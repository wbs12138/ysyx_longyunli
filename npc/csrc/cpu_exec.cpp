
#include "npc_sources.h"
#include "cpu_exec.h"
#include "npc_expr.h"
#include "npc_init.h"
#include "npc_itrace.h"
#include "npc_ftrace.h"
#include "npc_watchpoint.h"
#include "npc_difftest.h"
#include "npc_vga.h"
#include <sys/time.h>
#include <string.h>

int ebreak_dpi=0;

void ebreak(int back_right){
	if(back_right!=0)assert(0);
    else ebreak_dpi=1;
}

uint32_t m_waddr,m_wdata,m_raddr;
int m_len,trace_memory_w,trace_memory_r;
int total_steps=0;

CPU_state npc_cpu_state;

int dnpc=0;

int ftrace1=0,ftrace2=0,ftrace3=0,ftrace4=0;

uint32_t read_reg[32];

uint32_t read_cpu_state_pc(){
    return npc_cpu_state.pc;
}

uint32_t read_cpu_state_mepc(){
    return npc_cpu_state.mepc;
}

uint32_t read_cpu_state_mstatus(){
    return npc_cpu_state.mstatus;
}

uint32_t read_cpu_state_mtvec(){
    return npc_cpu_state.mtvec;
}

uint32_t read_cpu_state_mcause(){
    return npc_cpu_state.mcause;
}

uint32_t read_cpu_state_gpr(int ind){
    return npc_cpu_state.gpr[ind];
}

int check_watchpoint();
void exec_cpu(uint32_t exec_time);
void update_state();

int error_happen;

int curse ;
vluint64_t sim_time=0;
uint32_t pc_pre;
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
		dut->clk = 0;dut->ist=0;dut->eval();sim_time++;
		m_trace->dump(sim_time);
		
		dut->clk = 1;dut->eval();sim_time++;
		m_trace->dump(sim_time);
		
	}
	dut->reset=0;
    dut->eval();
    dut->ist = pmem_read(dut->pc,4);	
    
	dut->eval();
    pc_pre=dut->pc;
    update_state();
    sim_time+=1;
	m_trace->dump(sim_time);
    
	
}
    

void exec_cpu(uint32_t exec_time){
	
	if( curse==1 ){
		printf("\033[1;34mthe process of npc has been over,please restart NPC again\033[0m\n");
		return;
	}

    int exec_time_done ;
    for(exec_time_done=0;exec_time_done<exec_time;exec_time_done++){
        dut->ist = pmem_read(dut->pc,4);
		dut->eval();
        sim_time+=4;
        m_trace->dump(sim_time);
        dut->clk=0;
        dut->eval();
        sim_time+=4;
        dut->eval();
        m_trace->dump(sim_time);
        dut->clk=1;
        dut->eval();

        total_steps+=1;

		if(check_watchpoint()==1)break;

        #ifdef CONFIG_ITRACE
        trace_inst(pc_pre,dut->ist);
        #endif

        #ifdef CONFIG_MTRACE
        if(trace_memory_w)trace_memory(m_waddr,m_len,m_wdata,1);
        if(trace_memory_r)trace_memory(m_raddr,4,0xFFFFFFFF,0);
        trace_memory_r=0;
        trace_memory_w=0;
        #endif

        #ifdef CONFIG_DIFFTEST
        update_state();
        error_happen = difftest_step(npc_cpu_state.pc);
        if(error_happen){
            sim_time = MAX_SIM_TIME;
            break;
        }
        #endif

        #ifdef CONFIG_FTRACE
        if(ftrace1)
        trace_func_call(pc_pre, dut->pc, false);
        else if(ftrace2)
        trace_func_ret(pc_pre); // ret -> jalr x0, 0(x1)
        else if(ftrace3)
        trace_func_call(pc_pre, dut->pc, false);
        else if (ftrace4)
        trace_func_call(pc_pre, dut->pc, true);
        #endif

        #ifdef CONFIG_VGA
        vga_update_screen();
        #endif
        
        pc_pre=dut->pc;
        if(ebreak_dpi||sim_time>=MAX_SIM_TIME)break;
		
    }
    if(ebreak_dpi&&curse==0){ end_cpu();curse+=1;//display_inst();
                    printf("\033[1;34m[%s,%d]Success!\nNPC running over,because the dpi-c ebreak matters\033[0m\r\n",__FILE__,__LINE__);
					printf("\033[1;32m[%s,%d]HIT GOOD TRAP!\033[0m",__FILE__,__LINE__);
					printf("at pc = %x,total steps=%d\n",dut->pc,total_steps);
                    return ;}
    else if(sim_time>=MAX_SIM_TIME&&curse==0){
        end_cpu();curse+=1;
        printf("\033[1;31m[%s:%d]Fail!\nNPC running over,because of difftest or dead loop\033[0m\n",__FILE__,__LINE__);
        printf("\033[1;31m[%s,%d]HIT BAD TRAP!totalsteps=%d,sim_time=%ld\033[0m\n",__FILE__,__LINE__,total_steps,sim_time);
		assert(0);return ;}
    return;
}


void update_state(){
    for(int i=0;i<=31;i++){
        npc_cpu_state.gpr[i]=read_reg[i];
    }
    npc_cpu_state.pc = dut->pc;
    npc_cpu_state.mepc = dut->mepc;
    npc_cpu_state.mstatus = dut->mstatus;
    npc_cpu_state.mtvec = dut->mtvec;
    npc_cpu_state.mcause = dut->mcause;
}
static uint32_t *rtc_port_base =(uint32_t *)malloc(2*sizeof(uint32_t));
void end_cpu(){

    m_trace->close();

	delete dut;

    free(rtc_port_base);
	
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
	printf("%d:%s\t%x\n",i,regs[i],read_reg[i]);
}
printf("%d:%s\t%x\n",33,"pc",dut->pc);
printf("   %s\t%x\n","mcause ",dut->mcause);
printf("   %s\t%x\n","mepc   ",dut->mepc);
printf("   %s\t%x\n","mstatus",dut->mstatus);
printf("   %s\t%x\n","mtvec  ",dut->mtvec);

}

uint32_t isa_reg_str2val(const char *s, bool *success) {
    
    for(int i=0;i<32;i++)
    {   
        if(strcmp(regs[i],s)==0){
            
            return read_reg[i];
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

void ftrace_update(int dnpc_v,int trace1,int trace2, int trace3, int trace4){
    ftrace1=trace1;
    ftrace2=trace2;
    ftrace3=trace3;
    ftrace4=trace4;
    dnpc=dnpc_v;

}

void regfile_update(int rf1,int rf2,int rf3,int rf4,int rf5,int rf6,int rf7,int rf8,int rf9,int rf10,int rf11,int rf12,int rf13,int rf14,int rf15,int rf16,int rf17,int rf18,int rf19,int rf20,int rf21,int rf22,int rf23,int rf24,int rf25,int rf26,int rf27,int rf28,int rf29,int rf30 ,int rf31){
read_reg[0]=0;read_reg[1]= rf1;read_reg[2]= rf2;read_reg[3]= rf3;read_reg[4]= rf4;read_reg[5]= rf5;read_reg[6]= rf6;read_reg[7]= rf7;read_reg[8]= rf8;read_reg[9]= rf9;read_reg[10]= rf10;read_reg[11]= rf11;read_reg[12]= rf12;read_reg[13]= rf13;read_reg[14]= rf14;read_reg[15]= rf15;read_reg[16]= rf16;read_reg[17]= rf17;read_reg[18]= rf18;read_reg[19]= rf19;read_reg[20]= rf20;read_reg[21]= rf21;read_reg[22]= rf22;read_reg[23]= rf23;read_reg[24]= rf24;read_reg[25]= rf25;read_reg[26]= rf26;read_reg[27]= rf27;read_reg[28]= rf28;read_reg[29]= rf29;read_reg[30]= rf30 ;read_reg[31]= rf31;
}

static uint64_t boot_time = 0;

static uint64_t get_time_internal() {
    struct timeval now;
    gettimeofday(&now, NULL);
    uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
    return us;
};

uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}

uint64_t us;


int npc_pmem_read(int raddr) {
    if(dut->mem_valid ){

        if(raddr==0xa0000048){
            return rtc_port_base[0];   
        }
        else if(raddr==0xa0000048+4){
            us = get_time();
            rtc_port_base[0] = (uint32_t)us;
            rtc_port_base[1] = us >> 32;
            return rtc_port_base[1];
        }
        else if(raddr==0xa0000100){
            return read_vgactl();
        }

        trace_memory_r=1;
        m_raddr=(uint32_t)raddr;
        return pmem_read(m_raddr,4);
    }
    else return 0;
}

void npc_pmem_write(int waddr, int wdata, char wmask) {
    if(waddr == 0xa00003f8){
        char char_uart=(char)(wdata & 0xff);
        putchar(char_uart);
        return ;
    }
    else if(waddr == 0xa0000104){
        write_vgactl(wdata);
        return ;
    }
    else if(waddr >=0xa1000000 && waddr<=0xa2000000){
        vmem_write(waddr,4,wdata);
        return ;
    }
    trace_memory_w=1;
    
    if(wmask==1){
        m_waddr=(uint32_t)waddr;
        m_wdata=(uint32_t)wdata;m_len=1;
        pmem_write(waddr,1,wdata);
    }
    else if(wmask==3){
        m_waddr=(uint32_t)waddr;
        m_wdata=(uint32_t)wdata;m_len=2;
        pmem_write(waddr,2,wdata);
    }
    else if(wmask==15){
        m_waddr=(uint32_t)waddr;
        m_wdata=(uint32_t)wdata;
        m_len=4;
        pmem_write(waddr,4,wdata);
    }
    else assert(0);

  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
}

