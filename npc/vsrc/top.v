module top(
  input [1:0] Y,X0,X1,X2,X3,
  output [1:0] F
  
);
  
  MuxKey #(4, 2, 2) inst_muxkey (F, Y, {
    2'b00, X0,
    2'b01, X1,
    2'b10, X2,
    2'b11, X3
    
  });
endmodule
