/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <assert.h>
enum {
  TK_NOTYPE = 256, TK_EQ,
  TK_NUM, // 10 & 16
  TK_REG,
  TK_VAR,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"==", TK_EQ},        // equal
  {"\\(", '('},
  {"\\)", ')'},

  {"[0-9]+", TK_NUM}, // TODO: non-capture notation (?:pattern) makes compilation failed
  {"\\$\\w+", TK_REG},
  {"[A-Za-z_]\\w*", TK_VAR},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    assert(!ret);
  }
}

//void init_regex() {
//  int i;
//  char error_msg[128];
//  int ret;

//  for (i = 0; i < NR_REGEX; i ++) {
//    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
//    if (ret != 0) {
//      regerror(ret, &re[i], error_msg, 128);
//      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
//    }
//  }
//}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;


int find_major(int p, int q) {
  int ret = -1, par = 0, op_type = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == TK_NUM) {
      continue;
    }
    if (tokens[i].type == '(') {
      par++;
    } else if (tokens[i].type == ')') {
      if (par == 0) {
        return -1;
      }
      par--;
    } else if (par > 0) {
      continue;
    } else {
      int tmp_type = 0;
      switch (tokens[i].type) {
      case '*': case '/': tmp_type = 1; break;
      case '+': case '-': tmp_type = 2; break;
      default: assert(0);
      }
      if (tmp_type >= op_type) {
        op_type = tmp_type;
        ret = i;
      }
    }
  }
  if (par != 0) return -1;
  return ret;
}


bool check_parentheses(int p, int q) {
    printf("p:%d,q:%d\n",p,q);
    printf("the left char %c,the right char%c\n",tokens[p].type,tokens[q].type);
  if (tokens[p].type=='(' && tokens[q].type==')') {
    int par = 0;
    for (int i = p; i <= q; i++) {
      if (tokens[i].type=='(') par++;
      else if (tokens[i].type==')') par--;

      if (par == 0) return i==q; // the leftest parenthese is matched
    }
  }
  return false;
}


static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      int reg_res = regexec(&re[i], e + position, 1, &pmatch, 0);
      if (reg_res == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        if (rules[i].token_type == TK_NOTYPE) break;

        tokens[nr_token].type = rules[i].token_type;
        switch (rules[i].token_type) {
          case TK_NUM:
          case TK_REG:
          case TK_VAR:
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            // todo: handle overflow (token exceeding size of 32B)
        }
        nr_token++;

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}




word_t eval(int p, int q, bool *ok) {
  *ok = true;
  if (p > q) {
    *ok = false;
    return 0;
  } else if (p == q) {
    if (tokens[p].type != TK_NUM) {
      *ok = false;
      return 0;
    }
    word_t ret = strtol(tokens[p].str, NULL, 10);
    return ret;
  } else if (check_parentheses(p, q)) {
    return eval(p+1, q-1, ok);
  } else {    
    int major = find_major(p, q);
    if (major < 0) {
      *ok = false;
      return 0;
    }

    word_t val1 = eval(p, major-1, ok);
    if (!*ok) return 0;
    word_t val2 = eval(major+1, q, ok);
    if (!*ok) return 0;

    switch(tokens[major].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': if (val2 == 0) {
        *ok = false;
        return 0;
      } 
      return (sword_t)val1 / (sword_t)val2; // e.g. -1/2, may not pass the expr test
      default: assert(0);
    }
  }
}



word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  return eval(0, nr_token-1, success);
}

