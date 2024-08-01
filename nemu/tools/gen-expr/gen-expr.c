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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";



static char *buf_start = NULL;
static char *buf_end = buf+(sizeof(buf)/sizeof(buf[0]));

static int choose(int n) 
{

  return rand() % n;

}



static void gen_space() {

  int size = choose(4);

  if (buf_start < buf_end) {
    int n_writes = snprintf(buf_start, buf_end-buf_start, "%*s", size, "");
    if (n_writes > 0) {
      buf_start += n_writes;
    }
  }
}

static void gen_num() {

  int num = choose(INT8_MAX);

  if (buf_start < buf_end) {
    int n_writes = snprintf(buf_start, buf_end-buf_start, "%d", num);
    if (n_writes > 0) {
      buf_start += n_writes;
    }
  }
  gen_space();
}

static void gen_char(char c) {
  int n_writes = snprintf(buf_start, buf_end-buf_start, "%c", c);
  if (buf_start < buf_end) 
  {
    if (n_writes > 0) 
    {
      buf_start += n_writes;
    }
  }

}

static char ops[] = {'+', '-', '*', '/'};

static void gen_rand_op() 
{
  int op_index = choose(sizeof(ops));
  char op = ops[op_index];
  gen_char(op);
}

static void gen_rand_expr() {
  switch (choose(3))
  {

  case 0: gen_num(); break;
  case 1: gen_char('('); gen_rand_expr(); gen_char(')'); break;
  default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;

  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf_start = buf;

    gen_rand_expr();


    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Wall -Werror -o /tmp/.expr");
    // filter div-by-zero expressions
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint64_t result;
    int _ = fscanf(fp, "%lu", &result);
    _ = _;
    pclose(fp);

    printf("%lu %s\n", result, buf);
  }
  return 0;
}
