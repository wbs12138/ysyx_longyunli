module dpi_c_ebreak(
    input [31:0] ist
);

import "DPI-C" function void ebreak();

always@(*)
begin
    if(ist==32'h00000073)
        ebreak();
end

endmodule
