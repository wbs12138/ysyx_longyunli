TOPNAME = top
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
CSRCS = $(shell find $(abspath ./csrc/fpga) -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)
CSRCS_SIM = ./csrc/cpu_exec.cpp ./csrc/npc_expr.cpp ./csrc/npc_init.cpp ./csrc/npc_sdb.cpp ./csrc/npc_watchpoint.cpp ./csrc/main_sim.cpp

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
	verilator -Wall $(VSRCS) $(CSRCS_SIM) --cc --exe --build -j --trace --top-module $(TOPNAME) -lreadline
	obj_dir/V$(TOPNAME) $(IMG) $(ELF)

wave:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall $(VSRCS) $(CSRCS_SIM) --cc --exe --build -j --trace --top-module $(TOPNAME)
	obj_dir/V$(TOPNAME)
	gtkwave waveform.vcd


.PHONY: default all clean fpga sim wave compile

include ../Makefile
