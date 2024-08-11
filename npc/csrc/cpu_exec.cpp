#include "npc_sources.h"
#include "cpu_exec.h"
#include "npc_expr.h"
#include "npc_init.h"
#include "npc_itrace.h"
#include "npc_ftrace.h"
#include "npc_watchpoint.h"
#include "npc_difftest.h"
#include <string.h>

int ebreak_dpi=0;

void ebreak(){
	ebreak_dpi=1;
	return;
}

CPU_state npc_cpu_state;

uint32_t read_cpu_state_pc(){
    return npc_cpu_state.pc;
}

uint32_t read_cpu_state_gpr(int ind){
    return npc_cpu_state.gpr[ind];
}

int check_watchpoint();
void exec_cpu(uint32_t exec_time);
void update_state();

uint32_t previous_pc;
uint32_t previous_ist;

int error_happen;

int curse ;
vluint64_t sim_time=0;
Vtop *dut = new Vtop;
VerilatedVcdC *m_trace = new VerilatedVcdC;
void init_cpu(){
    error_happen=0;
    curse=0;
	Verilated::traceEverOn(true);
	
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
    dut->eval();
    dut->ist = pmem_read(dut->pc,4);	
	dut->eval();
    trace_inst(dut->pc,dut->ist);
    update_state();
    previous_pc=dut->pc;
    previous_ist=dut->ist;
	m_trace->dump(sim_time);
	sim_time++;
}
    

void exec_cpu(uint32_t exec_time){
	
	if( curse==1 ){
		printf("\033[1;34mthe process of npc has been over,please restart NPC again\033[0m\n");
		return;
	}

    int exec_time_done ;
    for(exec_time_done=0;exec_time_done<exec_time;exec_time_done++){
        for(int edge = 0; edge <= 1; edge++){
        dut->clk^=1;
        dut->eval();
		
		dut->ist = pmem_read(dut->pc,4);
		
		dut->eval();

		m_trace->dump(sim_time);

		sim_time++;
        
        m_trace->dump(sim_time);
        }
		
		if(check_watchpoint()==1)break;

        trace_inst(dut->pc,dut->ist);
        update_state();
        error_happen = difftest_step(npc_cpu_state.pc);
        if(error_happen){
            sim_time = MAX_SIM_TIME;
            break;
        }

        if(dut->ftrace1)
        trace_func_call(dut->pc, dut->dnpc, false);
        else if(dut->ftrace2)
        trace_func_ret(dut->pc); // ret -> jalr x0, 0(x1)
        else if(dut->ftrace3)
        trace_func_call(dut->pc, dut->dnpc, false);
        else if (dut->ftrace4)
        trace_func_call(dut->pc, dut->dnpc, true);
        

        if(ebreak_dpi||sim_time>=MAX_SIM_TIME)break;
		
    }
    if(ebreak_dpi&&curse==0){ end_cpu();curse+=1;display_inst();
                    printf("\033[1;34m[%s,%d]Success!\nNPC running over,because the dpi-c ebreak matters\033[0m\r\n",__FILE__,__LINE__);
					printf("\033[1;32m[%s,%d]HIT GOOD TRAP!\033[0m",__FILE__,__LINE__);
					printf("at pc = %x\n",dut->pc);
                    return ;}
    else if(sim_time>=MAX_SIM_TIME&&curse==0){
        end_cpu();curse+=1;display_inst();
        printf("\033[1;31m[%s:%d]Fail!\nNPC running over,because of difftest or dead loop\033[0m\n",__FILE__,__LINE__);
        printf("\033[1;32m[%s,%d]HIT BAD TRAP!\033[0m\n",__FILE__,__LINE__);
		return ;}
    return;
}


uint32_t read_reg(int index){

     if(index==0)return dut-> rf0;
else if(index==1)return dut-> rf1;
else if(index==2)return dut-> rf2;
else if(index==3)return dut-> rf3;
else if(index==4)return dut-> rf4;
else if(index==5)return dut-> rf5;
else if(index==6)return dut-> rf6;
else if(index==7)return dut-> rf7;
else if(index==8)return dut-> rf8;
else if(index==9)return dut-> rf9;
else if(index==10)return dut->rf10;
else if(index==11)return dut->rf11;
else if(index==12)return dut->rf12;
else if(index==13)return dut->rf13;
else if(index==14)return dut->rf14;
else if(index==15)return dut->rf15;
else if(index==16)return dut->rf16;
else if(index==17)return dut->rf17;
else if(index==18)return dut->rf18;
else if(index==19)return dut->rf19;
else if(index==20)return dut->rf20;
else if(index==21)return dut->rf21;
else if(index==22)return dut->rf22;
else if(index==23)return dut->rf23;
else if(index==24)return dut->rf24;
else if(index==25)return dut->rf25;
else if(index==26)return dut->rf26;
else if(index==27)return dut->rf27;
else if(index==28)return dut->rf28;
else if(index==29)return dut->rf29;
else if(index==30)return dut->rf30;
else if(index==31)return dut->rf31;
else            return 0;

}

void update_state(){
    for(int i=0;i<=31;i++){
        npc_cpu_state.gpr[i]=read_reg(i);
    }
    npc_cpu_state.pc = dut->pc;
}
	
void end_cpu(){

    m_trace->close();

	delete dut;
	
	return ;
}


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
for(int i=0;i<32;i++){
	printf("%d:%s\t%x\n",i,regs[i],read_reg(i));
}
printf("%d:%s\t%x\n",33,"pc",dut->pc);

}

uint32_t isa_reg_str2val(const char *s, bool *success) {
    
    for(int i=0;i<32;i++)
    {   
        if(strcmp(regs[i],s)==0){
            
            return read_reg(i);
        }
        else if(strcmp("pc",s)==0){
            
            return dut->pc;
        }
    }
    printf("not find the register.\n");
    return 0;
}

int check_watchpoint(){
	    for(int i = 0 ; i < NR_WP; i ++){
        if(wp_pool_flag(i))
        {
            bool success = false;
            
            char *expr1=wp_pool_expr(i);

            int tmp = expr(expr1,&success);

            int old_value = wp_pool_old_value(i);

            if(success){
                if(tmp != old_value)
                {
                    wp_pool_write_new_value(i,tmp);
                    printf("NO.%d : expression:\"%s\",old:%d,new:%d\n",\
                    i, expr1,old_value, tmp);
                    return 1;
                }
				else return 0;
            }
            else{
                printf("expr error.\n");
                return 1;
            }
        }
		else return 0;}return 0;}
