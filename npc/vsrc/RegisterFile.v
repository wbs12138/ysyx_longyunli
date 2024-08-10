module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  output [DATA_WIDTH-1:0] rdata,
  input [ADDR_WIDTH-1:0] raddr
);

export "DPI-C" function read_reg;

  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  assign rdata = (raddr=='b0) ?     'b0     :
                                    rf[raddr];
  
function [31:0] read_reg(input [4:0] reg_index);
  return rf[reg_index];
endfuction


