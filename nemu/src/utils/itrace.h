
#ifndef __ITRACE_H__
#define __ITRACE_H__


#include <common.h>



void trace_inst(word_t pc, uint32_t inst);

void display_inst();

void trace_memory(paddr_t addr, int len , word_t data, int wr );

void display_memory();

#endif
