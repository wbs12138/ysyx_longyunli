#include "npc_itrace.h"
#include "npc_disasm.h"

#define MAX_IRINGBUF 16
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_NONE       "\33[0m"


typedef struct {
  uint32_t pc;
  uint32_t inst;
} ItraceNode;

ItraceNode iringbuf[MAX_IRINGBUF];


int p_cur = 0;
bool full = false;

void trace_inst(uint32_t pc, uint32_t inst) {
  
  iringbuf[p_cur].pc = pc;
  iringbuf[p_cur].inst = inst;
  p_cur = (p_cur + 1) % MAX_IRINGBUF;
  full = full || p_cur == 0;
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



