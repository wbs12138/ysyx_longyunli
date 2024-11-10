#include <am.h>
#define DEVICE_BASE 0xa0000000
#define NPC_RTC_ADDR        (DEVICE_BASE + 0x0000048)
void __am_timer_init() {
}
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t high=inl(NPC_RTC_ADDR+4);
  uint32_t low=inl(NPC_RTC_ADDR);
  uptime->us = (uint64_t)low+(((uint64_t)high)<<32) ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
