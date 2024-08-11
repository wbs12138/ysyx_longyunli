module top(
    input clk,reset,
    output reg [31:0] pc,
    input [31:0] ist


            );


wire [6:0] opcode,func7;
wire [2:0] func3;

assign opcode = ist[6:0];
assign func7  = ist[31:25];
assign func3  = ist[14:12];

wire    lui,auipc,jal,jalr,beq,bne,blt,bge,bltu,bgeu,lb,lh,lw,
        lbu,lhu,sb,sh,sw,addi,slti,sltiu,xori,ori,andi,slti,sltiu,
        xori,ori,andi,slli,srli,srai,add,sub,sll,slt,sltu,xorr,srl,
        sra,orr,andd,fence;//ecall,ebreak

assign lui      =   (opcode==7'b0110111);
assign auipc    =   (opcode==7'b0010111);
assign jal      =   (opcode==7'b1101111);
assign jalr     =   (opcode==7'b1100111) && (func3==3'b000);
assign beq      =   (opcode==7'b1100011) && (func3==3'b000);
assign bne      =   (opcode==7'b1100011) && (func3==3'b001);
assign blt      =   (opcode==7'b1100011) && (func3==3'b100);
assign bge      =   (opcode==7'b1100011) && (func3==3'b101);
assign bltu     =   (opcode==7'b1100011) && (func3==3'b110);
assign bgeu     =   (opcode==7'b1100011) && (func3==3'b111);
assign lb       =   (opcode==7'b0000011) && (func3==3'b000);
assign lh       =   (opcode==7'b0000011) && (func3==3'b001);
assign lw       =   (opcode==7'b0000011) && (func3==3'b010);
assign lbu      =   (opcode==7'b0000011) && (func3==3'b100);
assign lhu      =   (opcode==7'b0000011) && (func3==3'b101);
assign sb       =   (opcode==7'b0100011) && (func3==3'b000);
assign sh       =   (opcode==7'b0100011) && (func3==3'b001);
assign sw       =   (opcode==7'b0100011) && (func3==3'b010);
assign addi     =   (opcode==7'b0010011) && (func3==3'b000);
assign slti     =   (opcode==7'b0010011) && (func3==3'b010);
assign sltiu    =   (opcode==7'b0010011) && (func3==3'b011);
assign xori     =   (opcode==7'b0010011) && (func3==3'b100);
assign ori      =   (opcode==7'b0010011) && (func3==3'b110);
assign andi     =   (opcode==7'b0010011) && (func3==3'b111);
assign slli     =   (opcode==7'b0010011) && (func3==3'b001) && (func7==7'b0000000);
assign srli     =   (opcode==7'b0010011) && (func3==3'b101) && (func7==7'b0000000);
assign srai     =   (opcode==7'b0010011) && (func3==3'b101) && (func7==7'b0100000);
assign add      =   (opcode==7'b0110011) && (func3==3'b000) && (func7==7'b0000000);
assign sub      =   (opcode==7'b0110011) && (func3==3'b000) && (func7==7'b0100000);
assign sll      =   (opcode==7'b0110011) && (func3==3'b001) && (func7==7'b0000000);
assign slt      =   (opcode==7'b0110011) && (func3==3'b010) && (func7==7'b0000000);
assign sltu     =   (opcode==7'b0110011) && (func3==3'b011) && (func7==7'b0000000);
assign xorr     =   (opcode==7'b0110011) && (func3==3'b100) && (func7==7'b0000000);
assign srl      =   (opcode==7'b0110011) && (func3==3'b101) && (func7==7'b0000000);
assign sra      =   (opcode==7'b0110011) && (func3==3'b101) && (func7==7'b0100000);
assign orr      =   (opcode==7'b0110011) && (func3==3'b110) && (func7==7'b0000000);
assign andd     =   (opcode==7'b0110011) && (func3==3'b111) && (func7==7'b0000000);
assign fence    =   (opcode==7'b0001111) && (func3==3'b000);


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
(clk,rf_wdata,rf_waddr,rf_wen,rf_rdata,rf_raddr);

wire [31:0] pc_next ;

assign pc_next  =   jalr ?  (rf_rdata + imm) & 32'hfffffffe :
                    jal  ?  pc+imm  :
                    pc + 4          ;

Reg #(32,32'h80000000) inst_pc (clk,reset,pc_next,pc,1'b1);

dpi_c_ebreak inst_dpi_c_ebreak(ist);

dpi_c_ftrace inst_dpi_c_ftrace (ist,pc_next);


endmodule
li,lui,auipc,lw,lbu,lb,lh,lhu,andi,sb,sw,sh,jal,xori,ori,addi,srai,srli,elli,jalr,blt,bltu,bge,bgeu,beq,bne,sra,srl,rem,remu,divu,div,mul,mulh,mulhu,and,sll,add,sub,sltu,sltiu,slti,slt,xor,or,ebreak,inv, 

