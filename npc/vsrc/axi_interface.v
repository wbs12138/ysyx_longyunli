module axi_interface (
    input           clock             ,
    input           reset             ,
    input           io_master_awready ,
    output          io_master_awvalid ,
    output  [31:0]  io_master_awaddr  ,
    output  [3:0]   io_master_awid    ,
    output  [7:0]   io_master_awlen   ,
    output  [2:0]   io_master_awsize  ,
    output  [1:0]   io_master_awburst ,
    input           io_master_wready  ,
    output          io_master_wvalid  ,
    output  [31:0]  io_master_wdata   ,
    output  [3:0]   io_master_wstrb   ,
    output          io_master_wlast   ,
    output          io_master_bready  ,
    input           io_master_bvalid  ,
    input   [1:0]   io_master_bresp   ,
    input   [3:0]   io_master_bid     ,
    input           io_master_arready ,
    output          io_master_arvalid ,
    output  [31:0]  io_master_araddr  ,
    output  [3:0]   io_master_arid    ,
    output  [7:0]   io_master_arlen   ,
    output  [2:0]   io_master_arsize  ,
    output  [1:0]   io_master_arburst ,
    output          io_master_rready  ,
    input           io_master_rvalid  ,
    input   [1:0]   io_master_rresp   ,
    input   [31:0]  io_master_rdata   ,
    input           io_master_rlast   ,
    input   [3:0]   io_master_rid     ,
    input   [31:0]  pc                ,
    output  reg [31:0]  ist               ,
    input           mem_wen           ,
    input   [31:0]  mem_waddr         ,
    input   [31:0]  mem_wdata         ,
    input   [3:0]   mem_wmask         ,
    input           mem_ren           ,
    output  [31:0]  rdata_mem         ,
    input   [31:0]  mem_raddr         ,
    output          mem_rdone         ,
    input   [3:0]   mem_rmask
);
    localparam IDLE   = 3'd0;
    localparam IFU_AR = 3'd1;
    localparam IFU_R  = 3'd2;
    localparam EXEU   = 3'd3;
    localparam LSU_AW = 3'd4;
    localparam LSU_W  = 3'd5;
    localparam LSU_AR = 3'd6;
    localparam LSU_R  = 3'd7;

    reg [2:0] state,next_state;

    always@(posedge clock) begin
        if(reset) begin
            state <= IDLE;
        end

        else begin
            state <= next_state;
        end
    end


    always@(*) begin
        case(state) 
            
            IDLE: begin
                next_state = IFU_AR;
            end

            IFU_AR: begin
                if(io_master_arvalid & io_master_arready) begin
                    next_state = IFU_R;
                end

                else begin
                    next_state = IFU_AR;
                end
            end

            IFU_R: begin
                if(io_master_rready & io_master_rvalid) begin
                    next_state = EXEU;
                end
                else begin
                    next_state = IFU_R;
                end
            end

            EXEU: begin
                if( mem_wen ) begin
                    next_state = LSU_AW;
                end

                else if(mem_ren) begin
                    next_state = LSU_AR;
                end

                else begin
                    next_state = IFU_AR;
                end
            end

            LSU_AW: begin
                if(io_master_awvalid & io_master_awready) begin
                    next_state = LSU_W;
                end
                
                else begin
                    next_state = LSU_AW;
                end
            end

            LSU_W: begin
                if(io_master_wvalid & io_master_wready) begin
                    next_state = IFU_AR;
                end

                else begin
                    next_state = LSU_W;
                end
            end

            LSU_AR: begin
                if(io_master_arvalid & io_master_arready) begin
                    next_state = LSU_R;
                end

                else begin
                    next_state = LSU_AR;
                end
            end

            LSU_R: begin
                if(io_master_rvalid & io_master_rready) begin
                    next_state = IFU_AR;
                end

                else begin
                    next_state = LSU_R;
                end
            end

            default:
                next_state = IDLE;

        
        endcase
    end


    assign io_master_awvalid = ( state == LSU_AW );

    assign io_master_wvalid = ( state == LSU_W );

    assign io_master_arvalid = ( state == IFU_AR || state == LSU_AR );

    assign io_master_rready = ( state == IFU_R || state == LSU_R ); 

    assign io_master_awaddr = mem_waddr ;

    assign io_master_awid = 'b0;

    assign io_master_awlen = 'b0;

    assign io_master_awsize = 3'd1;

    assign io_master_awburst = 2'b01;

    assign io_master_wdata = mem_wdata;

    assign io_master_wstrb = mem_wmask;

    assign io_master_wlast = ( state == LSU_W );

    assign io_master_bready = 1'b1;

    assign io_master_araddr = ( state == IFU_AR ) ? pc : mem_raddr;

    assign io_master_arid = 'b0;

    assign io_master_arlen = 'b0;

    assign io_master_arsize = ( state == IFU_AR )   ?   3'd3 : 
                                mem_rmask == 4'b1   ?   3'd0 :
                                mem_rmask == 4'b11  ?   3'd1 :
                                3'd3;

    assign io_master_arburst = 2'b01;

    always@(posedge clock) begin
        if(reset) begin
            ist <= 'b0;
        end
        else begin
            if(state == IFU_R & io_master_rvalid & io_master_rready) begin
                ist <= io_master_rdata;
            end
        end
    end

    assign rdata_mem = io_master_rdata ;

    assign mem_rdone = state == EXEU ? !mem_ren :
                       state == LSU_R? io_master_rvalid & io_master_rready :
                                'b0;

endmodule
