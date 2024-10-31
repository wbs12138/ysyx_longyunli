module dpi_c_ecall(
    input [31:0] ist
);

import "DPI-C" function void npc_ecall(input int ecall, input int mret);

wire ecall,mret;

assign ecall = (ist == 32'b00000000000000000000000001110011);
assign mret  = (ist == 32'b00110000001000000000000001110011);

always@(*)
begin
    npc_ecall(ecall,mret);
end

endmodule
