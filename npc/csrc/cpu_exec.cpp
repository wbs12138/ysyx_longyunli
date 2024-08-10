#include "npc_sources.h"
#include "cpu_exec.h"
#include "npc_init.h"

extern uint32_t read_reg(int reg_index);

int ebreak_dpi=0;

void ebreak(){
	ebreak_dpi=1;
	return;
}

vluint64_t sim_time=0;

void init_cpu(){
    Vtop *dut = new Vtop;
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace,5);
	m_trace->open("waveform.vcd");

	int reset_clk_time=2;
	dut->reset=1;
	sim_time++;
	m_trace->dump(sim_time);
	while(reset_clk_time-->0){
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
}
    

int exec_cpu(uint32_t exec_time){
    int exec_time_done ;
    for(exec_time_done=0;exec_time_done<exec_time;exec_time_done++){
        
        dut->clk^=1;
		
		dut->ist = pmem_read(dut->pc,4);
		printf("pc=%x\n",dut->pc);
		
		dut->eval();

		m_trace->dump(sim_time);

		sim_time++;
        
        if(ebreak_dpi||sim_time>=MAX_SIM_TIME)break;

    }
    if(ebreak_dpi){ end_cpu();
                    printf("\033[1;34m[%s,%d]Success!\nNPC running over,because the dpi-c ebreak matters\033[0m\r\n",__FILE__,__LINE__);
                    return 2;}
    else if(sim_time>=MAX_SIM_TIME){
        end_cpu();
        printf("\033[1;31m[%s:%d]Fail!\nNPC running over,because up to the max_sim_time\033[0m\n",__FILE__,__LINE__);
        return 1;}
    else return 0;
}

	
void end_cpu(){

    m_trace->close();

	delete dut;

	exit(EXIT_SUCCESS);
	
	return ;
}


