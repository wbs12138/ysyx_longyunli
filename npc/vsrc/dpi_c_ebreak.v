module dpi_c_ebreak(
    input [31:0] ist,
    input [31:0] a0
);

import "DPI-C" function void ebreak(input int back_right);

always@(*)
begin
    if(ist==32'h00100073)
        ebreak(a0);
end

endmodule
