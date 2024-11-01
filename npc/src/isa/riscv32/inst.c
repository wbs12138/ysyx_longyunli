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

#include "local-include/reg.h"
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/cpu.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/ifetch.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/decode.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/src/utils/itrace.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/memory/paddr.h>

#define R(i) gpr(i)

extern "C" void flash_read(int32_t addr, int32_t *data) {assert(0);}
extern "C" void mrom_read(int32_t addr,int32_t *data) {
  *data = paddr_read(addr,4);
}


int state_exeu,state_ifuar,state_ifur,insn,npc_pc;

int state_lsuar,state_lsuaw;

int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31;

int npc_mcause,npc_mtvec,npc_mepc,npc_mstatus;

int ftrace1,ftrace2,ftrace3,ftrace4;

int npc_ecall,npc_mret;

int aw_addr,aw_len,aw_data;

int ar_addr,ar_len;

int npc_ebreak;

int isa_exec_once(Decode *s) {

  while(state_exeu==0){
  	dut->eval();
    sim_time+=4;
    m_trace->dump(sim_time);
    dut->clock=0;
    dut->eval();
    sim_time+=4;
    dut->eval();
    m_trace->dump(sim_time);
    dut->clock=1;
    dut->eval();
  }


  s->isa.inst.val = insn;

  #ifdef CONFIG_ITRACE
    trace_inst(s->pc, s->isa.inst.val);
  #endif

  s->dnpc = s->snpc;

  s->dnpc = npc_pc;

  #ifdef CONFIG_ITRACE
  if(ftrace1) {
    trace_func_call(s->pc, s->dnpc, false);
  }

  if(ftrace2) {
    trace_func_ret(s->pc); 
  }

  if(ftrace3) {
    trace_func_call(s->pc, s->dnpc, false);
  }

  if(ftrace4) {
    trace_func_call(s->pc, s->dnpc, true);
  }
  #endif


  while(state_ifuar==0){

    if(state_lsuaw==1) {

      #ifdef CONFIG_MTRACE
        trace_memory(aw_addr,aw_len,aw_data,1);
      #endif
    }

    if(state_lsuar==1) {
      
      #ifdef CONFIG_MTRACE
        trace_memory(ar_addr,ar_len,0x0,0);
      #endif
    }

  	dut->eval();
    sim_time+=4;
    m_trace->dump(sim_time);
    dut->clock=0;
    dut->eval();
    sim_time+=4;
    dut->eval();
    m_trace->dump(sim_time);
    dut->clock=1;
    dut->eval();
  }

  R(0 ) = x0  ;
  R(1 ) = x1  ;
  R(2 ) = x2  ;
  R(3 ) = x3  ;
  R(4 ) = x4  ;
  R(5 ) = x5  ;
  R(6 ) = x6  ;
  R(7 ) = x7  ;
  R(8 ) = x8  ;
  R(9 ) = x9  ;
  R(10) = x10 ;
  R(11) = x11 ;
  R(12) = x12 ;
  R(13) = x13 ;
  R(14) = x14 ;
  R(15) = x15 ;
  R(16) = x16 ;
  R(17) = x17 ;
  R(18) = x18 ;
  R(19) = x19 ;
  R(20) = x20 ;
  R(21) = x21 ;
  R(22) = x22 ;
  R(23) = x23 ;
  R(24) = x24 ;
  R(25) = x25 ;
  R(26) = x26 ;
  R(27) = x27 ;
  R(28) = x28 ;
  R(29) = x29 ;
  R(30) = x30 ;
  R(31) = x31 ;

  if(npc_ebreak) {

    NEMUTRAP(s->pc, R(10));
  }

  cpu.csr.mepc = npc_mepc ;
  cpu.csr.mcause = npc_mcause ;
  cpu.csr.mstatus = npc_mstatus ;
  cpu.csr.mtvec = npc_mtvec ;

  #ifdef CONFIG_ITRACE
    bool success;
    if(npc_ecall) {
      trace_e_in(isa_reg_str2val("a7", &success), s->pc); 
    }
  #endif

  #ifdef CONFIG_ITRACE 
    if(npc_mret) {
      trace_e_out(s->dnpc, cpu.csr.mstatus); 
    }
  #endif

  return 0;
}


void cpu_ecall( int ecall,  int mret) {
  npc_ecall = ecall;
  npc_mret = mret;
};


void ftrace_update(int dnpc_v,int trace1,int trace2,int trace3,int trace4) {
  ftrace1 = trace1;
  ftrace2 = trace2;
  ftrace3 = trace3;
  ftrace4 = trace4;
};


void state_is_exeu(int npc_state) {
  state_exeu = npc_state;
};

void state_is_ifuar(int npc_state) {
  state_ifuar = npc_state;
};

void state_is_ifur(int npc_state) {
  state_ifur = npc_state;
};

void get_inst(int inst) {
  insn = inst;
};

void get_pc(int dnpc) {
  npc_pc = dnpc;
};

void get_csr(int mepc,int mcause,int mtvec,int mstatus) {
  npc_mepc = mepc;
  npc_mcause = mcause;
  npc_mstatus = mstatus;
  npc_mtvec = mtvec;
};


void memory_access(int npc_state_lsuaw, int npc_state_lsuar,int npc_aw_addr,int npc_aw_len,int npc_aw_data,int npc_ar_addr,int npc_ar_len) {
  state_lsuaw = npc_state_lsuaw;
  state_lsuar = npc_state_lsuar;
  aw_addr = npc_aw_addr;
  aw_len = npc_aw_len;
  aw_data = npc_aw_data;
  ar_addr = npc_ar_addr;
  ar_len = npc_ar_len;
}

void regfile_update( int rf1, int rf2, int rf3, int rf4, int rf5, int rf6, int rf7, int rf8, int rf9, int rf10, int rf11, int rf12, int rf13, int rf14, int rf15, int rf16, int rf17, int rf18, int rf19, int rf20, int rf21, int rf22, int rf23, int rf24, int rf25, int rf26, int rf27, int rf28, int rf29, int rf30 , int rf31) {
  x0 = 0    ;
  x1 = rf1  ;
  x2 = rf2  ;
  x3 = rf3  ;
  x4 = rf4  ;
  x5 = rf5  ;
  x6 = rf6  ;
  x7 = rf7  ;
  x8 = rf8  ;
  x9 = rf9  ;
  x10= rf10 ;
  x11= rf11 ;
  x12= rf12 ;
  x13= rf13 ;
  x14= rf14 ;
  x15= rf15 ;
  x16= rf16 ;
  x17= rf17 ;
  x18= rf18 ;
  x19= rf19 ;
  x20= rf20 ;
  x21= rf21 ;
  x22= rf22 ;
  x23= rf23 ;
  x24= rf24 ;
  x25= rf25 ;
  x26= rf26 ;
  x27= rf27 ;
  x28= rf28 ;
  x29= rf29 ;
  x30= rf30 ;
  x31= rf31 ;
  
};

void ebreak(int back_right) {
  npc_ebreak = 1;
};
