module top(
    input clk,reset,
    output reg [31:0] pc,
    input [31:0] ist
            );


wire [31:0] pc_next ;

assign pc_next = pc + 4'h4 ;

Reg #(32,32'h80000000) inst_pc (pc,pc_next,1'b1);

wire [11:0] imm1;

wire [4:0] rs1,rs2,rd;

wire addi ; 

assign addi = (ist[14:12]==3'b000) && (ist[6:0]==7'b0010011);

assign imm1 = (addi==1'b1) ? ist[31:20] :'b0 ;

assign rs1 = (addi==1'b1) ? ist[19:15] :'b0 ;

assign rd = (addi==1'b1) ? ist[11:7] :'b0 ;

wire [31:0] rf_wdata,rf_rdata;

wire [4:0] rf_waddr,rf_raddr;

wire wen;

assign rf_waddr = rd ;

assign rf_raddr = rs1 ;

assign wen= 'b1 ;

assign rf_wdata = rf_rdata + {20{imm1[11]},imm1} ;

RegisterFile #(5,32) inst_RegisterFile 
(clk,rf_wdata,rf_waddr,rf_wen,rf_rdata,rf_raddr);


endmodule