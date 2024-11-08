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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <assert.h>
#include <isa.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/nemu/src/utils/itrace.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/nemu/include/cpu/decode.h>

#ifdef CONFIG_TARGET_SHARE

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  #ifdef CONFIG_MTRACE
  trace_memory(addr,len,0xFFFFFFFF,0);
  #endif
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
  trace_memory(addr,len,data,1);
  #endif
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

#else//CONFIG_TARGET_SHARE


static uint8_t sram[0xffffff] PG_ALIGN = {};
static uint8_t mrom[0xfff] PG_ALIGN = {};
static uint8_t flash[0xfffffff] PG_ALIGN = {};
static uint8_t psram[0x1fffffff] PG_ALIGN = {};
static uint8_t sdram[0x1fffffff] PG_ALIGN = {};


uint8_t* guest_to_host(paddr_t paddr) {
  if(paddr>=0x0f000000 & paddr<=0x0fffffff) {
    return sram + paddr - 0x0f000000;
  }
  else if(paddr>=0x20000000 & paddr<=0x20000fff) {
    return mrom + paddr - 0x20000000;
  }
  else if(paddr>=0x30000000 & paddr<=0x3fffffff) {
    return flash + paddr - 0x30000000;
  }
  else if(paddr>=0x80000000 & paddr<=0x9fffffff) {
    return psram + paddr - 0x80000000;
  }
  else if(paddr>=0xa0000000 & paddr<=0xbfffffff) {
    return sdram + paddr - 0xa0000000;
  }
  else {
    printf("nemu_difftest guest_to_host error!\n");
    out_of_bound(paddr);
    assert(0);
  }
}

paddr_t host_to_guest(uint8_t *haddr) { return 0; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
  IFDEF(CONFIG_MEM_RANDOM, memset(sram, 0, 0xffffff));
  IFDEF(CONFIG_MEM_RANDOM, memset(mrom, rand(), 0xfff));
  IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), 0xfffffff));
  IFDEF(CONFIG_MEM_RANDOM, memset(psram, 0, 0x1fffffff));
  IFDEF(CONFIG_MEM_RANDOM, memset(sdram, 0, 0x1fffffff));

}

word_t paddr_read(paddr_t addr, int len) {
  return pmem_read(addr, len);
}

void paddr_write(paddr_t addr, int len, word_t data) {
  pmem_write(addr, len, data); return; 

}

#endif//CONFIG_TARGET_SHARE
