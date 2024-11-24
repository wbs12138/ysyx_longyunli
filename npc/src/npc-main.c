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

#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/common.h>

#include </home/wangbaosen/ysyx/ysyx-workbench/npc/include/cpu/cpu.h>

#include </home/wangbaosen/ysyx/ysyx-workbench/nvboard/usr/include/nvboard.h>

#define TOP_NAME VysyxSoCFull

void nvboard_bind_all_pins(TOP_NAME* top);


void init_monitor(int, char *[]);
void sdb_mainloop();
int is_exit_status_bad();

vluint64_t sim_time=0;

VysyxSoCFull *dut = new VysyxSoCFull;

VerilatedVcdC *m_trace = new VerilatedVcdC;

void init_verilator(int argc, char *argv[]) {

  Verilated::commandArgs(argc,argv);  

  Verilated::traceEverOn(true);

  VysyxSoCFull dut_nvboard &&dut;

  nvboard_bind_all_pins(dut_nvboard);
  
  nvboard_init();
	
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");

	int reset_clk_time=20;
	dut->reset=1;
	sim_time++;
	m_trace->dump(sim_time);
    
	while(reset_clk_time-->0){
		dut->clock = 0;
        //dut->ist=0;
    dut->eval();
    sim_time+=4;
		m_trace->dump(sim_time);
		
		dut->clock = 1;
    dut->eval();
    sim_time+=4;
		m_trace->dump(sim_time);

    nvboard_update();
		
	}
	dut->reset=0;
  dut->eval();
  sim_time+=4;
  dut->eval();
	m_trace->dump(sim_time);

  nvboard_update();


}


int main(int argc, char *argv[]) {
  /* Initialize the monitor. */

  int i=1;
  do{
    printf("argc[%d]=%s\n",i,argv[i-1]);
    i+=1;
  }while(i!=argc+1);

  init_monitor(argc, argv);



  init_verilator(argc, argv);


  /* Start engine. */
  sdb_mainloop();

  return is_exit_status_bad();
}
