#ifndef NPC_SOURCES_H
#define NPC_SOURCES_H


#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"

#define MAX_SIM_TIME 20000000
#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x8000000
#define CONFIG_PC_RESET_OFFSET 0x0
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#define PG_ALIGN __attribute((aligned(4096)))
#define uint32_t unsigned int
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
// #define CONFIG_ITRACE 0
// #define CONFIG_MTRACE 0
// #define CONFIG_FTRACE 0
// #define CONFIG_DIFFTEST 0



typedef struct {
    uint32_t gpr[32];
    uint32_t pc;
    
} CPU_state;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };


#endif