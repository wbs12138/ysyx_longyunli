#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

-include $(NPC_HOME)/../Makefile
include $(NPC_HOME)/scripts/build.mk

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt
override ARGS += --diff=/home/wangbaosen/ysyx/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so

# Command to execute NEMU
IMG ?=

NXDC_FILES = /home/wangbaosen/ysyx/ysyx-workbench/npc/constr/top.nxdc

NVBOARD_VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

NVBOARD_BUILD_DIR = ./nvboard_build
$(shell mkdir -p $(NVBOARD_BUILD_DIR))
NVBOARD_OBJ_DIR = $(NVBOARD_BUILD_DIR)/obj_dir

# constraint file
SRC_AUTO_BIND = /home/wangbaosen/ysyx/ysyx-workbench/npc/nvboard_build/auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

SRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

run:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@rm -rf $(NVBOARD_OBJ_DIR)
	verilator $(VSRCS) $(SRCS) $(NVBOARD_ARCHIVE) $(NVBOARD_VERILATOR_CFLAGS) --Mdir $(VERILATOR_OBJ_DIR) --exe --build -j --trace --autoflush --top-module $(TOPNAME) --timescale "1ns/1ns" --no-timing +incdir+$(UART_INCLUDE_DIR) +incdir+$(SPI_INCLUDE_DIR) +incdir+$(CSRC_INCLUDE_DIR) -LDFLAGS '-lreadline -lSDL2 $(shell llvm-config --libs)' $(addprefix -CFLAGS , $(NVBOARD_CXXFLAGS)) $(addprefix -LDFLAGS , $(NVBOARD_LDFLAGS))
	obj_dir/V$(TOPNAME) $(ARGS) $(IMG)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run clean-tools clean-all $(clean-tools)
