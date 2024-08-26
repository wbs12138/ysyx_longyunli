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

#include "npc_difftest.h"

void (*difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*difftest_regcpy)(void *dut, bool direction) = NULL;
void (*difftest_exec)(uint64_t n) = NULL;


static bool is_skip_ref = false;

void difftest_skip_ref() {
  is_skip_ref = true;
}

void init_difftest(char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  difftest_memcpy = reinterpret_cast<void (*)(uint32_t, void*, size_t, bool)>\
  (dlsym(handle, "difftest_memcpy"));
  assert(difftest_memcpy);

  difftest_regcpy = reinterpret_cast<void (*)(void*, bool)>\
  (dlsym(handle, "difftest_regcpy"));
  assert(difftest_regcpy);

  difftest_exec = reinterpret_cast<void (*)(uint64_t)>\
  (dlsym(handle, "difftest_exec"));
  assert(difftest_exec);

  void (*difftest_init)(int) = reinterpret_cast<void (*)(int)>\
  (dlsym(handle, "difftest_init"));
  assert(difftest_init);

    printf("\033[1;34m[%s:%d]The difftest_so is %s\033[0m\r\n",__FILE__,__LINE__, ref_so_file);


//   Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
//   Log("The result of every instruction will be compared with %s. "
//       "This will help you a lot for debugging, but also significantly reduce the performance. "
//       "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  difftest_init(1);
  difftest_memcpy(RESET_VECTOR, guest_to_host_extern(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
}


void ref_reg_display(CPU_state *ref_r) {
  int reg_num = 32;
  printf("ref_isa as follows to compare and check\n");
for(int i=0;i<reg_num;i++){
	printf("%d:\t%x\n",i,ref_r->gpr[i]);
}
printf("%d:\t%x\n",33,ref_r->pc);
printf("   %s\t%x\n","mcause ",ref_r->csr.mcause);
printf("   %s\t%x\n","mepc   ",ref_r->csr.mepc);
printf("   %s\t%x\n","mstatus",ref_r->csr.mstatus);
printf("   %s\t%x\n","mtvec  ",ref_r->csr.mtvec);

printf("\n\n\n");

}

bool isa_difftest_checkregs(CPU_state *ref_r, uint32_t pc) {
  int reg_num = 32;
  int error=0;
  for (int i = 0; i < reg_num; i++) {
    if (ref_r->gpr[i] != read_cpu_state_gpr(i)) {
      printf("difftest matters\n");
      printf("difftest fail at %s[%d], expect %#x got %#x\n", "gpr" , i , ref_r->gpr[i], read_cpu_state_gpr(i)); 
      error=1;
    }
  }
  if (ref_r->pc != read_cpu_state_pc()) {
    printf("difftest fail at %s, expect %#x got %#x\n", "pc" , ref_r->pc, read_cpu_state_pc()); 
    error=1;
  }
  if (ref_r->csr.mtvec != read_cpu_state_mtvec()) {
    printf("difftest fail at %s, expect %#x got %#x\n", "mtvec" , ref_r->csr.mtvec, read_cpu_state_mtvec()); 
    error=1;
  }
  if (ref_r->csr.mepc != read_cpu_state_mepc()) {
    printf("difftest fail at %s, expect %#x got %#x\n", "mepc" , ref_r->csr.mepc, read_cpu_state_mepc()); 
    error=1;
  }
  if (ref_r->csr.mcause != read_cpu_state_mcause()) {
    printf("difftest fail at %s, expect %#x got %#x\n", "mcause" , ref_r->csr.mcause, read_cpu_state_mcause()); 
    error=1;
  }
  if (ref_r->csr.mstatus != read_cpu_state_mstatus()) {
    printf("difftest fail at %s, expect %#x got %#x\n", "mstatus" , ref_r->csr.mstatus, read_cpu_state_mstatus()); 
    error=1;
  }
  if(error==1)
  return false;
  else
  return true;
}

// #define CHECKDIFFPC(p) if (ref_r->p != cpu.p) { 
//   printf("difftest fail at " #p ", expect %#x got %#x\n", ref_r->p, cpu.p); 
//   error = 1; 
// }
// #define CHECKDIFF(p) if (ref_r->csr.p != cpu.csr.p) { 
//   printf("\033[1;31m difftest fail at " #p ", expect %#x got %#x\033[0m\n", ref_r->csr.p, cpu.csr.p); 
//   error = 1; 
// }
// #define CHECKDIFF_FMT(p, fmt, ...) if (ref_r->p != cpu.p) { 
//   printf("difftest fail at " fmt ", expect %#x got %#x\n", ## __VA_ARGS__, ref_r->p, cpu.p); 
//   error = 1; 
// }

// bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
//   int error = 0;
//   int reg_num = ARRLEN(cpu.gpr);
//   for (int i = 0; i < reg_num; i++) {
//     CHECKDIFF_FMT(gpr[i], "gpr[%d]", i);
//   }
//   CHECKDIFFPC(pc);
//   CHECKDIFF(mstatus);
//   CHECKDIFF(mcause);
//   CHECKDIFF(mepc);
//   CHECKDIFF(mtvec);
//   if(error == 1)
//   return false;
//   else
//   return true;
// }


int checkregs(CPU_state *ref, uint32_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    
    display_inst();
    
    display_memory();

    ref_reg_display(ref);

    isa_reg_display();

    return 1;
  }
  else

  return 0;
}

int difftest_step(uint32_t pc) {
  CPU_state ref_r;
  if (is_skip_ref) {
    CPU_state cpu;
    for (int i = 0; i < 32; i++)
    cpu.gpr[i]       =   read_cpu_state_gpr(i);
    cpu.pc           =   read_cpu_state_pc();  
    cpu.csr.mtvec    =   read_cpu_state_mtvec();
    cpu.csr.mepc     =   read_cpu_state_mepc();
    cpu.csr.mcause   =   read_cpu_state_mcause();
    cpu.csr.mstatus  =   read_cpu_state_mstatus();
    difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return 0;
  }
  difftest_exec(1);
  difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  return checkregs(&ref_r, pc);
}
