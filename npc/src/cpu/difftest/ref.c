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
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/cpu.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/decode.h>
#include <difftest-def.h>
#include <memory/paddr.h>



__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_DUT)
    memcpy(buf,guest_to_host(addr),n);
  else
    memcpy(guest_to_host(addr),buf,n);
  
  return ;
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if(direction == DIFFTEST_TO_DUT)
    memcpy(dut,&cpu,sizeof(CPU_state));
  
  else
    memcpy(&cpu,dut,sizeof(CPU_state));

  return ;
}

static void exec_once_diff(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
  return;
}

__EXPORT void difftest_exec(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once_diff(&s, cpu.pc);
  }
  return;
}




__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
