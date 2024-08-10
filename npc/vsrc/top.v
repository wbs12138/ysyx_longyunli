module top(
    input clk,reset,
    output reg [31:0] pc,
    input [31:0] ist,
  output [31:0] rf0,
  output [31:0] rf1,
  output [31:0] rf2,
  output [31:0] rf3,
  output [31:0] rf4,
  output [31:0] rf5,
  output [31:0] rf6,
  output [31:0] rf7,
  output [31:0] rf8,
  output [31:0] rf9,
  output [31:0] rf10,
  output [31:0] rf11,
  output [31:0] rf12,
  output [31:0] rf13,
  output [31:0] rf14,
  output [31:0] rf15,
  output [31:0] rf16,
  output [31:0] rf17,
  output [31:0] rf18,
  output [31:0] rf19,
  output [31:0] rf20,
  output [31:0] rf21,
  output [31:0] rf22,
  output [31:0] rf23,
  output [31:0] rf24,
  output [31:0] rf25,
  output [31:0] rf26,
  output [31:0] rf27,
  output [31:0] rf28,
  output [31:0] rf29,
  output [31:0] rf30,
  output [31:0] rf31

            );

wire addi,jal,jalr,auipc,lui;

assign addi = (ist[14:12]==3'b000) && (ist[6:0]==7'b0010011);   //I R(rd) = src1 + imm
assign jalr = ((ist[14:12]==3'b000)&&(ist[6:0]==7'b1100111));   //I s->dnpc = (src1 + imm) & ~(word_t)1
assign auipc = (ist[6:0]==7'b0010111);                          //U R(rd) = s -> pc + imm
assign lui = (ist[6:0]==7'b0110111);                            //U R(rd) = imm
assign jal = (ist[6:0]==7'b1101111);                            //J s->dnpc = s->pc + imm

wire inst_i,inst_u,inst_j;

assign inst_i=addi|jalr;
assign inst_u=auipc|lui;
assign inst_j=jal;

wire [31:0] imm;

wire [4:0] rs1,rd;

assign imm =  inst_i ? {20'b0,ist[31:20]}   : 
              inst_u ? {ist[31:12],12'b0}   :
              inst_j ? {{11{ist[31]}},ist[31],ist[19:12],ist[20],ist[30:21],1'b0}:'b0;

assign rs1 = ist[19:15] ;

assign rd = ist[11:7] ;

wire [31:0] rf_wdata,rf_rdata;

wire [4:0] rf_waddr,rf_raddr;

wire rf_wen;

assign rf_waddr = rd ;

assign rf_raddr = rs1 ;

assign rf_wen= addi | auipc | lui | jal | jalr ;

assign rf_wdata =   addi ? rf_rdata + {{20{imm[11]}},imm[11:0]}   :
                    auipc? pc + imm                         :
                    lui  ? imm                              :
                    jal  ? pc + 4                           :
                    jalr ? pc + 4                           :
                    'b0;


RegisterFile #(5,32) inst_RegisterFile 
(clk,rf_wdata,rf_waddr,rf_wen,rf_rdata,rf_raddr,rf0,rf1,rf2,rf3,rf4,rf5,rf6,rf7,rf8,rf9,rf10,rf11,rf12,rf13,rf14,rf15,rf16,rf17,rf18,rf19,rf20,rf21,rf22,rf23,rf24,rf25,rf26,rf27,rf28,rf29,rf30,rf31);

wire [31:0] pc_next ;

assign pc_next  =   jalr ?  (rf_rdata + imm) & 32'hfffffffe :
                    jal  ?  pc+imm  :
                    pc + 4          ;

Reg #(32,32'h80000000) inst_pc (clk,reset,pc_next,pc,1'b1);


dpi_c_ebreak inst_dpi_c_ebreak(ist);

endmodule
