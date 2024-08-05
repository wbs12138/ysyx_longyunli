#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

#define MAX_SIM_TIME 6

vluint64_t sim_time=0;

static const uint32_t img [] = {
//   0b000000000011_00000_000_00001_0010011,  // addi r1 r0 0x03
//   0b000000000101_00001_000_00100_0010011,  // addi r4 r1 0x05
//   0b000000000001_00001_000_00101_0010011,  // addi r5 r1 0x01
//   0b000000000001_00101_000_00110_0010011,  // addi r6 r5 0x01
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
};


uint32_t *iram = NULL ;


void init_iram() {

  iram = (uint32_t *)malloc(sizeof(uint32_t)*100);
	
  memcpy(iram, img, sizeof(img));
  
  return ;
}



static uint32_t pmem_read(uint32_t addr) {
  uint32_t idx = (addr - 0x80000000)/4 ;
  uint32_t ret = iram[idx];
  return ret;
}






int main(int argc,char** argv,char** env){
	Vtop *dut = new Vtop;
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");


	int n=2;
	dut->reset=1;
	while(n-->0){
		dut->clk = 0;dut->eval();
		dut->clk = 1;dut->eval();

	}
	dut->reset=0;


	int a,b;
	while(sim_time<MAX_SIM_TIME){

		dut->clk^=1;

		printf("clk=%d\n,pc=%u\n,ist=%d\n",dut->clk,dut->pc,dut->ist);

		dut->ist = pmem_read(dut->pc);
		
		dut->eval();

		m_trace->dump(sim_time);

		sim_time++;
	}

	m_trace->close();

	delete dut;

	exit(EXIT_SUCCESS);
	
	return 0;
}




