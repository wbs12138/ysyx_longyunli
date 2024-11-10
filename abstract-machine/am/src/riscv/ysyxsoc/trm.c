#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char data_start [];

extern char data_size [];

extern char data_load_start [];

extern char rodata_start [];

extern char rodata_size [];

extern char rodata_load_start [];

extern char text_start [];

extern char text_size [];

extern char text_load_start [];

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
extern char _heap_end;
#define PMEM_END  (uintptr_t)&_heap_end

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

#define DEVICE_BASE     0x10000000
#define SERIAL_PORT     (DEVICE_BASE + 0x0)

bool ioe_init() {
  return true;
}

void ioe_read (int reg, void *buf) { ; }

void putch(char ch) {

  *(volatile char *)(SERIAL_PORT) = ch ;
  char status=0;
  while( status ==0 ) {
    status = *(volatile char *)(SERIAL_PORT + 5);
  }
  
}

void init_uart() {
  *(volatile char *)(SERIAL_PORT + 3) = 0x83 ;
  *(volatile char *)(SERIAL_PORT + 1) = 0x0 ;
  *(volatile char *)(SERIAL_PORT + 0) = 0x2 ;
  *(volatile char *)(SERIAL_PORT + 3) = 0x3  ;
}

void halt(int code) {
  npc_trap(code);

  // should not reach here
  while (1);
}



void _trm_init() {


  if (data_start != data_load_start){
    memcpy(data_start, data_load_start, (size_t)data_size );
  }

  init_uart();

  unsigned int ysyx;
  unsigned int ysyx_number;

  asm volatile("csrr %[dest], mvendorid" : [dest]"=r" (ysyx));
  asm volatile("csrr %0, marchid" : "=r" (ysyx_number));

  printf("ysyx, whose ascii is %x,welcome!\n",ysyx);
  printf("wangbaosen, whose number is %x,welcome!\n",ysyx_number);

  int ret = main(mainargs);
  halt(ret);
}
