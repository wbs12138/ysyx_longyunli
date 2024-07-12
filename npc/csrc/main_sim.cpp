#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

#define MAX_SIM_TIME 200
vluint64_t sim_time=0;
int main(int argc,char** argv,char** env){
	Vtop *dut = new Vtop;
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");

	void single_cycle() {
  		top->clk = 0; top->eval();
  		top->clk = 1; top->eval();
	}

	void reset(int n) {
  		top->rst = 1;
  		while (n -- > 0) single_cycle();
  		top->rst = 0;
	}

	reset(10);


	int a,b;
	while(sim_time<MAX_SIM_TIME){
		dut->clk^=1;
		if(dut->clk==0){
		a=rand();
		b=rand();
		dut->a=a;
		dut->b=b;
		}

		dut->eval();

		if(dut->clk==1 && a&b==1){
			printf("sim_time = %ld,a = %d,b = %d,led = %hx\n",\
					sim_time,dut->a,dut->b,dut->led);
		}

		m_trace->dump(sim_time);

		sim_time++;
	}

	m_trace->close;

	delete dut;

	exit(EXIT_SUCCESS);

}
