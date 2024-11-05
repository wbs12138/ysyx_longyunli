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
    input   [31:0]  npc               ,
    output  reg [31:0]  ist           ,
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

    wire read_mem ,write_mem;

    assign read_mem = (mem_raddr>=32'hf000000 & mem_raddr<=32'hfffffff) || (mem_raddr>=32'h20000000 & mem_raddr<=32'h20000fff) || (mem_raddr>=32'h10000000 & mem_raddr<=32'h10000fff);

    assign write_mem = (mem_waddr>=32'hf000000 & mem_waddr<=32'hfffffff);

    import "DPI-C" function void state_is_exeu(input int npc_state);

    import "DPI-C" function void state_is_ifuar(input int npc_state);

    import "DPI-C" function void state_is_ifur(input int npc_state);

    import "DPI-C" function void get_inst(input int inst);

    import "DPI-C" function void get_pc(input int dnpc);
    
    import "DPI-C" function void memory_access(input int npc_state_lsuaw, input int npc_state_lsuar,input int npc_aw_addr,input int npc_aw_len,input int npc_aw_data,input int npc_ar_addr,input int npc_ar_len);

    wire state_exeu,state_ifuar,state_ifur;

    wire state_lsuaw,state_lsuar;

    wire [31:0] state_lsuaw_t,state_lsuar_t;

    wire [31:0] state_exeu_t,state_ifuar_t,state_ifur_t;

    wire [31:0] wlen,rlen;

    assign wlen =   mem_wmask == 4'b0001 ? 32'b1 :
                    mem_wmask == 4'b0011 ? 32'd2 :
                    mem_wmask == 4'b1111 ? 32'd4 :
                    'b0;

    assign rlen =   mem_rmask == 4'b0001 ? 32'b1 :
                    mem_rmask == 4'b0011 ? 32'd2 :
                    mem_rmask == 4'b1111 ? 32'd4 :
                    'b0;

    assign state_exeu = state == EXEU;
    assign state_ifuar = state == IFU_AR;
    assign state_ifur = state == IFU_R;

    assign state_lsuaw = state == LSU_AW;
    assign state_lsuar = state == LSU_AR;

    assign state_exeu_t = {31'b0,state_exeu};
    assign state_ifuar_t = {31'b0,state_ifuar};
    assign state_ifur_t = {31'b0,state_ifur};

    assign state_lsuar_t = {31'b0,state_lsuar};
    assign state_lsuaw_t = {31'b0,state_lsuaw};


    always@(*)
    begin
        state_is_exeu(state_exeu_t);
        state_is_ifuar(state_ifuar_t);
        state_is_ifur(state_ifur_t);
        get_inst(ist);
        get_pc(npc);
        memory_access(state_lsuaw_t,state_lsuar_t,mem_waddr,wlen,mem_wdata,mem_raddr,rlen);
    end


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

    assign io_master_awaddr = write_mem ? {mem_waddr[31:2],2'b0} : mem_waddr ;

    assign io_master_awid = 'b0;

    assign io_master_awlen = 8'b0;

    assign io_master_awsize = 3'b010;

    assign io_master_awburst = 2'b01;

    assign io_master_wdata =!write_mem ? mem_wdata : 
                            mem_waddr[1:0]==2'd0 ? mem_wdata :
                            mem_waddr[1:0]==2'd1 ? {mem_wdata[23:0],8'b0} :
                            mem_waddr[1:0]==2'd2 ? {mem_wdata[15:0],16'b0} :
                            mem_waddr[1:0]==2'd3 ? {mem_wdata[7:0],24'b0} : 'b0;

    assign io_master_wstrb =!write_mem ? mem_wmask :
                            mem_waddr[1:0]==2'd0 ? mem_wmask :
                            mem_waddr[1:0]==2'd1 ? mem_wmask<<1'b1 :
                            mem_waddr[1:0]==2'd2 ? mem_wmask<<2'd2 :
                            mem_waddr[1:0]==2'd3 ? mem_wmask<<2'd3 : 'b0;

    assign io_master_wlast = ( state == LSU_W );

    assign io_master_bready = 1'b1;

    assign io_master_araddr = ( state == IFU_AR ) ? pc : 
                                read_mem ? {mem_raddr[31:2],2'b0} :
                                mem_raddr ;

    assign io_master_arid = 'b0;

    assign io_master_arlen = 'b0;

    assign io_master_arsize = ( state == IFU_AR )   ?   3'b010 : 
                                mem_rmask == 4'b1   ?   3'b000 :
                                mem_rmask == 4'b11  ?   3'b001 :
                                3'b010;

    always@(*) begin
        if(state == LSU_AW) begin
            assert( (mem_waddr[1:0]==2'd0) || (mem_waddr[1:0]==2'd1 & mem_wmask!=4'b1111) || (mem_waddr[1:0]==2'd2 & mem_wmask!=4'b1111) || (mem_waddr[1:0]==2'd3 & mem_wmask==4'b1));
        end
    end

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

    assign rdata_mem = ( state == IFU_AR ) ? io_master_rdata :
                        !read_mem            ? io_master_rdata :
                        mem_raddr[1:0]==2'd0 ? io_master_rdata :
                        mem_raddr[1:0]==2'd1 ? {8'b0,io_master_rdata[31:8]} :
                        mem_raddr[1:0]==2'd2 ? {16'b0,io_master_rdata[31:16]} :
                        mem_raddr[1:0]==2'd3 ? {24'b0,io_master_rdata[31:24]} :
                        'b0;

    always@(*) begin
        if(state == LSU_AR) begin
            assert( (mem_raddr[1:0]==2'd0) || (mem_raddr[1:0]==2'd1 & mem_rmask!=4'b1111) || (mem_raddr[1:0]==2'd2 & mem_rmask!=4'b1111) || (mem_raddr[1:0]==2'd3 & mem_rmask==4'b1));
        end
    end

    assign mem_rdone = state == EXEU ? !mem_ren :
                       state == LSU_R? io_master_rvalid & io_master_rready :
                                'b0;

endmodule
