module ysyx_24080008(
    input clock,reset,
    input io_interrupt,

    input           io_master_awready ,
    output          io_master_awvalid ,
    output  [31:0]  io_master_awaddr  ,
    output  [3:0]   io_master_awid    ,
    output  [7:0]   io_master_awlen   ,
    output  [2:0]   io_master_awsize  ,
    output  [1:0]   io_master_awburst ,
    input           io_master_wready  ,
    output          io_master_wvalid  ,
    output  [31:0]  io_master_wdata   ,
    output  [3:0]   io_master_wstrb   ,
    output          io_master_wlast   ,
    output          io_master_bready  ,
    input           io_master_bvalid  ,
    input   [1:0]   io_master_bresp   ,
    input   [3:0]   io_master_bid     ,
    input           io_master_arready ,
    output          io_master_arvalid ,
    output  [31:0]  io_master_araddr  ,
    output  [3:0]   io_master_arid    ,
    output  [7:0]   io_master_arlen   ,
    output  [2:0]   io_master_arsize  ,
    output  [1:0]   io_master_arburst ,
    output          io_master_rready  ,
    input           io_master_rvalid  ,
    input   [1:0]   io_master_rresp   ,
    input   [31:0]  io_master_rdata   ,
    input           io_master_rlast   ,
    input   [3:0]   io_master_rid     

  );


wire [6:0] opcode,func7;
wire [2:0] func3;

assign opcode = ist[6:0];
assign func7  = ist[31:25];
assign func3  = ist[14:12];

wire    lui,auipc,jal,jalr,beq,bne,blt,bge,bltu,bgeu,lb,lh,lw,
        lbu,lhu,sb,sh,sw,addi,slti,sltiu,xori,ori,andi,slli,srli,
        srai,add,sub,sll,slt,sltu,xorr,srl,
        sra,orr,andd,ecall,mret,csrrw,csrrs;

assign lui      =   (opcode==7'b0110111);//U
assign auipc    =   (opcode==7'b0010111);//U
assign jal      =   (opcode==7'b1101111);//J
assign jalr     =   (opcode==7'b1100111) && (func3==3'b000);//I
assign beq      =   (opcode==7'b1100011) && (func3==3'b000);//B
assign bne      =   (opcode==7'b1100011) && (func3==3'b001);//B
assign blt      =   (opcode==7'b1100011) && (func3==3'b100);//B
assign bge      =   (opcode==7'b1100011) && (func3==3'b101);//B
assign bltu     =   (opcode==7'b1100011) && (func3==3'b110);//B
assign bgeu     =   (opcode==7'b1100011) && (func3==3'b111);//B
assign lb       =   (opcode==7'b0000011) && (func3==3'b000);//I
assign lh       =   (opcode==7'b0000011) && (func3==3'b001);//I
assign lw       =   (opcode==7'b0000011) && (func3==3'b010);//I
assign lbu      =   (opcode==7'b0000011) && (func3==3'b100);//I
assign lhu      =   (opcode==7'b0000011) && (func3==3'b101);//I
assign sb       =   (opcode==7'b0100011) && (func3==3'b000);//S
assign sh       =   (opcode==7'b0100011) && (func3==3'b001);//S
assign sw       =   (opcode==7'b0100011) && (func3==3'b010);//S
assign addi     =   (opcode==7'b0010011) && (func3==3'b000);//I
assign slti     =   (opcode==7'b0010011) && (func3==3'b010);//I
assign sltiu    =   (opcode==7'b0010011) && (func3==3'b011);//I
assign xori     =   (opcode==7'b0010011) && (func3==3'b100);//I
assign ori      =   (opcode==7'b0010011) && (func3==3'b110);//I
assign andi     =   (opcode==7'b0010011) && (func3==3'b111);//I
assign slli     =   (opcode==7'b0010011) && (func3==3'b001) && (func7==7'b0000000);//R
assign srli     =   (opcode==7'b0010011) && (func3==3'b101) && (func7==7'b0000000);//R
assign srai     =   (opcode==7'b0010011) && (func3==3'b101) && (func7==7'b0100000);//R
assign add      =   (opcode==7'b0110011) && (func3==3'b000) && (func7==7'b0000000);//R
assign sub      =   (opcode==7'b0110011) && (func3==3'b000) && (func7==7'b0100000);//R
assign sll      =   (opcode==7'b0110011) && (func3==3'b001) && (func7==7'b0000000);//R
assign slt      =   (opcode==7'b0110011) && (func3==3'b010) && (func7==7'b0000000);//R
assign sltu     =   (opcode==7'b0110011) && (func3==3'b011) && (func7==7'b0000000);//R
assign xorr     =   (opcode==7'b0110011) && (func3==3'b100) && (func7==7'b0000000);//R
assign srl      =   (opcode==7'b0110011) && (func3==3'b101) && (func7==7'b0000000);//R
assign sra      =   (opcode==7'b0110011) && (func3==3'b101) && (func7==7'b0100000);//R
assign orr      =   (opcode==7'b0110011) && (func3==3'b110) && (func7==7'b0000000);//R
assign andd     =   (opcode==7'b0110011) && (func3==3'b111) && (func7==7'b0000000);//R

assign csrrw    =   (opcode==7'b1110011) && (func3==3'b001);//I
assign csrrs    =   (opcode==7'b1110011) && (func3==3'b010);//I

assign ecall    =   (ist==32'b00000000000000000000000001110011);
assign mret     =   (ist==32'b00110000001000000000000001110011);


wire inst_i,inst_u,inst_j,inst_b,inst_s;//inst_r;

assign inst_i=jalr|lb|lh|lw|lbu|lhu|addi|slti|sltiu|xori|ori|andi|srli|slli|srai|csrrw|csrrs;

assign inst_u=auipc|lui;

assign inst_j=jal;

assign inst_b=beq|bne|blt|bge|bltu|bgeu;

assign inst_s=sb|sh|sw;

wire [31:0] imm;

wire [4:0] rs1,rs2,rd;

reg [31:0] rdata_mem;

assign imm =  inst_i ? {{20{ist[31]}},ist[31:20]}   : 
              inst_u ? {ist[31:12],12'b0}   :
              inst_j ? {{11{ist[31]}},ist[31],ist[19:12],ist[20],ist[30:21],1'b0}:
              inst_s ? {{20{ist[31]}},ist[31:25],ist[11:7]}:
              inst_b ? {{20{ist[31]}},ist[31],ist[7],ist[30:25],ist[11:8]}:'b0;

assign rs1 = ist[19:15] ;

assign rs2 = ist[24:20] ;

assign rd = ist[11:7] ;

wire [31:0] rf_wdata,rf_rdata1,rf_rdata2;

wire [4:0] rf_waddr,rf_raddr1,rf_raddr2;

wire rf_wen;

wire [31:0] csr_sel;

assign rf_waddr = rd ;

assign rf_raddr1 = rs1 ;

assign rf_raddr2 = rs2 ;

assign rf_wen=  lui|auipc|jal|jalr|lb|lh|lw|
                lbu|lhu|addi|slti|sltiu|xori|ori|andi|slli|srli|
                srai|add|sub|sll|slt|sltu|xorr|srl|
                sra|orr|andd|csrrs|csrrw ;

assign rf_wdata = lui   ?   imm     :
                  auipc ?   pc+imm  :
                  jal   ?   pc+4    :
                  jalr  ?   pc+4    :
                  lb    ?   {{24{rdata_mem[7]}},rdata_mem[7:0]} :
                  lh    ?   {{16{rdata_mem[15]}},rdata_mem[15:0]} :
                  lw    ?   rdata_mem:
                  lbu   ?   {24'b0,rdata_mem[7:0]} :
                  lhu   ?   {16'b0,rdata_mem[15:0]} :
                  addi  ?   rf_rdata1 + imm :
                  (slti&&(((rf_rdata1[31]==1)&&(imm[31]==0))||((rf_rdata1[31]==imm[31])&&(rf_rdata1[30:0]<imm[30:0]))))  ?   32'b1:
                  (sltiu&&(rf_rdata1<imm)) ?  32'b1   :
                  xori  ?   rf_rdata1 ^ imm :
                  ori   ?   rf_rdata1 | imm :
                  andi  ?   rf_rdata1 & imm :
                  slli  ?   rf_rdata1 <<imm :
                  srli  ?   rf_rdata1 >>imm :
                  srai  ?   ({32{rf_rdata1[31]}}<<(6'd32-{1'b0,imm[4:0]}))|(rf_rdata1>>imm[4:0]):
                  add   ?   rf_rdata1 + rf_rdata2:
                  sub   ?   rf_rdata1 - rf_rdata2:
                  sll   ?   rf_rdata1 <<rf_rdata2[4:0]:
                  (slt&&(((rf_rdata1[31]==1)&&(rf_rdata2[31]==0))||((rf_rdata1[31]==rf_rdata2[31])&&(rf_rdata1[30:0]<rf_rdata2[30:0]))))   ?  32'b1: 
                  (sltu&&(rf_rdata1<rf_rdata2))  ? 32'b1:
                  xorr  ?   rf_rdata1 ^ rf_rdata2 :
                  srl   ?   rf_rdata1 >> rf_rdata2[4:0] :
                  sra   ?   ({32{rf_rdata1[31]}}<<(6'd32-{1'b0,rf_rdata2[4:0]}))|(rf_rdata1>>rf_rdata2[4:0]):
                  orr   ?   rf_rdata1 | rf_rdata2 :
                  andd  ?   rf_rdata1 & rf_rdata2 :
                  csrrs ?   csr_sel :
                  csrrw ?   csr_sel :
                  32'b0;

wire [31:0] mepc,mtvec,mcause,mstatus;

wire [31:0] mepc_next,mtvec_next,mcause_next,mstatus_next;

wire mepc_en,mtvec_en,mcause_en,mstatus_en;

assign csr_sel  = (imm==32'h341)  ? mepc:
                  (imm==32'h342)  ? mcause:
                  (imm==32'h300)  ? mstatus:
                  (imm==32'h305)  ? mtvec:
                  32'b0;

assign mepc_next    = csrrw ? rf_rdata1   :
                      csrrs ? rf_rdata1|mepc  :
                      ecall ? pc :
                      32'b0;

assign mtvec_next   = csrrw ? rf_rdata1   :
                      csrrs ? rf_rdata1|mtvec  :
                      32'b0;

assign mcause_next  = csrrw ? rf_rdata1   :
                      csrrs ? rf_rdata1|mcause  :
                      ecall ? 32'hb   :
                      32'b0;

assign mstatus_next = csrrw ? rf_rdata1   :
                      csrrs ? rf_rdata1|mstatus  :
                      mret  ? {mstatus[31:13],2'b0,mstatus[10:8],1'b1,mstatus[6:4],mstatus[7],mstatus[2:0]}:
                      ecall ? {mstatus[31:13],2'b11,mstatus[10:8],mstatus[3],mstatus[6:4],1'b0,mstatus[2:0]}:
                      32'b0;

assign mepc_en      = ((imm==32'h341)&&(csrrw||csrrs)) | ecall ;
assign mtvec_en     = (imm==32'h305)&&(csrrw||csrrs);
assign mcause_en    = ((imm==32'h342)&&(csrrw||csrrs)) | ecall ;
assign mstatus_en   = ((imm==32'h300)&(csrrw|csrrs)) | mret | ecall ;

Reg #(32,32'h0) inst_mepc   (clock,reset,mepc_next,mepc,mepc_en & mem_rdone);
Reg #(32,32'h0) inst_mtvec  (clock,reset,mtvec_next,mtvec,mtvec_en & mem_rdone);
Reg #(32,32'h0) inst_mcause (clock,reset,mcause_next,mcause,mcause_en & mem_rdone);
Reg #(32,32'h1800) inst_mstatus(clock,reset,mstatus_next,mstatus,mstatus_en & mem_rdone);

wire [31:0] a0;
wire mem_rdone;
RegisterFile #(5,32) inst_RegisterFile 
(clock,rf_wdata,rf_waddr,rf_wen & mem_rdone,rf_rdata1,rf_rdata2,rf_raddr1,rf_raddr2,a0);

wire [31:0] pc_next ;

assign pc_next  =   jalr ?  (rf_rdata1 + imm) & 32'hfffffffe :
                    jal  ?  pc+imm  :
                    (beq&&(rf_rdata1==rf_rdata2))  ?  pc+(imm<<1) :
                    (bne&&(rf_rdata1!=rf_rdata2))  ?  pc+(imm<<1) :
                    (blt&&(((rf_rdata1[31]==1)&&(rf_rdata2[31]==0))||((rf_rdata1[31]==rf_rdata2[31])&&(rf_rdata1[30:0]<rf_rdata2[30:0])))) ? pc+(imm<<1):
                    (bltu&&(rf_rdata1<rf_rdata2))?pc+(imm<<1):
                    (bge&&(((rf_rdata1[31]==0)&&(rf_rdata2[31]==1))||((rf_rdata1[31]==rf_rdata2[31])&&(rf_rdata1[30:0]>=rf_rdata2[30:0])))) ? pc+(imm<<1):
                    (bgeu&&(rf_rdata1>=rf_rdata2))?pc+(imm<<1):
                    mret  ?   mepc  :
                    ecall ?   mtvec :
                    pc + 4          ;

Reg #(32,32'h80000000) inst_pc (clock,reset,pc_next,pc,mem_rdone);


wire mem_ren;

wire mem_wen;

wire [31:0] mem_raddr;

wire [31:0] mem_wdata,mem_waddr;

wire [3:0] mem_wmask;

wire [3:0] mem_rmask;

assign mem_ren = lb | lbu |lh | lhu | lw ;

assign mem_wen = sb | sh | sw ;

assign mem_raddr =  lb ? (rf_rdata1 + imm) :
                    lbu? (rf_rdata1 + imm) :
                    lh ? (rf_rdata1 + imm) :
                    lhu? (rf_rdata1 + imm) :
                    lw ? (rf_rdata1 + imm) :
                    32'b0;


assign mem_wdata = rf_rdata2 ;

assign mem_waddr = rf_rdata1 + imm ;

assign mem_wmask =  sb ? 4'b0001 :
                    sh ? 4'b0011 :
                    sw ? 4'b1111 :
                    4'b0;

assign mem_rmask = lb | lbu ? 4'b0001 :
                   lh | lhu ? 4'b0011 :
                   lw       ? 4'b1111 :
                   'b0;

dpi_c_ebreak inst_dpi_c_ebreak(ist,a0);

dpi_c_ftrace inst_dpi_c_ftrace (ist,pc_next);

axi_interface u_axi_interface(
  .clock(clock),
  .reset(reset),
  .io_master_awready(io_master_awready) ,
  .io_master_awvalid(io_master_awvalid) ,
  .io_master_awaddr (io_master_awaddr) ,
  .io_master_awid   (io_master_awid) ,
  .io_master_awlen  (io_master_awlen) ,
  .io_master_awsize (io_master_awsize) ,
  .io_master_awburst(io_master_awburst) ,
  .io_master_wready (io_master_wready) ,
  .io_master_wvalid (io_master_wvalid) ,
  .io_master_wdata  (io_master_wdata) ,
  .io_master_wstrb  (io_master_wstrb) ,
  .io_master_wlast  (io_master_wlast) ,
  .io_master_bready (io_master_bready) ,
  .io_master_bvalid (io_master_bvalid) ,
  .io_master_bresp  (io_master_bresp) ,
  .io_master_bid    (io_master_bid) ,
  .io_master_arready(io_master_arready) ,
  .io_master_arvalid(io_master_arvalid) ,
  .io_master_araddr (io_master_araddr) ,
  .io_master_arid   (io_master_arid) ,
  .io_master_arlen  (io_master_arlen) ,
  .io_master_arsize (io_master_arsize) ,
  .io_master_arburst(io_master_arburst) ,
  .io_master_rready (io_master_rready) ,
  .io_master_rvalid (io_master_rvalid) ,
  .io_master_rresp  (io_master_rresp) ,
  .io_master_rdata  (io_master_rdata) ,
  .io_master_rlast  (io_master_rlast) ,
  .io_master_rid    (io_master_rid)   ,
  .pc               (pc)              ,
  .ist              (ist)             ,
  .mem_wen          (mem_wen)         ,
  .mem_waddr        (mem_waddr)       ,
  .mem_wdata        (mem_wdata)       ,
  .mem_wmask        (mem_wmask)       ,
  .mem_ren          (mem_ren)         ,
  .rdata_mem        (rdata_mem)       ,
  .mem_raddr        (mem_raddr)       ,
  .mem_rdone        (mem_rdone)       ,
  .mem_rmask        (mem_rmask)

);

endmodule
