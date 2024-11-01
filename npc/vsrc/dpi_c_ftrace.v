module dpi_c_ftrace(input [31:0] ist,input [31:0] pc_next);
import "DPI-C" function void ftrace_update(input int dnpc_v,input int trace1,input int trace2,input int trace3,input int trace4);

wire [4:0] rd;

wire jal,jalr;

wire [31:0] imm;

wire ftrace1,ftrace2,ftrace3,ftrace4;

assign imm = {20'b0,ist[31:20]} ;

assign rd = ist[11:7] ;

assign jal = (ist[6:0]==7'b1101111); 

assign jalr = ((ist[14:12]==3'b000)&&(ist[6:0]==7'b1100111));   

assign ftrace1 = jal&&(rd==5'b1);

assign ftrace2 = jalr&&(ist==32'h00008067) ;

assign ftrace3 = jalr&&(rd==5'b1);

assign ftrace4 = jalr&&(rd==5'b0)&&(imm=='b0);

always@(*)
begin
    ftrace_update(pc_next ,{31'b0,ftrace1},{31'b0,ftrace2},{31'b0,ftrace3},{31'b0,ftrace4});
end



endmodule
