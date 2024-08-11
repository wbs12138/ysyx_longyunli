#ifndef NPC_DIFFTEST_H
#define NPC_DIFFTEST_H

#include "npc_sources.h"
#include "npc_init.h"
#include "npc_itrace.h"
#include "cpu_exec.h"
#include <dlfcn.h>

void init_difftest(char *ref_so_file, long img_size);
int difftest_step(uint32_t pc);

#endif
