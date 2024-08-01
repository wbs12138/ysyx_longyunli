/*******************             experiment 1           ****************/

// module top(
//   input [1:0] Y,X0,X1,X2,X3,clk,
//   input rst,
//   output [1:0] F1
  
// );
//   MuxKey #(4, 2, 2) inst_muxkey (F1, Y, {
//     2'b00, X0,
//     2'b01, X1,
//     2'b10, X2,
//     2'b11, X3
    
//   });
// endmodule


/*******************             experiment 2           ****************/
// module top(
// input [7:0] btn,
// input en,
// output led_sig,
// output reg [2:0] led_num,
// output reg[7:0] digital_led
// );

// assign led_sig=en&(btn!='b0);

// always@(*)
// begin
//     if(!en)
//       led_num=3'd0;
//     else if(btn[7]==1'b1)
//       led_num=3'd7;
//     else if(btn[6]==1'b1)
//       led_num=3'd6;
//     else if(btn[5]==1'b1)
//       led_num=3'd5;
//     else if(btn[4]==1'b1)
//       led_num=3'd4;
//     else if(btn[3]==1'b1)
//       led_num=3'd3;
//     else if(btn[2]==1'b1)
//       led_num=3'd2;
//     else if(btn[1]==1'b1)
//       led_num=3'd1;
//     else if(btn[0]==1'b1)
//       led_num=3'd0;
//     else
//       led_num=3'd0;
// end

// always@(*)
// begin
//   if(!en)               digital_led=8'b00000010;
//   else if(led_num==3'd7)digital_led=8'b00011111;
//   else if(led_num==3'd6)digital_led=8'b01000001;
//   else if(led_num==3'd5)digital_led=8'b01001001;
//   else if(led_num==3'd4)digital_led=8'b10011001;
//   else if(led_num==3'd3)digital_led=8'b00001101;
//   else if(led_num==3'd2)digital_led=8'b00100101;
//   else if(led_num==3'd1)digital_led=8'b10011111;
//   else                  digital_led=8'b00000010;

  
// end
// endmodule


/*******************             experiment 3           ****************/
// module top(
// input [3:0] A,B,
// input [2:0] selector,
// output [3:0] Result,
// output Overflow,Zero,Carry
// );

// wire SA;

// wire [3:0] comp_result;

// assign SA = (selector == 3'b001);

// wire [3:0] B_i;

// assign B_i = {4{SA}}^B ;

// assign {Carry,comp_result}= A + B_i + {3'b0,SA} ;

// assign Overflow = (A[3]==B_i[3])&&(comp_result[3]!=A[3]);

// assign Zero = ~(|comp_result);

// assign Result = (selector == 3'b000 || selector == 3'b001)      ?   comp_result :
//                 (selector == 3'b010)                            ?   ~A          :
//                 (selector == 3'b011)                            ?   A&B         :
//                 (selector == 3'b100)                            ?   A|B         :
//                 (selector == 3'b101)                            ?   A^B         :
//                 (selector == 3'b110 && A[3]==1'b1 && B[3]==1'b0)?   4'b1111     :
//                 (selector == 3'b110 && A[3]==1'b0 && B[3]==1'b1)?   4'b0        :
//                 (selector == 3'b110 && A[2:0]<B[2:0])           ?   4'b1111     :
//                 (selector == 3'b110)                            ?   4'b0        :
//                 (selector == 3'b111 && A==B)                    ?   4'b1111     :
//                                                                     4'b0        ;

                                                      
// endmodule

/*******************             experiment 4           ****************/
// module top(
//     input clk,
//     input rst,
//     output reg [7:0] digital_led1,
//     output reg [7:0] digital_led2
// );
//     reg [7:0] num;

//     wire lin;

//     assign lin = num[0]^num[2]^num[3]^num[4];

//     always@(posedge clk or posedge rst)
//     begin
//         if(rst)
//             num<=8'b00000001;
//         else
//             num<={lin,num[7:1]};
//     end

//     always@(*)
//     begin
//         if     (num[3:0]==4'hf)digital_led1=8'b01110001;
//         else if(num[3:0]==4'he)digital_led1=8'b00100001;
//         else if(num[3:0]==4'hd)digital_led1=8'b10000101;
//         else if(num[3:0]==4'hc)digital_led1=8'b11100101;
//         else if(num[3:0]==4'hb)digital_led1=8'b11000001;
//         else if(num[3:0]==4'ha)digital_led1=8'b00010001;
//         else if(num[3:0]==4'h9)digital_led1=8'b00001001;
//         else if(num[3:0]==4'h8)digital_led1=8'b00000001;
//         else if(num[3:0]==4'h7)digital_led1=8'b00011111;
//         else if(num[3:0]==4'h6)digital_led1=8'b01000001;
//         else if(num[3:0]==4'h5)digital_led1=8'b01001001;
//         else if(num[3:0]==4'h4)digital_led1=8'b10011001;
//         else if(num[3:0]==4'h3)digital_led1=8'b00001101;
//         else if(num[3:0]==4'h2)digital_led1=8'b00100101;
//         else if(num[3:0]==4'h1)digital_led1=8'b10011111;
//         else if(num[3:0]==4'h0)digital_led1=8'b00000010;
//     end

    
    
    
//     always@(*)
//     begin
//         if     (num[7:4]==4'hf)digital_led2=8'b01110001;
//         else if(num[7:4]==4'he)digital_led2=8'b00100001;
//         else if(num[7:4]==4'hd)digital_led2=8'b10000101;
//         else if(num[7:4]==4'hc)digital_led2=8'b11100101;
//         else if(num[7:4]==4'hb)digital_led2=8'b11000001;
//         else if(num[7:4]==4'ha)digital_led2=8'b00010001;
//         else if(num[7:4]==4'h9)digital_led2=8'b00001001;
//         else if(num[7:4]==4'h8)digital_led2=8'b00000001;
//         else if(num[7:4]==4'h7)digital_led2=8'b00011111;
//         else if(num[7:4]==4'h6)digital_led2=8'b01000001;
//         else if(num[7:4]==4'h5)digital_led2=8'b01001001;
//         else if(num[7:4]==4'h4)digital_led2=8'b10011001;
//         else if(num[7:4]==4'h3)digital_led2=8'b00001101;
//         else if(num[7:4]==4'h2)digital_led2=8'b00100101;
//         else if(num[7:4]==4'h1)digital_led2=8'b10011111;
//         else if(num[7:4]==4'h0)digital_led2=8'b00000010;
//     end



// endmodule

/*******************             experiment 5           ****************/
module top(
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output reg [7:0] digital_led1,digital_led2,digital_led3,digital_led4,digital_led5,digital_led6

);

localparam IDLE=2'b00;

localparam VALID=2'b01;

localparam CANCEL=2'b10;

localparam WAIT=2'b11;


reg [1:0] state;
reg [1:0] next_state;


always@(posedge clk or posedge rst)
begin
    if(rst)
        state<=IDLE;
    else
        state<=next_state;
end

always@(*)
begin
    case(state)
    IDLE:
    if(ready)
        next_state=VALID;
    else  next_state=IDLE;
    VALID:
    if(ready&&(data==8'hF0))
        next_state=CANCEL;
    else next_state=VALID;
    CANCEL:
    if(ready)
        next_state=WAIT;
    else
        next_state=CANCEL;
    default:
    if(ready)
    next_state=VALID;
    else
    next_state=WAIT;
    
    endcase
end


wire ready;
wire nextdata_n;
assign nextdata_n=1'b0;
wire [7:0] data;
    ps2_keyboard inst_keyboard
                (   .clk     (clk),
                    .clrn    (!rst),
                    .ps2_clk (ps2_clk),
                    .ps2_data(ps2_data),
                    .data    (data),
                    .ready   (ready),
                    .nextdata_n(nextdata_n),
                    .overflow()
                    );

reg [7:0] data_r1;


always@(posedge clk or posedge rst)
begin
    if(rst)
    begin
        data_r1<='b0;

    end
    else
    begin
        if(ready)
        begin
            data_r1<=data;
        end
    end
end


reg [7:0] digital_led1_r,digital_led2_r,digital_led3_r,digital_led4_r;


    always@(*)
    begin
        if     (data_r1[3:0]==4'hf)digital_led1_r=8'b01110001;
        else if(data_r1[3:0]==4'he)digital_led1_r=8'b00100001;
        else if(data_r1[3:0]==4'hd)digital_led1_r=8'b10000101;
        else if(data_r1[3:0]==4'hc)digital_led1_r=8'b11100101;
        else if(data_r1[3:0]==4'hb)digital_led1_r=8'b11000001;
        else if(data_r1[3:0]==4'ha)digital_led1_r=8'b00010001;
        else if(data_r1[3:0]==4'h9)digital_led1_r=8'b00001001;
        else if(data_r1[3:0]==4'h8)digital_led1_r=8'b00000001;
        else if(data_r1[3:0]==4'h7)digital_led1_r=8'b00011111;
        else if(data_r1[3:0]==4'h6)digital_led1_r=8'b01000001;
        else if(data_r1[3:0]==4'h5)digital_led1_r=8'b01001001;
        else if(data_r1[3:0]==4'h4)digital_led1_r=8'b10011001;
        else if(data_r1[3:0]==4'h3)digital_led1_r=8'b00001101;
        else if(data_r1[3:0]==4'h2)digital_led1_r=8'b00100101;
        else if(data_r1[3:0]==4'h1)digital_led1_r=8'b10011111;
        else if(data_r1[3:0]==4'h0)digital_led1_r=8'b00000010;
    end



    always@(*)
    begin
        if     (data_r1[7:4]==4'hf)digital_led2_r=8'b01110001;
        else if(data_r1[7:4]==4'he)digital_led2_r=8'b00100001;
        else if(data_r1[7:4]==4'hd)digital_led2_r=8'b10000101;
        else if(data_r1[7:4]==4'hc)digital_led2_r=8'b11100101;
        else if(data_r1[7:4]==4'hb)digital_led2_r=8'b11000001;
        else if(data_r1[7:4]==4'ha)digital_led2_r=8'b00010001;
        else if(data_r1[7:4]==4'h9)digital_led2_r=8'b00001001;
        else if(data_r1[7:4]==4'h8)digital_led2_r=8'b00000001;
        else if(data_r1[7:4]==4'h7)digital_led2_r=8'b00011111;
        else if(data_r1[7:4]==4'h6)digital_led2_r=8'b01000001;
        else if(data_r1[7:4]==4'h5)digital_led2_r=8'b01001001;
        else if(data_r1[7:4]==4'h4)digital_led2_r=8'b10011001;
        else if(data_r1[7:4]==4'h3)digital_led2_r=8'b00001101;
        else if(data_r1[7:4]==4'h2)digital_led2_r=8'b00100101;
        else if(data_r1[7:4]==4'h1)digital_led2_r=8'b10011111;
        else if(data_r1[7:4]==4'h0)digital_led2_r=8'b00000010;
    end


        assign digital_led1=(state==VALID)?digital_led1_r:8'b11111111;
        assign digital_led2=(state==VALID)?digital_led2_r:8'b11111111;

    wire [7:0] ascii;

    assign ascii =  (data_r1==8'h16)?8'h31:
                    (data_r1==8'h1E)?8'h32:
                    (data_r1==8'h26)?8'h33:
                    (data_r1==8'h25)?8'h34:
                    (data_r1==8'h2E)?8'h35:
                    (data_r1==8'h36)?8'h36:
                    (data_r1==8'h3D)?8'h37:
                    (data_r1==8'h3E)?8'h38:
                    (data_r1==8'h46)?8'h39:
                    (data_r1==8'h45)?8'h30://
                    (data_r1==8'h1C)?8'h41:
                    (data_r1==8'h32)?8'h42:
                    (data_r1==8'h21)?8'h43:
                    (data_r1==8'h23)?8'h44:
                    (data_r1==8'h24)?8'h45:
                    (data_r1==8'h2B)?8'h46:
                    (data_r1==8'h34)?8'h47:
                    (data_r1==8'h33)?8'h48:
                    (data_r1==8'h43)?8'h49:
                    (data_r1==8'h3B)?8'h4A:
                    (data_r1==8'h42)?8'h4B:
                    (data_r1==8'h4B)?8'h4C:
                    (data_r1==8'h3A)?8'h4D:
                    (data_r1==8'h31)?8'h4E:
                    (data_r1==8'h44)?8'h4F:
                    (data_r1==8'h4D)?8'h50:
                    (data_r1==8'h15)?8'h51:
                    (data_r1==8'h2D)?8'h52:
                    (data_r1==8'h1B)?8'h53:
                    (data_r1==8'h2C)?8'h54:
                    (data_r1==8'h3C)?8'h55:
                    (data_r1==8'h2A)?8'h56:
                    (data_r1==8'h1D)?8'h57:
                    (data_r1==8'h22)?8'h58:
                    (data_r1==8'h35)?8'h59:
                    (data_r1==8'h1A)?8'h5A:
                                        8'h00;

    always@(*)
    begin
        if     (ascii[3:0]==4'hf)digital_led3_r=8'b01110001;
        else if(ascii[3:0]==4'he)digital_led3_r=8'b00100001;
        else if(ascii[3:0]==4'hd)digital_led3_r=8'b10000101;
        else if(ascii[3:0]==4'hc)digital_led3_r=8'b11100101;
        else if(ascii[3:0]==4'hb)digital_led3_r=8'b11000001;
        else if(ascii[3:0]==4'ha)digital_led3_r=8'b00010001;
        else if(ascii[3:0]==4'h9)digital_led3_r=8'b00001001;
        else if(ascii[3:0]==4'h8)digital_led3_r=8'b00000001;
        else if(ascii[3:0]==4'h7)digital_led3_r=8'b00011111;
        else if(ascii[3:0]==4'h6)digital_led3_r=8'b01000001;
        else if(ascii[3:0]==4'h5)digital_led3_r=8'b01001001;
        else if(ascii[3:0]==4'h4)digital_led3_r=8'b10011001;
        else if(ascii[3:0]==4'h3)digital_led3_r=8'b00001101;
        else if(ascii[3:0]==4'h2)digital_led3_r=8'b00100101;
        else if(ascii[3:0]==4'h1)digital_led3_r=8'b10011111;
        else                        digital_led3_r=8'b00000010;
    end


    always@(*)
    begin
        if     (ascii[7:4]==4'hf)digital_led4_r=8'b01110001;
        else if(ascii[7:4]==4'he)digital_led4_r=8'b00100001;
        else if(ascii[7:4]==4'hd)digital_led4_r=8'b10000101;
        else if(ascii[7:4]==4'hc)digital_led4_r=8'b11100101;
        else if(ascii[7:4]==4'hb)digital_led4_r=8'b11000001;
        else if(ascii[7:4]==4'ha)digital_led4_r=8'b00010001;
        else if(ascii[7:4]==4'h9)digital_led4_r=8'b00001001;
        else if(ascii[7:4]==4'h8)digital_led4_r=8'b00000001;
        else if(ascii[7:4]==4'h7)digital_led4_r=8'b00011111;
        else if(ascii[7:4]==4'h6)digital_led4_r=8'b01000001;
        else if(ascii[7:4]==4'h5)digital_led4_r=8'b01001001;
        else if(ascii[7:4]==4'h4)digital_led4_r=8'b10011001;
        else if(ascii[7:4]==4'h3)digital_led4_r=8'b00001101;
        else if(ascii[7:4]==4'h2)digital_led4_r=8'b00100101;
        else if(ascii[7:4]==4'h1)digital_led4_r=8'b10011111;
        else                        digital_led4_r=8'b00000010;
    end


        assign digital_led3=(state==VALID)?digital_led3_r:8'b11111111;
        assign digital_led4=(state==VALID)?digital_led4_r:8'b11111111;

    reg [7:0] count;

    always@(posedge clk or posedge rst)
    begin
        if(rst)
        count<='b0;
        else
        if( state!=VALID && next_state==VALID )
        count<=count+1'b1;
    end


    always@(*)
    begin
        if     (count[3:0]==4'hf)digital_led5=8'b01110001;
        else if(count[3:0]==4'he)digital_led5=8'b00100001;
        else if(count[3:0]==4'hd)digital_led5=8'b10000101;
        else if(count[3:0]==4'hc)digital_led5=8'b11100101;
        else if(count[3:0]==4'hb)digital_led5=8'b11000001;
        else if(count[3:0]==4'ha)digital_led5=8'b00010001;
        else if(count[3:0]==4'h9)digital_led5=8'b00001001;
        else if(count[3:0]==4'h8)digital_led5=8'b00000001;
        else if(count[3:0]==4'h7)digital_led5=8'b00011111;
        else if(count[3:0]==4'h6)digital_led5=8'b01000001;
        else if(count[3:0]==4'h5)digital_led5=8'b01001001;
        else if(count[3:0]==4'h4)digital_led5=8'b10011001;
        else if(count[3:0]==4'h3)digital_led5=8'b00001101;
        else if(count[3:0]==4'h2)digital_led5=8'b00100101;
        else if(count[3:0]==4'h1)digital_led5=8'b10011111;
        else if(count[3:0]==4'h0)digital_led5=8'b00000010;
    end


    always@(*)
    begin
        if     (count[7:4]==4'hf)digital_led6=8'b01110001;
        else if(count[7:4]==4'he)digital_led6=8'b00100001;
        else if(count[7:4]==4'hd)digital_led6=8'b10000101;
        else if(count[7:4]==4'hc)digital_led6=8'b11100101;
        else if(count[7:4]==4'hb)digital_led6=8'b11000001;
        else if(count[7:4]==4'ha)digital_led6=8'b00010001;
        else if(count[7:4]==4'h9)digital_led6=8'b00001001;
        else if(count[7:4]==4'h8)digital_led6=8'b00000001;
        else if(count[7:4]==4'h7)digital_led6=8'b00011111;
        else if(count[7:4]==4'h6)digital_led6=8'b01000001;
        else if(count[7:4]==4'h5)digital_led6=8'b01001001;
        else if(count[7:4]==4'h4)digital_led6=8'b10011001;
        else if(count[7:4]==4'h3)digital_led6=8'b00001101;
        else if(count[7:4]==4'h2)digital_led6=8'b00100101;
        else if(count[7:4]==4'h1)digital_led6=8'b10011111;
        else if(count[7:4]==4'h0)digital_led6=8'b00000010;
    end




endmodule
