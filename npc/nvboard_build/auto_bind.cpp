#include </home/wangbaosen/ysyx/ysyx-workbench/nvboard/usr/include/nvboard.h>
#include "/home/wangbaosen/ysyx/ysyx-workbench/npc/obj_dir/VysyxSoCFull.h"

void nvboard_bind_all_pins(VysyxSoCFull* top) {
	nvboard_bind_pin( &top->externalPins_gpio_out, 16, LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
}
