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

void init_difftest(char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  difftest_memcpy = dlsym(handle, "difftest_memcpy");
  assert(difftest_memcpy);

  difftest_regcpy = dlsym(handle, "difftest_regcpy");
  assert(difftest_regcpy);

  difftest_exec = dlsym(handle, "difftest_exec");
  assert(difftest_exec);

  void (*difftest_init)(int) = dlsym(handle, "difftest_init");
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

printf("\n\n\n");

}

bool isa_difftest_checkregs(CPU_state *ref_r, uint32_t pc) {
  int reg_num = 32;
  for (int i = 0; i < reg_num; i++) {
    if (ref_r->gpr[i] != npc_cpu_state.gpr[i]) {
      printf("difftest matters\n");
      return false;
    }
  }
  if (ref_r->pc != npc_cpu_state.pc) {
    return false;
  }
  return true;
}

int checkregs(CPU_state *ref, uint32_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    
    //display_memory();

    display_inst();

    ref_reg_display(ref);

    isa_reg_display();

    return 1;
  }
  else

  return 0;
}

int difftest_step(uint32_t pc) {
  CPU_state ref_r;

  difftest_exec(1);
  difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  return checkregs(&ref_r, pc);
}
