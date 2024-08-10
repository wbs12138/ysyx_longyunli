#include "npc_sources.h"
#include "npc_compile.h"

vluint64_t sim_time=0;

int ebreak_dpi=0;

void ebreak(){
	ebreak_dpi=1;
	return;
}

int main(int argc,char** argv,char** env){
	
	int i=1;
    do{
		printf("argc[%d]=%s\n",i,argv[i-1]);
    	i+=1;
  	}while(i!=argc+1);

	char *img_file=NULL;
	img_file=argv[1];

	load_img(img_file);

	//init_mem();

	Vtop *dut = new Vtop;
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");

	int n=2;
	dut->reset=1;
	sim_time++;
	m_trace->dump(sim_time);
	while(n-->0){
		dut->clk = 0;dut->eval();
		m_trace->dump(sim_time);
		sim_time++;
		dut->clk = 1;dut->eval();
		m_trace->dump(sim_time);
		sim_time++;

	}
	dut->reset=0;
	m_trace->dump(sim_time);
	sim_time++;


	int a,b;
	while(sim_time<MAX_SIM_TIME&&ebreak_dpi==0){

		dut->clk^=1;
		
		dut->ist = pmem_read(dut->pc,4);
		printf("pc=%x\n",dut->pc);
		
		dut->eval();

		m_trace->dump(sim_time);

		sim_time++;

	}

	m_trace->close();

	if(ebreak_dpi==1)
	Log("NPC running over,because the dpi-c ebreak matters");
	else
	printf("NPC running over,because up to the max_sim_time");

	delete dut;

	exit(EXIT_SUCCESS);
	
	return 0;
}




