module gpio_top_apb(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,//
  input         in_penable,//
  input  [2:0]  in_pprot,//
  input         in_pwrite,//
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,//
  output [31:0] in_prdata,
  output        in_pslverr,//

  output [15:0] gpio_out,
  input  [15:0] gpio_in,
  output [7:0]  gpio_seg_0,
  output [7:0]  gpio_seg_1,
  output [7:0]  gpio_seg_2,
  output [7:0]  gpio_seg_3,
  output [7:0]  gpio_seg_4,
  output [7:0]  gpio_seg_5,
  output [7:0]  gpio_seg_6,
  output [7:0]  gpio_seg_7
);

assign in_pready = 1'b1;

assign in_pslverr = 1'b0;

reg [15:0] switch;

always@(posedge clock) begin
  if(reset)
    switch <= 16'b0;
  else
    switch <= gpio_in;
end

reg [15:0] led;

assign gpio_out = led;

reg [31:0] segment;

wire [3:0] seg0,seg2,seg3,seg4,seg5,seg6,seg7;

assign seg7 = segment[31:28];
assign seg6 = segment[27:24];
assign seg5 = segment[23:20];
assign seg4 = segment[19:16];
assign seg3 = segment[15:12];
assign seg2 = segment[11: 8];
assign seg1 = segment[ 7: 4];
assign seg0 = segment[ 3: 0];

integer i;

always@(posedge clock) begin
  if(in_psel & in_penable & in_pwrite) begin
    if(in_paddr == 32'h10002000) begin
      for(i=0;i<2;i=i+1) begin
        if(in_pstrb[i])
          led[7+8*i:8*i] <= in_pwdata[7+8*i:8*i];
      end
    end

    else if(in_paddr == 32'h10002008) begin
      for(i=0;i<4;i=i+1) begin
        if(in_pstrb[i])
          segment[7+8*i:8*i] <= in_pwdata[7+8*i:8*i];
      end
    end
  end
end

assign in_prdata = {16'b0,switch};

wire [7:0] segs [15:0];

assign segs[0] = 8'b11111100;
assign segs[1] = 8'b01100000;
assign segs[2] = 8'b11011010;
assign segs[3] = 8'b11110010;
assign segs[4] = 8'b01100110;
assign segs[5] = 8'b10110110;
assign segs[6] = 8'b10111110;
assign segs[7] = 8'b11100000;
assign segs[8] = 8'b11111110;
assign segs[9] = 8'b11110110;
assign segs[10] = 8'b11101110;
assign segs[11] = 8'b00111110;
assign segs[12] = 8'b00011010;
assign segs[13] = 8'b01111010;
assign segs[14] = 8'b10011110;
assign segs[15] = 8'b10001110;

assign gpio_seg_0 = ~segs[seg0];
assign gpio_seg_1 = ~segs[seg1];
assign gpio_seg_2 = ~segs[seg2];
assign gpio_seg_3 = ~segs[seg3];
assign gpio_seg_4 = ~segs[seg4];
assign gpio_seg_5 = ~segs[seg5];
assign gpio_seg_6 = ~segs[seg6];
assign gpio_seg_7 = ~segs[seg7];


endmodule
