module dpi_c_ebreak(
    input [31:0] ist,
    input [31:0] a0
);

import "DPI-C" function void ebreak(input int back_right);

wire ebreak_happen;

assign ebreak_happen = ist == 32'h00100073;

always@(*)
begin
    if(ebreak_happen)
        ebreak(a0);
end

endmodule
