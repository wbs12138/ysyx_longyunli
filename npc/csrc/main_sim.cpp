#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"

#define MAX_SIM_TIME 20000
#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x8000000
#define CONFIG_PC_RESET_OFFSET 0x0
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#define PG_ALIGN __attribute((aligned(4096)))


vluint64_t sim_time=0;

int ebreak_dpi=0;

void ebreak(){
	ebreak_dpi=1;
	return;
}

static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - CONFIG_MBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default:assert(0);
  }
}

static uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(uint32_t addr, int len, uint32_t data) {
  host_write(guest_to_host(addr), len, data);
}

void init_mem() {
  memset(pmem, rand(), CONFIG_MSIZE);
  printf("physical memory area [\" %d \", \" %d \"]", PMEM_LEFT, PMEM_RIGHT);
}

static char *img_file = NULL;

//static long load_img() 
void load_img(){
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return ;
  }

  FILE *fp = fopen(img_file, "rb");
  assert(fp);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return ;
}


int main(int argc,char** argv,char** env){
	
	//assert(argc==2);
	
	int i=1;
    do{
		printf("argc[%d]=%s\n",i,argv[i-1]);
    	i+=1;
  	}while(i!=argc+1);

	img_file=argv[1];

	load_img();

	init_mem();

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
		
		dut->eval();

		m_trace->dump(sim_time);

		sim_time++;

	}

	m_trace->close();

	if(ebreak_dpi==1)
	printf("NPC running over,because the dpi-c ebreak matters");
	else
	printf("NPC running over,because up to the max_sim_time");

	delete dut;

	exit(EXIT_SUCCESS);
	
	return 0;
}




