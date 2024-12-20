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

#include <dlfcn.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/isa.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/difftest.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/cpu.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/memory/paddr.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/utils.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/src/utils/itrace.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/src/isa/riscv32/local-include/reg.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NEMU
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

static uint8_t value = 0;
static uint8_t *psram = &value;

uint8_t* guest_to_host_psram() { return psram; }



void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}


const char *ref_regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};



void ref_reg_display(CPU_state *ref_r) {
  int reg_num = ARRLEN(cpu.gpr);
  printf("\n\n\n");
  printf("ref_reg as follows to compare and check\n");
for(int i=0;i<reg_num;i++){
  printf("%d:%s\t%x\n",i,ref_regs[i],ref_r->gpr[i]);
}
printf("%d:%s\t%x\n",33,"pc",ref_r->pc);
printf("   %s\t%x\n","mcause ",ref_r->csr.mcause);
printf("   %s\t%x\n","mepc   ",ref_r->csr.mepc);
printf("   %s\t%x\n","mstatus",ref_r->csr.mstatus);
printf("   %s\t%x\n","mtvec  ",ref_r->csr.mtvec);

printf("\n\n\n");

}

#define CHECKDIFFPC(p) if (ref_r->p != cpu.p) { \
  printf("difftest fail at " #p ", expect %#x got %#x\n", ref_r->p, cpu.p); \
  error = 1; \
}
#define CHECKDIFF(p) if (ref_r->csr.p != cpu.csr.p) { \
  printf("\033[1;31m difftest fail at " #p ", expect %#x got %#x\033[0m\n", ref_r->csr.p, cpu.csr.p); \
  error = 1; \
}
#define CHECKDIFF_FMT(p, fmt, ...) if (ref_r->p != cpu.p) { \
  printf("difftest fail at " fmt ", expect %#x got %#x\n", ## __VA_ARGS__, ref_r->p, cpu.p); \
  error = 1; \
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int error = 0;
  int reg_num = ARRLEN(cpu.gpr);
  for (int i = 0; i < reg_num; i++) {
    CHECKDIFF_FMT(gpr[i], "gpr[%d]", i);
  }
  CHECKDIFFPC(pc);
  CHECKDIFF(mstatus);
  CHECKDIFF(mcause);
  CHECKDIFF(mepc);
  CHECKDIFF(mtvec);
  if(error == 1)
  return false;
  else
  return true;
}



void isa_difftest_attach() {
}


static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    nemu_state.state = NEMU_ABORT;
    nemu_state.halt_pc = pc;
    
    display_memory();

    display_inst();

    ref_reg_display(ref);

    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;

  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }
  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }

    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

    checkregs(&ref_r, pc);

}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
