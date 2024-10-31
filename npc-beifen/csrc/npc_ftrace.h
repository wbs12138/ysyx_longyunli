#ifndef NPC_FTRACE_H
#define NPC_FTRACE_H


#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "npc_sources.h"


void parse_elf(const char *elf_file);

void trace_func_call(uint32_t pc, uint32_t target, bool is_tail);

void trace_func_ret(uint32_t pc);


#endif
