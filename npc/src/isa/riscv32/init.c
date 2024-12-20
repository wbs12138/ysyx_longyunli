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
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/memory/paddr.h>

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {
  // 0x00300093,  // addi r1 r0 0x03
  // 0x00508213,  // addi r4 r1 0x05
  // 0x00108293,  // addi r5 r1 0x01
  // 0x00128313,  // addi r6 r5 0x01
  //0xFFF0A103,  // load error for test
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  // 0xdeadbeef,  // some data
};

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = RESET_VECTOR;
  cpu.csr.mstatus=0x00001800;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  //printf("sizeofimag is %ld\n",sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}
