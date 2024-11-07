// define this macro to enable fast behavior simulation
// for flash by skipping SPI transfers

module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output reg [31:0] in_prdata,
  output        in_pslverr,

  output                  spi_sck,
  output [spi_ss_num-1:0] spi_ss,
  output                  spi_mosi,
  input                   spi_miso,
  output                  spi_irq_out
);
assign in_pslverr = 1'b0;

reg [31:0] in_paddr_r;
reg        in_psel_r;
reg        in_penable_r;
reg        in_pwrite_r;
reg [31:0] in_pwdata_r;
reg [3:0]  in_pstrb_r;
wire       in_pready_r;
wire[31:0] in_prdata_r;

reg [3:0] state,next_state;

localparam IDLE = 4'd0;
localparam REG_CONFIG = 4'd1;
localparam REG_CONFIG_READ = 4'd2;
localparam REG_CONFIG_WB = 4'd3;
localparam FLASH_CONFIG_FREQ = 4'd4;
localparam FLASH_CONFIG_CTRL = 4'd5;
localparam FLASH_CONFIG_DATA0 = 4'd6;
localparam FLASH_CONFIG_DATA1 = 4'd7;
localparam FLASH_CONFIG_SS = 4'd8;
localparam FLASH_CONFIG_START = 4'd9;
localparam FLASH_READ_BUSY = 4'd10;
localparam FLASH_CONFIG_SS_N = 4'd11;
localparam FLASH_READ_DATA = 4'd12;
localparam FLASH_WB = 4'd13;

assign in_pready = (state==REG_CONFIG_WB) || (state==FLASH_WB) || (state==REG_CONFIG && next_state==IDLE);

always@(posedge clock or posedge reset) begin
  if(reset) begin
    state<=IDLE;
  end
  else begin
    state<=next_state;
  end
end

always@(*) begin
  case(state) 
    IDLE: begin
      if(in_psel & in_penable & in_pwrite & (in_paddr>=32'h10001000 & in_paddr<=32'h10001fff))
        next_state = REG_CONFIG;
      else if(in_psel & in_penable & !in_pwrite & (in_paddr>=32'h10001000 & in_paddr<=32'h10001fff))
        next_state = REG_CONFIG_READ;
      else if(in_psel & in_penable & !in_pwrite & (in_paddr>=32'h30000000 & in_paddr<=32'h3fffffff))
        next_state = FLASH_CONFIG_FREQ;
      else
        next_state = IDLE;
    end

    REG_CONFIG: begin
      if(in_pready_r) 
        next_state = IDLE;
      else 
        next_state = REG_CONFIG;
    end

    REG_CONFIG_READ: begin
      if(in_pready_r) 
        next_state = REG_CONFIG_WB;
      else 
        next_state = REG_CONFIG_READ;
    end

    REG_CONFIG_WB: begin
      next_state = IDLE;
    end

    FLASH_CONFIG_FREQ: begin
      if(in_pready_r) 
        next_state = FLASH_CONFIG_CTRL;
      else 
        next_state = FLASH_CONFIG_FREQ;
    end

    FLASH_CONFIG_CTRL: begin
      if(in_pready_r) 
          next_state = FLASH_CONFIG_DATA1;
      else
        next_state = FLASH_CONFIG_CTRL;
    end

    FLASH_CONFIG_DATA1: begin
      if(in_pready_r)
        next_state = FLASH_CONFIG_DATA0;
      else
        next_state = FLASH_CONFIG_DATA1;
    end

    FLASH_CONFIG_DATA0: begin
      if(in_pready_r)
        next_state = FLASH_CONFIG_SS;
      else
        next_state = FLASH_CONFIG_DATA0;
    end

    FLASH_CONFIG_SS: begin
      if(in_pready_r)
        next_state = FLASH_CONFIG_START;
      else
        next_state = FLASH_CONFIG_SS;
    end

    FLASH_CONFIG_START: begin
      if(in_pready_r)
        next_state = FLASH_READ_BUSY;
      else 
        next_state = FLASH_CONFIG_START;
    end

    FLASH_READ_BUSY: begin
      if(in_pready_r) begin
        if(in_prdata_r[8]==1'b1) 
          next_state = FLASH_READ_BUSY;
        else
          next_state = FLASH_CONFIG_SS_N;
      end
      else
        next_state = FLASH_READ_BUSY;
    end

    FLASH_CONFIG_SS_N: begin
      if(in_pready_r) 
        next_state = FLASH_READ_DATA;
      else
        next_state = FLASH_CONFIG_SS_N;
    end

    FLASH_READ_DATA: begin
      if(in_pready_r)
        next_state = FLASH_WB;
      else
        next_state = FLASH_READ_DATA;
    end

    FLASH_WB: begin
      next_state = IDLE;
    end    
  endcase
end


always@(posedge clock or posedge reset) begin
  if(reset) begin
    in_paddr_r<='b0;
    in_pwdata_r<='b0;
    in_prdata<='b0;
    in_pstrb_r<='b0;
    in_pwrite_r<='b0;
    in_psel_r<='b0;
    in_penable_r<='b0;
  end
  else begin
    case(state) 
      IDLE: begin
        if(next_state == REG_CONFIG) begin
          in_paddr_r<=in_paddr;
          in_pwdata_r<=in_pwdata;
          in_pstrb_r<=in_pstrb;
          in_pwrite_r<=in_pwrite;
          in_psel_r<=in_psel;
          in_penable_r<=in_penable;
        end
        else if(next_state == REG_CONFIG_READ) begin
          in_paddr_r<=in_paddr;
          in_pwdata_r<=in_pwdata;
          in_pstrb_r<=in_pstrb;
          in_pwrite_r<=in_pwrite;
          in_psel_r<=in_psel;
          in_penable_r<=in_penable;
        end  
        else if(next_state == FLASH_CONFIG_FREQ) begin
          in_paddr_r<=32'h30000014;
          in_pwdata_r<=32'h00000004;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      REG_CONFIG: begin
        if(next_state == IDLE) begin
          in_paddr_r<='b0;
          in_pwdata_r<='b0;
          in_prdata<='b0;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<='b0;
          in_penable_r<='b0;
        end
      end

      REG_CONFIG_READ: begin
        if(next_state == REG_CONFIG_WB) begin
          in_paddr_r<='b0;
          in_pwdata_r<='b0;
          in_prdata<=in_prdata_r;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<='b0;
          in_penable_r<='b0;
        end
      end

      REG_CONFIG_WB: begin
        if(next_state == IDLE) begin
          in_paddr_r<='b0;
          in_pwdata_r<='b0;
          in_prdata<='b0;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<='b0;
          in_penable_r<='b0;
        end
      end

      FLASH_CONFIG_FREQ: begin
        if(next_state = FLASH_CONFIG_CTRL) begin
          in_paddr_r<=32'h30000010;
          in_pwdata_r<=32'h00000440;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end 
      end

      FLASH_CONFIG_CTRL: begin
        if(next_state == FLASH_CONFIG_DATA1) begin
          in_paddr_r<=32'h30000004;
          in_pwdata_r<={8'h03,in_paddr[23:0]};
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_CONFIG_DATA1: begin
        if(next_state == FLASH_CONFIG_DATA0) begin
          in_paddr_r<=32'h30000000;
          in_pwdata_r<=32'h0;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_CONFIG_DATA0: begin
        if(next_state == FLASH_CONFIG_SS) begin
          in_paddr_r<=32'h30000018;
          in_pwdata_r<=32'h1;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_CONFIG_SS: begin
        if(next_state == FLASH_CONFIG_START) begin
          in_paddr_r<=32'h30000010;
          in_pwdata_r<=32'h00000540;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_CONFIG_START: begin
        if(next_state == FLASH_READ_BUSY) begin
          in_paddr_r<=32'h30000010;
          in_pwdata_r<='b0;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<='b0;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_READ_BUSY: begin
        if(next_state == FLASH_CONFIG_SS_N) begin
          in_paddr_r<=32'h30000018;
          in_pwdata_r<=32'h0;
          in_prdata<='b0;
          in_pstrb_r<=4'b1111;
          in_pwrite_r<=1'b1;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_CONFIG_SS_N: begin
        if(next_state == FLASH_READ_DATA) begin
          in_paddr_r<=32'h0;
          in_pwdata_r<='b0;
          in_prdata<='b0;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<=1'b1;
          in_penable_r<=1'b1;
        end
      end

      FLASH_READ_DATA: begin
        if(next_state == FLASH_WB) begin
          in_paddr_r<='b0;
          in_pwdata_r<='b0;
          in_prdata<=in_prdata_r;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<='b0;
          in_penable_r<='b0;
        end
      end

      FLASH_WB: begin
        if(next_state == IDLE) begin
          in_paddr_r<='b0;
          in_pwdata_r<='b0;
          in_pstrb_r<='b0;
          in_pwrite_r<='b0;
          in_psel_r<='b0;
          in_penable_r<='b0;
        end
      end    
    endcase
  end
end


spi_top u0_spi_top (
  .wb_clk_i(clock),
  .wb_rst_i(reset),
  .wb_adr_i(in_paddr_r[4:0]),
  .wb_dat_i(in_pwdata_r),
  .wb_dat_o(in_prdata_r),
  .wb_sel_i(in_pstrb_r),
  .wb_we_i (in_pwrite_r),
  .wb_stb_i(in_psel_r),
  .wb_cyc_i(in_penable_r),
  .wb_ack_o(in_pready_r),
  .wb_err_o(),
  .wb_int_o(),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

endmodule
