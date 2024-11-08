module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);
  wire [3:0] dio_in;
  wire [3:0] dio_out;
  wire [3:0] dio_en;

  assign dio_in = dio;

  reg [7:0] data [536870911:0];

  genvar i;

  generate 
    for(i=0;i<4;i=i+1) begin
      assign dio[i] = dio_en[i] ? dio_out[i] : 1'bz;
    end
  endgenerate

  reg [2:0] state,next_state;

  localparam CMD = 3'd0;
  localparam ADDR = 3'd1;
  localparam WRITE = 3'd2;
  localparam READ = 3'd3;

  reg [6:0] cnt;
  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      cnt<='b0;
    end
    else begin
      if(state==CMD & cnt==7'd7) begin
        cnt<='b0;
      end
      else if(state==ADDR & cnt==7'd5) begin
        cnt<='b0;
      end
      else if(state==WRITE & cnt==7'd1) begin
        cnt<='b0;
      end
      else if(state==READ & cnt==7'd1) begin
        cnt<='b0;
      end
      else begin
        cnt<=cnt+1'b1;
      end
    end
  end

  reg [7:0] cmd;

  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      cmd<='b0;
    end
    else begin
      if(state==CMD) begin
        cmd[cnt] <= dio_in[0];
      end
    end
  end

  reg [23:0] addr;

  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      addr<='b0;
    end
    else begin
      if(state==ADDR) begin
        addr[23-4*cnt]<=dio_in[3];
        addr[22-4*cnt]<=dio_in[2];
        addr[21-4*cnt]<=dio_in[1];
        addr[20-4*cnt]<=dio_in[0];
      end
      else if(state==WRITE) begin
        if(cnt==7'd1) begin
          addr<=addr + 1'b1;
        end
      end
      else if(state==READ) begin
        if(cnt==7'd1) begin
          addr<=addr + 1'b1;
        end
      end
    end
  end

  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      state<=CMD;
    end
    else begin
      state<=next_state;
    end
  end

  always@(*) begin
    case(state)
      CMD:begin
        if(cnt==7'd7) begin
          next_state = ADDR;
        end
        else begin
          next_state = CMD;
        end
      end

      ADDR: begin
        if(cnt==7'd5) begin
          if(cmd==8'h38) begin
            next_state = WRITE;
          end
          else if(cmd==8'heb) begin
            next_state = READ;
          end
          else begin
            next_state = CMD;
          end
        end
        else begin
          next_state = ADDR;
        end
      end

      WRITE: begin
        next_state = WRITE;
      end

      READ: begin
        next_state = READ;
      end
    endcase
  end

  always@(posedge sck) begin
    if(state==WRITE) begin
      if(cnt == 7'd0) begin
        data[addr][7] <= dio_in[3];
        data[addr][6] <= dio_in[2];
        data[addr][5] <= dio_in[1];
        data[addr][4] <= dio_in[0];
      end
      else begin
        data[addr][3] <= dio_in[3];
        data[addr][2] <= dio_in[2];
        data[addr][1] <= dio_in[1];
        data[addr][0] <= dio_in[0];
      end
    end
  end

  assign dio_out[3] = (cnt==7'd0) ? data[addr][7] : data[addr][3] ;
  assign dio_out[2] = (cnt==7'd0) ? data[addr][6] : data[addr][2] ;
  assign dio_out[1] = (cnt==7'd0) ? data[addr][5] : data[addr][1] ;
  assign dio_out[0] = (cnt==7'd0) ? data[addr][4] : data[addr][0] ;

  assign dio_en = (state==READ) ? 4'b1111 : 4'b0 ;

endmodule
