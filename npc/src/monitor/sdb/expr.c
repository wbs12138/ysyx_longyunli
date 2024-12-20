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

#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/isa.h>
#include <regex.h>
#include <assert.h>
#include <string.h>

int min(int a, int b)
{
    return a<b?a:b;
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
  DIV       = 15 
//   NOT       = 16

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
    // {"\\!",                 NOT},

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



static Token tokens[65535] __attribute__((used)) = {};
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
{   for(int i=0;i<65535;i++)
    {tokens[i].type=0;
     strcpy(tokens[i].str,"0");}
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
                char *substr_start_reg = e + position + 1;
                int substr_len = pmatch.rm_eo;

        
                position += substr_len;

            
                if (rules[i].token_type == TK_NOTYPE) break;

                tokens[nr_token].type = rules[i].token_type;
        
                switch (rules[i].token_type) 
                {
                    case NUM:
                    case HEX:
                        strncpy(tokens[nr_token].str, substr_start, substr_len);
                        tokens[nr_token].str[substr_len]='\0';
                        break;
                    case REGISTER:{
                        strncpy(tokens[nr_token].str, substr_start_reg, substr_len - 1);
                        tokens[nr_token].str[2]='\0';
                        break; 
                    }
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


uint32_t char2int(char s[]);
void int2char(uint32_t x,char str[]);


int pre_process()
{
 
    int tokens_len = 0;

    for(int i = 0 ; i < 65535 ; i ++)
    {
	if(tokens[i].type == 0)
	    break;
	tokens_len ++;
    }
   
  
//*************************************register*****************************
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	    if(tokens[i].type == REGISTER )
	    {   
	        bool flag = true;

	        uint32_t tmp = isa_reg_str2val(tokens[i].str, &flag);
            

	        if(flag)
            {   
		        int2char(tmp, tokens[i].str);
                
	        }
            else
            {
		        printf("Transfrom error. \n");
		        assert(0);
	        }
	    }
    }
    
//*************************************hex*****************************
    for(int i = 0 ; i < tokens_len ; i ++)
    {
        if(tokens[i].type == HEX)
        {   
            int value = strtol(tokens[i].str, NULL, 16);
            
            int2char(value, tokens[i].str);
        }
    }
    
//*************************************fushu*****************************
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if(
    (tokens[i].type == SUB && i > 0 &&\
    (tokens[i-1].type != NUM && tokens[i-1].type != HEX &&tokens[i-1].type != REGISTER&&tokens[i-1].type != RPARE ) &&\
    (tokens[i+1].type == NUM || tokens[i+1].type == HEX ||tokens[i+1].type == REGISTER ))
		||
		(tokens[i].type == SUB && i == 0)
	  )
	{
	    
	    tokens[i].type = TK_NOTYPE;
	    
	    for(int j = 31 ; j >= 1 ; j --)
        {
		    tokens[i+1].str[j] = tokens[i+1].str[j-1];
	    }
	    tokens[i+1].str[0] = '-';
	    
	    for(int j = 0 ; j < tokens_len ; j ++)
        {
		    if(tokens[j].type == TK_NOTYPE)
		    {
		        for(int k = j +1 ; k < tokens_len ; k ++)
                {
			        tokens[k - 1] = tokens[k];
		        }
		        tokens_len -- ;
		    }
	    }
	}
    }


//*************************************jiezhizhen*****************************
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if(	(tokens[i].type == PLUS && i > 0
      && tokens[i-1].type != NUM && tokens[i-1].type != HEX 
      && tokens[i-1].type != REGISTER && tokens[i-1].type != RPARE 
		    && (tokens[i+1].type == NUM || tokens[i+1].type == HEX || tokens[i+1].type == REGISTER)
		    )
		||
            (tokens[i].type == PLUS && i == 0)
          )
		{
            tokens[i].type = TK_NOTYPE;
            uint32_t tmp = char2int(tokens[i+1].str);
            uint32_t value = *((uint32_t *)(long)tmp);
            int2char(value, tokens[i+1].str);	    
            // 
            for(int j = 0 ; j < tokens_len ; j ++){
                if(tokens[j].type == TK_NOTYPE){
                    for(int k = j +1 ; k < tokens_len ; k ++){
                    tokens[k - 1] = tokens[k];
                }
                    tokens_len -- ;
                }
            }
		}
    }
    return tokens_len;
}

uint32_t char2int(char s[])
{
    uint32_t res=0;
    for(int i=0;s[i]!='\0';i++)
    {
        res*=10;
        res+=s[i]-'0'; 
    }
    return res;

}

void int2char(uint32_t num,char ret[])
{
	ret[0] = '\0';
	char *p = ret;
	do
	{
		int temp = num % 10;
		*(p++) = temp + '0';		
//		*(p++) = num + 0x30;
		num /= 10;
	}while(num);
	
	
	int len = strlen(ret);
	int i = 0;
	for(i=0; i<len/2; i++)
	{
		char temp = ret[i];
		ret[i] = ret[(len - 1 - i)];
		ret[(len - 1 - i)] = temp; 
	}
	
	
}



uint32_t eval(int p, int q) 
{   

    if (p == q) 
    {    
        uint32_t resul = strtol(tokens[p].str,NULL,10);

        
        return resul ;
    
    }

    else if (check_parentheses(p, q) == true) 
    {    
        return eval(p + 1, q - 1);
    }

    else 
    {
        int lpare_num=0;

        int op = 65535;

        int op_pd=0;

        bool flag = false;

        bool flag_pd=false;
           
        for(int i = q ; i >= p ; i --)
        {   
            if(tokens[i].type == RPARE)
            {   lpare_num=0;
                
                while(tokens[i].type != LPARE||lpare_num!=1){
                    if(tokens[i].type==RPARE)
                        lpare_num++;
                    if(tokens[i].type==LPARE)
                        lpare_num--;
                    if(i==0)
                    break;;
                    i --;
                }
                
            }
            if(!flag && tokens[i].type == OR ){
                flag = true;
                op = min(op,i);
            }

            if(!flag && tokens[i].type == AND ){
				flag = true;
                op = min(op,i);
            }

            if(!flag && tokens[i].type == NOTEQ){
                flag = true;
                op = min(op,i);
            }

            if(!flag && tokens[i].type == EQ){
                flag = true;
                op = min(op,i);
            }
            if(!flag && tokens[i].type == LEQ){
                flag = true;
                op = min(op, i);
            }
            if(!flag && tokens[i].type == REQ){
                flag = true;
                op = min(op, i);
            }
            if(!flag && tokens[i].type == ADD){
                flag = true;
                op = min(op, i);
            }
            if(!flag && tokens[i].type == SUB){
                flag = true;
                op = min(op, i);
            }
            if(!flag && !flag_pd && tokens[i].type == PLUS){
                flag_pd=true;
                op_pd=i;
                op = min(op, i);
            }
            if(!flag && !flag_pd && tokens[i].type == DIV){
                flag_pd=true;
                op_pd=i;
                op = min(op, i);
            }
        
        }
        if(flag==false)op=op_pd;

        int  op_type = tokens[op].type;
        

        
        uint32_t  val1 = eval(p, op - 1);
        uint32_t  val2 = eval(op + 1, q);

        int32_t resu_tmp;
        int32_t val1_tmp;
        int32_t val2_tmp;

        switch (op_type) 
        {
            case ADD:
                return val1 + val2;
            case SUB:
                return val1 - val2;
            case PLUS:{
                val1_tmp=(int32_t)val1;
                val2_tmp=(int32_t)val2;
                resu_tmp=val1_tmp*val2_tmp;

                return (uint32_t)resu_tmp; }
            case DIV:
                if(val2 == 0){
                    printf("division can't zero;\n");
                    return 0;
                }

                val1_tmp=(int32_t)val1;
                val2_tmp=(int32_t)val2;
                resu_tmp=val1_tmp/val2_tmp;

                return (uint32_t)resu_tmp;
            case EQ:
                return val1 == val2;
            case NOTEQ:
                return val1 != val2;
            case OR:
                return val1 || val2;
            case AND:
                return val1 && val2;
            case LEQ:
                return val1 <= val2;
            case REQ:
                return val1 >= val2;
            default:
                printf("error by some pre-process");
                assert(0);
        }
    }
}







word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  int len;
  *success = true;
  len=pre_process();
  
  return eval(0, len-1);

}

