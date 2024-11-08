module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);
  wire [3:0] dio_in;
  wire [3:0] dio_out;
  wire [3:0] dio_en;

  assign dio_in = dio;

  reg [7:0] data [4194303:0];

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

  wire [2:0] cmd_index;
  assign cmd_index = cnt[2:0];

  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      cmd<='b0;
    end
    else begin
      if(state==CMD) begin
        cmd[7-cmd_index] <= dio_in[0];
      end
    end
  end

  reg [23:0] addr;
  wire [2:0]addr_index;
  assign addr_index = cnt[2:0];

  always@(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      addr<='b0;
    end
    else begin
      if(state==ADDR) begin
        addr[23-4*addr_index]<=dio_in[3];
        addr[22-4*addr_index]<=dio_in[2];
        addr[21-4*addr_index]<=dio_in[1];
        addr[20-4*addr_index]<=dio_in[0];
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

      default: begin
        next_state = CMD;
      end
    endcase
  end

  wire [21:0] data_index;
  assign data_index = addr[21:0];

  always@(posedge sck) begin
    if(state==WRITE) begin
      if(cnt == 7'd0) begin
        data[data_index][7] <= dio_in[3];
        data[data_index][6] <= dio_in[2];
        data[data_index][5] <= dio_in[1];
        data[data_index][4] <= dio_in[0];
      end
      else begin
        data[data_index][3] <= dio_in[3];
        data[data_index][2] <= dio_in[2];
        data[data_index][1] <= dio_in[1];
        data[data_index][0] <= dio_in[0];
      end
    end
  end

  assign dio_out[3] = (cnt==7'd0) ? data[data_index][7] : data[data_index][3] ;
  assign dio_out[2] = (cnt==7'd0) ? data[data_index][6] : data[data_index][2] ;
  assign dio_out[1] = (cnt==7'd0) ? data[data_index][5] : data[data_index][1] ;
  assign dio_out[0] = (cnt==7'd0) ? data[data_index][4] : data[data_index][0] ;

  assign dio_en = (state==READ) ? 4'b1111 : 4'b0 ;

endmodule
