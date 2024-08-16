#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


static void reverse(char *s, int len) {
  int time=len/2;
  int cur_time=0;
  char *end = s + len - 1;
  char tmp;
  while (cur_time < time) {
    tmp = *s;
    *s = *end;
    *end = tmp;
    s++;
    end--;
    cur_time++;
  }
}

/* itoa convert int to string under base. return string length */
static int itoa(int n, char *s, int base) {
  assert(base <= 16);
  if(n!=-2147483648 && n!=0){
  int i = 0, sign = n, bit;
  if (sign < 0) n = -n;
  while (n > 0 ){
    bit = n % base;
    if (bit >= 10) s[i++] = 'a' + bit - 10;
    else s[i++] = '0' + bit;
    n=n/base;
    
  } 

  if (sign < 0) s[i++] = '-';
  s[i] = '\0';

  reverse(s, i);

  return i;}
  else if(n==0)
  {strcpy(s, "0");
  return 1;}
  else{strcpy(s, "-2147483648");
  return 11;}
}


int sprintf(char *out, const char *fmt, ...) {
  va_list pArgs;
  va_start(pArgs, fmt);
  char *start = out;

  for (; *fmt != '\0'; ++fmt) {
    
    if (*fmt != '%') {
      *out = *fmt;
      ++out;
    } else {
      switch (*(++fmt)) {
      case '%': *out = *fmt; ++out; break;
      case 'd': out += itoa(va_arg(pArgs, int), out, 10); break;
      case 's':
        char *s = va_arg(pArgs, char*);
        strcpy(out, s);
        out += strlen(out);
        break;
      }
      
    }
    
  }
  *out = '\0';
  va_end(pArgs);

  return out - start;
}


int printf(const char *fmt, ...) {
  char info[1024];
  for(int i=0;i<1024;i++)
  {
    info[i]='\0';
  }
  char *buffer = info;

  va_list pArgs;
  va_start(pArgs, fmt);
  char *start = buffer;

  for (; *fmt != '\0'; ++fmt) {
    if (*fmt == '\\'){
      putch('\033');
      
      fmt+=4;
    }
    else if (*fmt != '%') {putch('0');
      *buffer = *fmt;
      ++buffer;
    } else {
      switch (*(++fmt)) {
      case '%': *buffer = *fmt; ++buffer; break;
      case 'd': buffer += itoa(va_arg(pArgs, int), buffer, 10); break;
      case 's':
        char *s = va_arg(pArgs, char*);
        strcpy(buffer, s);
        buffer += strlen(buffer);
        break;
      }
      
    }
    
  }
  *buffer = '\0';
  va_end(pArgs);

    
    // 逐个字符输出
    do{
      putch(*start);
      start++;
    }while(*start!='\0');

    return 0;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}


int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
