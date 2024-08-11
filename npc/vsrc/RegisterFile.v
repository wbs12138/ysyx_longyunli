module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  output [DATA_WIDTH-1:0] rdata,
  input [ADDR_WIDTH-1:0] raddr,
  output [DATA_WIDTH-1:0] rf0,
  output [DATA_WIDTH-1:0] rf1,
  output [DATA_WIDTH-1:0] rf2,
  output [DATA_WIDTH-1:0] rf3,
  output [DATA_WIDTH-1:0] rf4,
  output [DATA_WIDTH-1:0] rf5,
  output [DATA_WIDTH-1:0] rf6,
  output [DATA_WIDTH-1:0] rf7,
  output [DATA_WIDTH-1:0] rf8,
  output [DATA_WIDTH-1:0] rf9,
  output [DATA_WIDTH-1:0] rf10,
  output [DATA_WIDTH-1:0] rf11,
  output [DATA_WIDTH-1:0] rf12,
  output [DATA_WIDTH-1:0] rf13,
  output [DATA_WIDTH-1:0] rf14,
  output [DATA_WIDTH-1:0] rf15,
  output [DATA_WIDTH-1:0] rf16,
  output [DATA_WIDTH-1:0] rf17,
  output [DATA_WIDTH-1:0] rf18,
  output [DATA_WIDTH-1:0] rf19,
  output [DATA_WIDTH-1:0] rf20,
  output [DATA_WIDTH-1:0] rf21,
  output [DATA_WIDTH-1:0] rf22,
  output [DATA_WIDTH-1:0] rf23,
  output [DATA_WIDTH-1:0] rf24,
  output [DATA_WIDTH-1:0] rf25,
  output [DATA_WIDTH-1:0] rf26,
  output [DATA_WIDTH-1:0] rf27,
  output [DATA_WIDTH-1:0] rf28,
  output [DATA_WIDTH-1:0] rf29,
  output [DATA_WIDTH-1:0] rf30,
  output [DATA_WIDTH-1:0] rf31

);

  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  assign rdata = (raddr=='b0) ?     'b0     :
                                    rf[raddr];
  
  assign rf0 =32'b0;
  assign rf1 =rf[1];
  assign rf2 =rf[2];
  assign rf3 =rf[3];
  assign rf4 =rf[4];
  assign rf5 =rf[5];
  assign rf6 =rf[6];
  assign rf7 =rf[7];
  assign rf8 =rf[8];
  assign rf9 =rf[9];
  assign rf10=rf[10];
  assign rf11=rf[11];
  assign rf12=rf[12];
  assign rf13=rf[13];
  assign rf14=rf[14];
  assign rf15=rf[15];
  assign rf16=rf[16];
  assign rf17=rf[17];
  assign rf18=rf[18];
  assign rf19=rf[19];
  assign rf20=rf[20];
  assign rf21=rf[21];
  assign rf22=rf[22];
  assign rf23=rf[23];
  assign rf24=rf[24];
  assign rf25=rf[25];
  assign rf26=rf[26];
  assign rf27=rf[27];
  assign rf28=rf[28];
  assign rf29=rf[29];
  assign rf30=rf[30];
  assign rf31=rf[31];


endmodule
