module top(
  input [1:0] Y,X0,X1,X2,X3,clk,
  input rst,
  output reg[1:0] F1
  
);
  wire [1:0] F;
  MuxKey #(4, 2, 2) inst_muxkey (F, Y, {
    2'b00, X0,
    2'b01, X1,
    2'b10, X2,
    2'b11, X3
    
  });

  always@(posedge clk or negedge rst)
  begin
    if(!rst)
    F1<='b0;
    else
    F1<=F;
  end
endmodule
