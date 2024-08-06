module dpi_c_ebreak(
    input [31:0] ist
);

always@(*)
begin
    if(ist==32'h00000073)
        ebreak();
end

endmodule
