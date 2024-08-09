module top(
    input clk,reset,
    output reg [31:0] pc,
    input [31:0] ist
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

wire [11:0] imm;

wire [4:0] rs1,rd;

assign imm =  inst_i ? {20'b0,ist[31:20]}   : 
              inst_u ? {ist[31:12],12'b0}   :
              inst_j ? {12'b0,ist[31],ist[7:0],ist[8],ist[18:9]}:'b0;

assign rs1 = ist[19:15] ;

assign rd = ist[11:7] ;

wire [31:0] rf_wdata,rf_rdata;

wire [4:0] rf_waddr,rf_raddr;

wire rf_wen;

assign rf_waddr = rd ;

assign rf_raddr = rs1 ;

assign rf_wen= addi | auipc | lui ;

assign rf_wdata =   addi ? rf_rdata + {{20{imm[11]}},imm}   :
                    auipc? pc + imm                         :
                    lui  ? imm                              :
                    'b0;


RegisterFile #(5,32) inst_RegisterFile 
(clk,rf_wdata,rf_waddr,rf_wen,rf_rdata,rf_raddr);

wire [31:0] pc_next ;

assign pc_next  =   jalr ?  (rf_rdata + imm) & 32'hfffffffe;
                    jal  ?  pc+imm  :
                    pc + 4          ;

Reg #(32,32'h80000000) inst_pc (clk,reset,pc_next,pc,1'b1);


dpi_c_ebreak inst_dpi_c_ebreak(ist);


endmodule
