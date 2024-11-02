#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char data_start [];

extern char data_size [];

extern char data_load_start [];

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (0x1fff)
#define PMEM_END  ((uintptr_t)&_heap_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

#define DEVICE_BASE     0x10000000
#define SERIAL_PORT     (DEVICE_BASE + 0x0)

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }

void putch(char ch) {
  outb(SERIAL_PORT, ch);
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

  int ret = main(mainargs);
  halt(ret);
}
