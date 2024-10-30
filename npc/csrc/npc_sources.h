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
#include "VysyxSoCFull.h"
#include "svdpi.h"
#include "VysyxSoCFull__Dpi.h"

#define MAX_SIM_TIME 20000000000
#define CONFIG_MBASE 0x20000000
#define CONFIG_MSIZE 0x8000000
#define CONFIG_PC_RESET_OFFSET 0x0
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#define PG_ALIGN __attribute((aligned(4096)))
#define uint32_t unsigned int
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))


// #define CONFIG_ITRACE 1
// #define CONFIG_MTRACE 1
// #define CONFIG_FTRACE 1
// #define CONFIG_DIFFTEST 1

//#define CONFIG_VGA 1

typedef struct {
  uint32_t mcause;
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mtvec;
} riscv32_CSRs;

typedef struct {
    uint32_t gpr[32];
    uint32_t pc;
    riscv32_CSRs csr;
    
} CPU_state;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };


#endif