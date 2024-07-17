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
#include <regex.h>
#include <assert.h>
#include <string.h>

int max(int a, int b)
{
    return a>b?a:b;
}



enum {
  TK_NOTYPE = 256, 
  NUM       = 1  ,
  HEX       = 2  ,
  EQ        = 3  ,
  NOTEQ     = 4  ,
  OR        = 5  ,
  AND       = 6  ,
  LEQ       = 7  ,
  REQ       = 8  ,
  REGISTER  = 9  ,
  LPARE     = 10 ,
  RPARE     = 11 ,
  ADD       = 12 ,
  SUB       = 13 ,
  PLUS      = 14 ,
  DIV       = 15 ,
  NOT       = 16

};




static struct rule {
    const char *regex;
    int token_type;
}   rules[] = {


    {" +",                  TK_NOTYPE},    
    {"\\+",                 ADD},         
    {"\\-",                 SUB},       
    {"\\*",                 PLUS},      
    {"\\/",                 DIV},         

    {"\\(",                 LPARE},
    {"\\)",                 RPARE},
    
    {"\\<\\=",              LEQ},            
    {"\\>\\=",              REQ},
    {"\\=\\=",              EQ},        
    {"\\!\\=",              NOTEQ},

    {"\\&\\&",              AND},
    {"\\|\\|",              OR},       
    {"\\!",                 NOT},

    {"\\$[a-zA-Z]*[0-9]*",  REGISTER},

    {"0[xX][0-9a-fA-F]+",   HEX},
    {"[0-9]*",              NUM},
};




#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};




void init_regex() {
  int i;
  int compile_resu;

  for (i = 0; i < NR_REGEX; i ++) {
    compile_resu = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    assert(!compile_resu);

  }
}





typedef struct token {
  int type;
  char str[32];
} Token;



static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;







bool check_parentheses(int p, int q) 
{

    if (tokens[p].type== LPARE && tokens[q].type== RPARE ) 
    {
        int par = 0;
        for (int i = p; i <= q; i++) 
        {
            if (tokens[i].type== LPARE ) par++;
            else if (tokens[i].type== RPARE ) par--;

            if (par == 0)
            {
                if (i==q)
                    return true;
                else
                    return false;
            }    
                
        }
    }
    
    return false;
}






static bool make_token(char *e) 
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;
    
    while (e[position] != '\0') 
    {
    
        for (i = 0; i < NR_REGEX; i ++) 
        {
            
            int reg_res = regexec(&re[i], e + position, 1, &pmatch, 0);
            
            
            if (reg_res == 0 && pmatch.rm_so == 0) 
            {
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

        
                position += substr_len;

            
                if (rules[i].token_type == TK_NOTYPE) break;

                tokens[nr_token].type = rules[i].token_type;
        
                switch (rules[i].token_type) 
                {
                    case NUM:
                    case REGISTER:
                    case HEX:
                        strncpy(tokens[nr_token].str, substr_start, substr_len);break;
                    
                    case EQ:
                        strcpy(tokens[nr_token].str, "==");break;

                    case NOTEQ:
                        strcpy(tokens[nr_token].str, "!=");break;

                    case AND:
                        strcpy(tokens[nr_token].str, "&&");break;

                    case OR:
                        strcpy(tokens[nr_token].str, "||");break;

                    case LEQ:
                        strcpy(tokens[nr_token].str, "<=");break;
                        
                    case REQ:
                        strcpy(tokens[nr_token].str, ">=");break;

                    default:
                        break;
            
                }

                nr_token++;

                break;
            }
        }

        if (i == NR_REGEX) 
        {
            printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
            return false;
        }
    }

    return true;
}





uint32_t eval(int p, int q) 
{
    if (p == q) 
    {
        word_t resul = strtol(tokens[p].str,NULL,10);
        return resul ;
    
    }

    else if (check_parentheses(p, q) == true) 
    {    
        return eval(p + 1, q - 1);
    }

    else 
    {
        int op = -1;

        bool flag = false;

        for(int i = p ; i <= q ; i ++)
        {
            if(tokens[i].type == LPARE)
            {
                while(tokens[i].type != RPARE)
                    i ++;
            }
            if(!flag && tokens[i].type == OR ){
                flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == ADD ){
				flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == NOTEQ){
                flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == EQ){
                flag = true;
                op = max(op,i);
            }
            if(!flag && tokens[i].type == LEQ){
                flag = true;
                op = max(op, i);
            }
            if(!flag && tokens[i].type == REQ){
                flag = true;
                op = max(op, i);
            }
            if(!flag && tokens[i].type == ADD){
                flag = true;
                op = max(op, i);
            }
            if(!flag && tokens[i].type == SUB){
                flag = true;
                op = max(op, i);
            }
            if(!flag && tokens[i].type == PLUS){
                op = max(op, i);
            }
            if(!flag && tokens[i].type == DIV){
                op = max(op, i);
            }
        }
        
        int  op_type = tokens[op].type;

        
        uint32_t  val1 = eval(p, op - 1);
        uint32_t  val2 = eval(op + 1, q);

        switch (op_type) {
            case ADD:
                return val1 + val2;
            case SUB:
                return val1 - val2;
            case PLUS:
                return val1 * val2;
            case DIV:
                if(val2 == 0){
                    printf("division can't zero;\n");
                    return 0;
                }
                return val1 / val2;
            case EQ:
                return val1 == val2;
            case NOTEQ:
                return val1 != val2;
            case OR:
                return val1 || val2;
            case AND:
                return val1 && val2;
            default:
                printf("No Op type.");
                assert(0);
        }
    }
}







word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  return eval(0, nr_token-1);
}

