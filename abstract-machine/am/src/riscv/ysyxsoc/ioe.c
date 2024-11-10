#include <am.h>
#include <klib-macros.h>

void __am_timer_init();
void __am_gpu_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);

static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

typedef void (*handler_t)(void *buf);

bool ioe_init() {

  return true;
}

void ioe_read (int reg, void *buf) { ; }
void ioe_write(int reg, void *buf) { ; }



#define FB_ADDR 0xa1000000

#define SYNC_ADDR 0xa0000100 + 4
#define VGACTL_ADDR 0xa0000100

void __am_gpu_init() {
  ;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
;
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  ;
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  ;
}

