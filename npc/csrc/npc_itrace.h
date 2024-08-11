
#ifndef NPC_ITRACE_H__
#define NPC_ITRACE_H__


#include <fcntl.h>
#include <unistd.h>
#include "/usr/include/elf.h"
#include "npc_sources.h"


void trace_inst(uint32_t pc, uint32_t inst);

void display_inst();

void parse_elf(const char *elf_file);

void trace_func_call(uint32_t pc, uint32_t target, bool is_tail);

void trace_func_ret(uint32_t pc);

#endif
