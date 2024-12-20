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
    localparam IDLE         = 4'd0;
    localparam IFU_AR       = 4'd1;
    localparam IFU_R        = 4'd2;
    localparam EXEU         = 4'd3;
    localparam LSU_AW       = 4'd4;
    localparam LSU_W        = 4'd5;
    localparam LSU_AW_2S    = 4'd6;
    localparam LSU_W_2S     = 4'd7;
    localparam LSU_AR       = 4'd8;
    localparam LSU_R        = 4'd9;
    localparam LSU_AR_2S    = 4'd10;
    localparam LSU_R_2S     = 4'd11;


    reg [3:0] state,next_state;

    wire read_mem ,write_mem;

    assign read_mem = (mem_raddr>=32'hf000000 & mem_raddr<=32'hfffffff) || (mem_raddr>=32'h20000000 & mem_raddr<=32'h20000fff) || (mem_raddr>=32'h10000000 & mem_raddr<=32'h10000fff) || (mem_raddr>=32'h80000000 & mem_raddr<=32'h9fffffff) || (mem_raddr>=32'h30000000 & mem_raddr<=32'h3fffffff) || (mem_raddr>=32'ha0000000 & mem_raddr<=32'ha1e84800);

    assign write_mem = (mem_waddr>=32'hf000000 & mem_waddr<=32'hfffffff) || (mem_waddr>=32'h10000000 & mem_waddr<=32'h10000fff) || (mem_waddr>=32'h80000000 & mem_waddr<=32'h9fffffff) || (mem_waddr>=32'ha0000000 & mem_waddr<=32'ha1e84800);

    reg need_2s;
    
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
                    if(need_2s) begin
                        next_state = LSU_AW_2S;
                    end
                    else begin
                        next_state = IFU_AR;
                    end
                end

                else begin
                    next_state = LSU_W;
                end
            end

            LSU_AW_2S: begin
                if(io_master_awvalid & io_master_awready) begin
                    next_state = LSU_W_2S;
                end
                
                else begin
                    next_state = LSU_AW_2S;
                end
            end

            LSU_W_2S: begin
                if(io_master_wvalid & io_master_wready) begin
                    next_state = IFU_AR;
                end

                else begin
                    next_state = LSU_W_2S;
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
                    if(need_2s) begin
                        next_state = LSU_AR_2S;
                    end
                    else begin
                        next_state = IFU_AR;
                    end
                end

                else begin
                    next_state = LSU_R;
                end
            end

            LSU_AR_2S: begin
                if(io_master_arvalid & io_master_arready) begin
                    next_state = LSU_R_2S;
                end

                else begin
                    next_state = LSU_AR_2S;
                end
            end

            LSU_R_2S: begin
                if(io_master_rvalid & io_master_rready) begin
                    next_state = IFU_AR;
                end

                else begin
                    next_state = LSU_R_2S;
                end
            end

            default:
                next_state = IDLE;

        
        endcase
    end


    assign io_master_awvalid = ( state == LSU_AW ) || ( state == LSU_AW_2S );

    assign io_master_wvalid = ( state == LSU_W ) || ( state == LSU_W_2S );

    assign io_master_arvalid = ( state == IFU_AR || state == LSU_AR || state == LSU_AR_2S );

    assign io_master_rready = ( state == IFU_R || state == LSU_R || state == LSU_R_2S ); 

    assign io_master_awaddr = write_mem & state==LSU_AW ? {mem_waddr[31:2],2'b0} :
                              write_mem & state==LSU_AW_2S ? {mem_waddr[31:2]+1'b1,2'b0} :
                              mem_waddr ;

    assign io_master_awid = 'b0;

    assign io_master_awlen = 8'b0;

    assign io_master_awsize = 3'b010;

    assign io_master_awburst = 2'b01;

    assign io_master_wdata =!write_mem ? mem_wdata : 
                            state==LSU_W & mem_waddr[1:0]==2'd0 ? mem_wdata :
                            state==LSU_W & mem_waddr[1:0]==2'd1 ? {mem_wdata[23:0],8'b0} :
                            state==LSU_W & mem_waddr[1:0]==2'd2 ? {mem_wdata[15:0],16'b0} :
                            state==LSU_W & mem_waddr[1:0]==2'd3 ? {mem_wdata[7:0],24'b0} : 
                            state==LSU_W_2S & mem_waddr[1:0]==2'd1 ? {24'b0,mem_wdata[31:24]} :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd2 ? {16'b0,mem_wdata[31:16]} :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd3 ? {8'b0,mem_wdata[31:8]} :
                            'b0;

    assign io_master_wstrb =!write_mem ? mem_wmask :
                            state==LSU_W & mem_waddr[1:0]==2'd0 ? mem_wmask :
                            state==LSU_W & mem_waddr[1:0]==2'd1 ? mem_wmask<<1'b1 :
                            state==LSU_W & mem_waddr[1:0]==2'd2 ? mem_wmask<<2'd2 :
                            state==LSU_W & mem_waddr[1:0]==2'd3 ? mem_wmask<<2'd3 :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd1 ? 4'b1 :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd2 ? 4'b11 :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd3 & mem_wmask==4'b11 ? 4'b1 :
                            state==LSU_W_2S & mem_waddr[1:0]==2'd3 & mem_wmask==4'b1111 ? 4'b111 : 4'b0;

    assign io_master_wlast = ( state == LSU_W ) || ( state == LSU_W_2S );

    assign io_master_bready = 1'b1;

    assign io_master_araddr = ( state == IFU_AR ) ? pc : 
                                state==LSU_AR & read_mem ? {mem_raddr[31:2],2'b0} :
                                state==LSU_AR_2S & read_mem ? {mem_raddr[31:2] + 1'b1,2'b0} :
                                mem_raddr ;

    assign io_master_arid = 'b0;

    assign io_master_arlen = 'b0;

    assign io_master_arsize = 3'b010;

    always@(posedge clock) begin
        if(state==LSU_AW) begin
            need_2s <= write_mem & ((mem_waddr[1:0]==2'd1 & mem_wmask==4'b1111) || (mem_waddr[1:0]==2'd2 & mem_wmask[3:2]!=2'b0) || (mem_waddr[1:0]==2'd3 & mem_wmask[3:1]!=3'b0));
        end

        else if(state==LSU_AR) begin
            need_2s <= read_mem & ((mem_raddr[1:0]==2'd1 & mem_rmask==4'b1111) || (mem_raddr[1:0]==2'd2 & mem_rmask[3:2]!=2'b0) || (mem_raddr[1:0]==2'd3 & mem_rmask[3:1]!=3'b0));
        end

        else if(state==EXEU) begin
            need_2s <= 'b0;
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

    reg [31:0] rdata_mem_mid;

    always@(clock) begin
        if(state==LSU_R) begin
            if(io_master_rvalid & io_master_rready) begin
                rdata_mem_mid <= io_master_rdata;
            end
        end
    end

    assign rdata_mem = ( state == IFU_AR ) ? io_master_rdata :
                        !read_mem            ? io_master_rdata :
                        state == LSU_R & mem_raddr[1:0]==2'd0 ? io_master_rdata :
                        state == LSU_R & mem_raddr[1:0]==2'd1 ? {8'b0,io_master_rdata[31:8]} :
                        state == LSU_R & mem_raddr[1:0]==2'd2 ? {16'b0,io_master_rdata[31:16]} :
                        state == LSU_R & mem_raddr[1:0]==2'd3 ? {24'b0,io_master_rdata[31:24]} :
                        state == LSU_R_2S & mem_raddr[1:0]==2'd1 ? {io_master_rdata[7:0],rdata_mem_mid[31:8]} :
                        state == LSU_R_2S & mem_raddr[1:0]==2'd2 ? {io_master_rdata[15:0],rdata_mem_mid[31:16]} :
                        state == LSU_R_2S & mem_raddr[1:0]==2'd3 ? {io_master_rdata[23:0],rdata_mem_mid[31:24]} :
                        'b0;

    assign mem_rdone = state == EXEU ? !mem_ren :
                       state == LSU_R & !need_2s ? io_master_rvalid & io_master_rready :
                       state == LSU_R_2S         ? io_master_rvalid & io_master_rready :
                                'b0;

    wire addr_debug_axi_w,addr_debug_axi_r;

    assign addr_debug_axi_w = io_master_awaddr == 32'ha0005b48 & io_master_awvalid & io_master_awready;

    assign addr_debug_axi_r = io_master_araddr == 32'ha0005b48 & io_master_arvalid & io_master_arready;

endmodule
