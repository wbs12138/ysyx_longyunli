#include "npc_itrace.h"
#include "npc_disasm.h"

#define MAX_IRINGBUF 16
#define MAX_MRINGBUF 32
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_NONE       "\33[0m"


typedef struct {
  uint32_t pc;
  uint32_t inst;
} ItraceNode;

typedef struct {
  uint32_t pc;
  uint32_t inst;
  uint32_t addr;
  int len;
  uint32_t data; 
  int wr;
} MtraceNode;

ItraceNode iringbuf[MAX_IRINGBUF];
MtraceNode mringbuf[MAX_MRINGBUF];


int p_cur = 0;
bool full = false;

int pm_cur = 0;
bool full_m = false;

void trace_inst(uint32_t pc, uint32_t inst) {
  
  iringbuf[p_cur].pc = pc;
  iringbuf[p_cur].inst = inst;
  p_cur = (p_cur + 1) % MAX_IRINGBUF;
  full = full || p_cur == 0;
}


void trace_memory(uint32_t addr, int len , uint32_t data , int wr) {
  
  mringbuf[pm_cur].pc = (p_cur==0) ? iringbuf[15].pc : iringbuf[p_cur-1].pc;
  mringbuf[pm_cur].inst = (p_cur==0) ? iringbuf[15].inst : iringbuf[p_cur-1].inst;
  mringbuf[pm_cur].addr = addr;
  mringbuf[pm_cur].len = len;
  mringbuf[pm_cur].data = data;
  mringbuf[pm_cur].wr   = wr;
  pm_cur = (pm_cur + 1) % MAX_MRINGBUF;
  full_m = full_m || pm_cur == 0;
}


void display_inst() {
  if (!full && !p_cur) return;

  int end = p_cur;
  int i = full?p_cur:0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf[128]; // 128 should be enough!
  char *p;
  int msg1_over=0;
  init_disasm("riscv32");
  do {
    if(msg1_over==0){
      printf("     the instruction saved is:\n");
      msg1_over=1;
    }
    p = buf;
    p += sprintf(buf, "%s" "0x%08" "x" ": %08x ", (i+1)%MAX_IRINGBUF==end?" --> ":"     ", iringbuf[i].pc, iringbuf[i].inst);
    disassemble(p, buf+sizeof(buf)-p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);
    if ((i+1)%MAX_IRINGBUF==end) printf(ANSI_FG_RED);
    puts(buf);
  } while ((i = (i+1)%MAX_IRINGBUF) != end);
  puts(ANSI_NONE);
}



void display_memory() {
  if (!full_m && !pm_cur) return;

  int end_m = pm_cur;
  int i_m = full_m?pm_cur:0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf_m[128]; // 128 should be enough!
  char *pm;
  int msg2_over=0;
  do {
    if(msg2_over==0){
      printf("     the memory inst saved is:\n");
      msg2_over=1;
    }
    pm = buf_m;
    pm += sprintf(buf_m, "%s" "0x%08" "x" ": %08x ", (i_m+1)%MAX_MRINGBUF==end_m?" --> ":"     ", mringbuf[i_m].pc, mringbuf[i_m].inst);
    disassemble(pm, buf_m+sizeof(buf_m)-pm, mringbuf[i_m].pc, (uint8_t *)&mringbuf[i_m].inst, 4);
    if(mringbuf[i_m].wr==0)
    printf("     read from addr=%x,len=%d\n",mringbuf[i_m].addr,mringbuf[i_m].len);
    else
    printf("     write to  addr=%x,len=%d,data=%u\n",mringbuf[i_m].addr,mringbuf[i_m].len,mringbuf[i_m].data);
    if ((i_m+1)%MAX_MRINGBUF==end_m) printf(ANSI_FG_RED);
    puts(buf_m);
  } while ((i_m = (i_m+1)%MAX_MRINGBUF) != end_m);
  puts(ANSI_NONE);
}


