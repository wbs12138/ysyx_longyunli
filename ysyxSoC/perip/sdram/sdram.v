module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 1:0] dqm,
  inout [15:0] dq
);

  wire [15:0] dq_in;

  wire [15:0] dq_out;

  wire dq_oe;

  assign dq_in = dq;

  genvar i;

  generate 
    for(i=0;i<16;i=i+1) begin
      assign dq[i] = dq_oe ? dq_out[i] : 1'bz;
    end
  endgenerate

  reg [15:0]bank0[0:8191][0:511];
  reg [15:0]bank1[0:8191][0:511];
  reg [15:0]bank2[0:8191][0:511];
  reg [15:0]bank3[0:8191][0:511];


  reg [11:0] status_reg;

  wire [2:0] burst_length;

  wire [2:0] cas_latency;

  assign burst_length = status_reg[2:0];
  assign cas_latency = status_reg[6:4];

  reg [1:0] bank_addr;

  reg [12:0] row_addr;

  reg [8:0] column_addr_r;

  reg [8:0] column_addr_w;

  reg start_cnt;

  reg [2:0] cnt;

  wire load_mode_register;

  wire read;
  
  wire write;

  wire active;

  wire stop;

  assign load_mode_register = cke & !cs & !ras & !cas & !we;

  assign active = cke & !cs & !ras & cas & we;

  assign read = cke & !cs & ras & !cas & we;

  assign write = cke & !cs & ras & !cas & !we;

  assign stop = cke & !cs & ras & cas & !we;

  always@(posedge clk) begin
    if(active) begin
      row_addr <= a;
      bank_addr <= ba;
    end
  end

  always@(posedge clk) begin
    if(load_mode_register) begin
      status_reg[9:0] <= a[9:0];
    end
  end

  always@(posedge clk) begin
    if(read) begin
      column_addr_r <= a[8:0];
    end

    else begin
      column_addr_r <= column_addr_r + 1'b1;
    end
  end

  wire [15:0] data_to_out;

  reg [15:0] data_to_out_p,data_to_out_2p;

  always@(posedge clk) begin
    data_to_out_p <= data_to_out; 
    data_to_out_2p <= data_to_out_p; 
  end

  assign data_to_out =  bank_addr==2'd0 ? bank0[row_addr][column_addr_r] :
                        bank_addr==2'd0 ? bank1[row_addr][column_addr_r] :
                        bank_addr==2'd0 ? bank2[row_addr][column_addr_r] :
                                          bank3[row_addr][column_addr_r] ;

  assign dq_out = cas_latency==3'd2 ? data_to_out_p :
                                      data_to_out_2p;

  always@(posedge clk) begin
    start_cnt <= 1'd0;
    if(write) begin
      start_cnt <= 1'd1;
      column_addr_w <= a[8:0] + 1'b1;
    end

    else begin
      column_addr_w <= column_addr_w + 1'b1;
    end
  end

  always@(posedge clk) begin
    if(start_cnt) begin
      if(burst_length != 3'd0)
        cnt <= 3'd1;
    end

    else if(stop) begin
      cnt <= 3'b0;
    end
    
    else if(cnt != 'b0) begin
      cnt <= cnt + 1'b1;
      if(burst_length == 3'b001) begin
        cnt <= 3'd0;
      end
      else if(burst_length == 3'b010) begin
        if(cnt == 3'd3)
          cnt <= 3'd0;
      end
      else if(burst_length == 3'b011) begin
        if(cnt == 3'd7)
          cnt <= 3'd0;
      end
    end
  end

  wire [8:0] column_w;

  assign column_w = a[8:0];

  wire [15:0] data_in;

  wire [15:0] remain_data;

  assign remain_data =  write & bank_addr==2'd0 ? bank0[row_addr][column_w] :
                        write & bank_addr==2'd1 ? bank1[row_addr][column_w] :
                        write & bank_addr==2'd2 ? bank2[row_addr][column_w] :
                        write & bank_addr==2'd3 ? bank3[row_addr][column_w] :
                        bank_addr==2'd0                                ? bank0[row_addr][column_addr_w] :
                        bank_addr==2'd1                                ? bank1[row_addr][column_addr_w] :
                        bank_addr==2'd2                                ? bank2[row_addr][column_addr_w] :
                                                                         bank3[row_addr][column_addr_w] ;


  assign data_in =  dqm[1] & dqm[0] ? dq_in :
                    dqm[1] & !dqm[0]? {dq_in[15:8],remain_data[7:0]} :
                    !dqm[1] & dqm[0]? {remain_data[15:8],dq_in[7:0]} :
                                      {remain_data} ;


  always@(posedge clk) begin
    if(write) begin
      if(bank_addr == 2'd0)
        bank0[row_addr][column_w] <= data_in;
      else if(bank_addr == 2'd1)
        bank1[row_addr][column_w] <= data_in;
      else if(bank_addr == 2'd2)
        bank2[row_addr][column_w] <= data_in;
      else
        bank3[row_addr][column_w] <= data_in;
    end
    else if(cnt != 3'b0 & !stop) begin
      if(bank_addr == 2'd0)
        bank0[row_addr][column_addr_w] <= data_in;
      else if(bank_addr == 2'd1)
        bank1[row_addr][column_addr_w] <= data_in;
      else if(bank_addr == 2'd2)
        bank2[row_addr][column_addr_w] <= data_in;
      else
        bank3[row_addr][column_addr_w] <= data_in;
    end 
  end

  assign dq_oe = !((cke & !cs & ras & !cas & !we) || (cnt != 3'b0));

  wire [15:0] data_debug;

  assign data_debug = bank0[0][419];

  wire addr_debug;

  assign addr_debug = column_addr_w == 9'd419;



endmodule
