TOPNAME = ysyxSoCFull
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                                -O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath ./vsrc) -name "*.sv")
VSRCS += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc/fpga) -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)
CSRCS_SIM = ./csrc/cpu_exec.cpp ./csrc/npc_expr.cpp ./csrc/npc_init.cpp ./csrc/npc_sdb.cpp ./csrc/npc_watchpoint.cpp ./csrc/main_sim.cpp ./csrc/npc_itrace.cpp ./csrc/npc_ftrace.cpp ./csrc/npc_difftest.cpp ./csrc/npc_vga.cpp
SO_FILE = /home/wangbaosen/ysyx/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so
UART_INCLUDE_DIR = ../ysyxSoC/perip/uart16550/rtl
SPI_INCLUDE_DIR = ../ysyxSoC/perip/spi/rtl

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
                $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
                --Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

fpga: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)
	rm -rf obj_dir

run:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall $(VSRCS) $(CSRCS_SIM) --cc --exe --build -j --trace --top-module $(TOPNAME) --timescale "1ns/1ns" --no-timing +incdir+$(UART_INCLUDE_DIR) +incdir+$(SPI_INCLUDE_DIR) -LDFLAGS '-lreadline -lSDL2 $(shell llvm-config --libs)'
	obj_dir/V$(TOPNAME) $(IMG) $(ELF) $(ARGS) $(SO_FILE)

wave:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall $(VSRCS) $(CSRCS_SIM) --cc --exe --build -j --trace --top-module $(TOPNAME)
	obj_dir/V$(TOPNAME)
	gtkwave waveform.vcd


.PHONY: default all clean fpga sim wave compile

include ../Makefile
