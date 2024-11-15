#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char _data_start [];

extern char _data_end [];

extern char _data_size [];

extern char _data_load_start [];

extern char _rodata_start [];

extern char _rodata_end [];

extern char _rodata_size [];

extern char _rodata_load_start [];

extern char _text_start [];

extern char _text_end [];

extern char _text_size [];

extern char _text_load_start [];

// extern char _data_extra_start [];

// extern char _data_extra_end [];

// extern char _data_extra_size [];

// extern char _data_extra_load_start [];

extern char _bootloader_start [];

extern char _bootloader_end [];

extern char _bootloader_size [];

extern char _bootloader_load_start [];

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

void putch(char ch) __attribute__((optimize("0")));

void putch(char ch) {
  int a=0;

  *(volatile char *)(SERIAL_PORT) = ch ;
  char status=0;
  while( status ==0 ) {
    status = *(volatile char *)(SERIAL_PORT + 5);
  }

  while(a!=1000000000) {
    a=a+1;
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


void __attribute__((section(".bootloader"))) _bootloader_init() {

  unsigned long  n;

  if(_text_start != _text_end) {
    unsigned char *dest = (unsigned char *)_text_start;
    const unsigned char *src = (unsigned char *)_text_load_start;
    n = (unsigned long)_text_size;

    while ( n != 0) {
      *dest = *src;
      --n;
      ++dest;
      ++src;
    }

  }

  if(_rodata_start != _rodata_end) {
    unsigned char *dest = (unsigned char *)_rodata_start;
    const unsigned char *src = (unsigned char *)_rodata_load_start;
    n = (unsigned long)_rodata_size;
    while ( n != 0) {
      *dest = *src;
      --n;
      ++dest;
      ++src;
    }
  }

  // if(_data_extra_start != _data_extra_end) {
  //   unsigned char *dest = (unsigned char *)_data_extra_start;
  //   const unsigned char *src = (unsigned char *)_data_extra_load_start;
  //   n = (unsigned long)_data_extra_size;
  //   if(n>4) {
  //     for (; n > 4; n -= 4, src += 4, dest += 4) {
  //       *(size_t *)dest = *(size_t *)src;
  //     }
  //   }

  //   for (; n>0; dest+=1, src+=1) {
  //     *dest = *src;
  //     --n;
  //   }
  // }

  if(_data_start != _data_end) {
    unsigned char *dest = (unsigned char *)_data_start;
    const unsigned char *src = (unsigned char *)_data_load_start;
    n = (unsigned long)_data_size;
    while ( n != 0) {
      *dest = *src;
      --n;
      ++dest;
      ++src;
    }
  }

  __asm__ volatile (
        "la a0, %0\n\t"
        "jalr a0\n\t"
        :: "i"(_trm_init)
  );
}


void __attribute__((section(".fsbl"))) _fsbl_init() {
  if(_bootloader_start != _bootloader_end) {
    unsigned char *dest = (unsigned char *)_bootloader_start;
    const unsigned char *src = (unsigned char *)_bootloader_load_start;
    unsigned long n = (unsigned long)_bootloader_size;
    while ( n != 0) {
      *dest = *src;
      --n;
      ++dest;
      ++src;
    }
  }

  __asm__ volatile (
        "la a0, %0\n\t"
        "jalr a0\n\t"
        :: "i"(_bootloader_init)
  );
}

