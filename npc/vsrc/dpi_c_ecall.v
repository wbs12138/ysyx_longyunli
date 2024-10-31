module dpi_c_ecall(
    input [31:0] ist
);

import "DPI-C" function void npc_ecall(input int ecall, input int mret);

wire ecall,mret;

wire ecall_t,mret_t;

assign ecall = (ist == 32'b00000000000000000000000001110011);
assign mret  = (ist == 32'b00110000001000000000000001110011);

assign ecall_t = {30'b0,ecall};

assign mret_t = {30'b0,mret};

always@(*)
begin
    npc_ecall(ecall_t,mret_t);
end

endmodule
