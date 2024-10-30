AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker_ysyxsoc.ld \
						 --defsym=_pmem_start=0x20000000 --defsym=_entry_offset=0x0 --defsym=_heap_start=0xf000000
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
YSYXSOC_FLAGS = is_batch_mode
.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) run IMG=$(IMAGE).bin ELF=$(IMAGE).elf ARGS="$(YSYXSOC_FLAGS)"
