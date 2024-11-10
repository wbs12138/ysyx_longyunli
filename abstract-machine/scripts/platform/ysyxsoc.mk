AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker_ysyxsoc.ld \
						 --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0 --defsym=_heap_end=0x84000000
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
YSYXSOC_FLAGS = -l $(shell dirname $(IMAGE).elf)/npc-log.txt -b -e $(IMAGE).elf
.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) run ARGS="$(YSYXSOC_FLAGS)" IMG=$(IMAGE).bin
