#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

#define MAX_SIM_TIME 6
vluint64_t sim_time=0;



static const uint32_t img [] = {
  0b000000000011_00000_000_00001_0010011,  // addi r1 r0 0x03
  0b000000000101_00001_000_00100_0010011,  // addi r4 r1 0x05
  0b000000000001_00001_000_00101_0010011,  // addi r5 r1 0x01
  0b000000000001_00101_000_00110_0010011,  // addi r6 r5 0x01
};

uint32_t *iram_start = 0x80000000;

void init_iram() {
	
  memcpy(iram_start, img, sizeof(img));

  return ;
}


static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);return 0;
  }
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




