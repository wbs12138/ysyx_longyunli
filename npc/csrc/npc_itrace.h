
#ifndef NPC_ITRACE_H__
#define NPC_ITRACE_H__


#include <fcntl.h>
#include <unistd.h>
#include "npc_sources.h"


void trace_inst(uint32_t pc, uint32_t inst);

void display_inst();

void trace_memory(uint32_t addr, int len , uint32_t data, int wr );

void display_memory();


#endif
