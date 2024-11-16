module bitrev (
  input  sck,
  input  ss,
  input  mosi,
  output reg miso
);

  reg [7:0] data;
  reg [2:0] cnt;

  reg state,next_state;

  localparam RX = 1'b0;
  localparam TX = 1'b1;

  always@(posedge sck or posedge ss) begin
    if(ss) begin
      state<=RX;
    end
    else begin
      state<=next_state;
    end
  end

  always@(*) begin
    case(state) 
    RX:begin
      if(cnt==3'd7) begin
        next_state = TX;
      end
      else begin
        next_state = RX;
      end
    end
    TX: 
      next_state = TX;
    endcase
  end

  always@(posedge sck or posedge ss) begin
      if(ss) begin
        data<='b0;
        cnt<='b0;
      end
      else begin
        if(!ss) begin
          if(state==RX) begin 
            data[cnt] <=  mosi;
          end
          cnt       <=  cnt+1'b1;
        end
      end
  end

  always@(posedge sck or posedge ss) begin
    if(ss) begin
      miso<=1'b1;
    end
    else begin
      if(state==RX & next_state== TX) begin
        miso<=mosi;
      end
      else begin
        if(state==TX) begin
          miso<=data[6-cnt];
        end
      end
    end
  end


endmodule
