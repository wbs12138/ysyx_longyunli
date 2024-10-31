TOPNAME = ysyxSoCFull
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                                -O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir

$(shell mkdir -p $(BUILD_DIR))

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath ./vsrc) -name "*.sv")
VSRCS += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
VSRCS += $(shell find $(abspath ../ysyxSoC/build) -name "*.v")
UART_INCLUDE_DIR = ../ysyxSoC/perip/uart16550/rtl
SPI_INCLUDE_DIR = ../ysyxSoC/perip/spi/rtl
CSRC_INCLUDE_DIR = /home/wangbaosen/ysyx/ysyx-workbench/npc/include

clean:
	rm -rf $(BUILD_DIR)
	rm -rf obj_dir

.PHONY: default all clean fpga
