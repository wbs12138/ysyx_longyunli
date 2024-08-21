#ifndef NPC_VGA_H
#define NPC_VGA_H

#include "npc_sources.h"

#include <SDL2/SDL.h>

uint32_t *vgactl_port_base = NULL;


void init_vga();
void vga_update_screen();
void vmem_write(uint32_t addr, int len, uint32_t data);

void free_vgactl_port_base();



#endif