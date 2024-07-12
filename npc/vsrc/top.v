module top(
  input clk,
  input rst,
  input a,b,
  output reg [15:0] led
);
  reg [31:0] count;
  always @(posedge clk) begin
    if (rst) begin led <= 1; count <= 0; end
    else begin
	    if(a&b)begin
      if (count == 0) led <= {led[14:0], led[15]};
      count <= (count >= 1000000 ? 32'b0 : count + 1);
    end
  end
  end
endmodule

