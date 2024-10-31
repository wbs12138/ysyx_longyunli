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


void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

void init_verilator(int argc, char *argv[]) {

  Verilated::commandArgs(argc,argv);  

  Verilated::traceEverOn(true);
	
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");

	int reset_clk_time=2;
	dut->reset=1;
	sim_time++;
	m_trace->dump(sim_time);
    
	while(reset_clk_time-->0){
		dut->clock = 0;
        //dut->ist=0;
        dut->eval();sim_time++;
		m_trace->dump(sim_time);
		
		dut->clock = 1;dut->eval();sim_time++;
		m_trace->dump(sim_time);
		
	}
	dut->reset=0;
    dut->eval();
    //dut->ist = pmem_read(dut->pc,4);	
    
	dut->eval();
    //pc_pre=dut->pc;
    //update_state();
    sim_time+=1;
	m_trace->dump(sim_time);


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
  engine_start();

  return is_exit_status_bad();
}
