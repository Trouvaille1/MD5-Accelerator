// ==============================================================
// Generated by Vitis HLS v2023.1
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

module md5_wrap_md5_final_1_Pipeline_VITIS_LOOP_172_3 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        m_axi_gmem_AWVALID,
        m_axi_gmem_AWREADY,
        m_axi_gmem_AWADDR,
        m_axi_gmem_AWID,
        m_axi_gmem_AWLEN,
        m_axi_gmem_AWSIZE,
        m_axi_gmem_AWBURST,
        m_axi_gmem_AWLOCK,
        m_axi_gmem_AWCACHE,
        m_axi_gmem_AWPROT,
        m_axi_gmem_AWQOS,
        m_axi_gmem_AWREGION,
        m_axi_gmem_AWUSER,
        m_axi_gmem_WVALID,
        m_axi_gmem_WREADY,
        m_axi_gmem_WDATA,
        m_axi_gmem_WSTRB,
        m_axi_gmem_WLAST,
        m_axi_gmem_WID,
        m_axi_gmem_WUSER,
        m_axi_gmem_ARVALID,
        m_axi_gmem_ARREADY,
        m_axi_gmem_ARADDR,
        m_axi_gmem_ARID,
        m_axi_gmem_ARLEN,
        m_axi_gmem_ARSIZE,
        m_axi_gmem_ARBURST,
        m_axi_gmem_ARLOCK,
        m_axi_gmem_ARCACHE,
        m_axi_gmem_ARPROT,
        m_axi_gmem_ARQOS,
        m_axi_gmem_ARREGION,
        m_axi_gmem_ARUSER,
        m_axi_gmem_RVALID,
        m_axi_gmem_RREADY,
        m_axi_gmem_RDATA,
        m_axi_gmem_RLAST,
        m_axi_gmem_RID,
        m_axi_gmem_RFIFONUM,
        m_axi_gmem_RUSER,
        m_axi_gmem_RRESP,
        m_axi_gmem_BVALID,
        m_axi_gmem_BREADY,
        m_axi_gmem_BRESP,
        m_axi_gmem_BID,
        m_axi_gmem_BUSER,
        ctx_state_0_ret1,
        hash,
        ctx_state_1_ret1,
        ctx_state_2_ret1,
        ctx_state_3_ret1
);

parameter    ap_ST_fsm_pp0_stage0 = 4'd1;
parameter    ap_ST_fsm_pp0_stage1 = 4'd2;
parameter    ap_ST_fsm_pp0_stage2 = 4'd4;
parameter    ap_ST_fsm_pp0_stage3 = 4'd8;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output   m_axi_gmem_AWVALID;
input   m_axi_gmem_AWREADY;
output  [63:0] m_axi_gmem_AWADDR;
output  [0:0] m_axi_gmem_AWID;
output  [31:0] m_axi_gmem_AWLEN;
output  [2:0] m_axi_gmem_AWSIZE;
output  [1:0] m_axi_gmem_AWBURST;
output  [1:0] m_axi_gmem_AWLOCK;
output  [3:0] m_axi_gmem_AWCACHE;
output  [2:0] m_axi_gmem_AWPROT;
output  [3:0] m_axi_gmem_AWQOS;
output  [3:0] m_axi_gmem_AWREGION;
output  [0:0] m_axi_gmem_AWUSER;
output   m_axi_gmem_WVALID;
input   m_axi_gmem_WREADY;
output  [7:0] m_axi_gmem_WDATA;
output  [0:0] m_axi_gmem_WSTRB;
output   m_axi_gmem_WLAST;
output  [0:0] m_axi_gmem_WID;
output  [0:0] m_axi_gmem_WUSER;
output   m_axi_gmem_ARVALID;
input   m_axi_gmem_ARREADY;
output  [63:0] m_axi_gmem_ARADDR;
output  [0:0] m_axi_gmem_ARID;
output  [31:0] m_axi_gmem_ARLEN;
output  [2:0] m_axi_gmem_ARSIZE;
output  [1:0] m_axi_gmem_ARBURST;
output  [1:0] m_axi_gmem_ARLOCK;
output  [3:0] m_axi_gmem_ARCACHE;
output  [2:0] m_axi_gmem_ARPROT;
output  [3:0] m_axi_gmem_ARQOS;
output  [3:0] m_axi_gmem_ARREGION;
output  [0:0] m_axi_gmem_ARUSER;
input   m_axi_gmem_RVALID;
output   m_axi_gmem_RREADY;
input  [7:0] m_axi_gmem_RDATA;
input   m_axi_gmem_RLAST;
input  [0:0] m_axi_gmem_RID;
input  [10:0] m_axi_gmem_RFIFONUM;
input  [0:0] m_axi_gmem_RUSER;
input  [1:0] m_axi_gmem_RRESP;
input   m_axi_gmem_BVALID;
output   m_axi_gmem_BREADY;
input  [1:0] m_axi_gmem_BRESP;
input  [0:0] m_axi_gmem_BID;
input  [0:0] m_axi_gmem_BUSER;
input  [31:0] ctx_state_0_ret1;
input  [63:0] hash;
input  [31:0] ctx_state_1_ret1;
input  [31:0] ctx_state_2_ret1;
input  [31:0] ctx_state_3_ret1;

reg ap_idle;
reg m_axi_gmem_AWVALID;
reg[63:0] m_axi_gmem_AWADDR;
reg m_axi_gmem_WVALID;
reg[7:0] m_axi_gmem_WDATA;
reg m_axi_gmem_BREADY;

(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
reg    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_idle_pp0;
wire    ap_CS_fsm_pp0_stage3;
wire    ap_block_state4_pp0_stage3_iter0;
reg   [0:0] icmp_ln172_reg_351;
reg    ap_block_state4_io;
reg    ap_block_state8_pp0_stage3_iter1;
reg    ap_block_pp0_stage3_subdone;
reg    ap_condition_exit_pp0_iter0_stage3;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
reg    gmem_blk_n_AW;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_pp0_stage1;
reg    gmem_blk_n_W;
wire    ap_CS_fsm_pp0_stage2;
wire    ap_block_pp0_stage2;
reg    gmem_blk_n_B;
wire    ap_block_pp0_stage3;
wire    ap_block_pp0_stage0;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state5_pp0_stage0_iter1;
reg    ap_block_state5_io;
reg    ap_block_state9_pp0_stage0_iter2;
reg    ap_block_pp0_stage0_11001;
reg   [2:0] i_3_reg_344;
wire   [0:0] icmp_ln172_fu_172_p2;
reg   [0:0] icmp_ln172_reg_351_pp0_iter1_reg;
wire   [31:0] zext_ln173_fu_194_p1;
reg   [31:0] zext_ln173_reg_355;
wire   [7:0] trunc_ln173_1_fu_204_p1;
reg   [7:0] trunc_ln173_1_reg_362;
reg   [63:0] gmem_addr_reg_367;
wire   [7:0] trunc_ln174_fu_229_p1;
reg   [7:0] trunc_ln174_reg_373;
wire    ap_block_state2_pp0_stage1_iter0;
reg    ap_block_state2_io;
wire    ap_block_state6_pp0_stage1_iter1;
reg    ap_block_state10_pp0_stage1_iter2;
reg    ap_block_pp0_stage1_11001;
reg   [63:0] gmem_addr_1_reg_378;
reg   [63:0] gmem_addr_2_reg_384;
reg   [63:0] gmem_addr_3_reg_390;
wire   [7:0] trunc_ln175_fu_303_p1;
reg   [7:0] trunc_ln175_reg_396;
wire    ap_block_state3_pp0_stage2_iter0;
reg    ap_block_state3_io;
wire    ap_block_state7_pp0_stage2_iter1;
reg    ap_block_state11_pp0_stage2_iter2;
reg    ap_block_pp0_stage2_11001;
wire   [7:0] trunc_ln176_fu_311_p1;
reg   [7:0] trunc_ln176_reg_401;
reg    ap_block_pp0_stage3_11001;
reg    ap_enable_reg_pp0_iter0_reg;
reg    ap_block_pp0_stage2_subdone;
wire   [63:0] add_ln173_fu_208_p2;
wire   [63:0] add_ln174_fu_242_p2;
wire   [63:0] add_ln175_fu_264_p2;
wire   [63:0] add_ln176_fu_283_p2;
reg    ap_block_pp0_stage2_01001;
reg    ap_block_pp0_stage3_01001;
reg    ap_block_pp0_stage0_01001;
reg    ap_block_pp0_stage1_01001;
reg   [2:0] i_fu_66;
wire   [2:0] i_4_fu_220_p2;
wire    ap_loop_init;
reg   [2:0] ap_sig_allocacmp_i_3;
wire   [1:0] trunc_ln173_fu_182_p1;
wire   [4:0] shl_ln1_fu_186_p3;
wire   [31:0] lshr_ln173_fu_198_p2;
wire   [63:0] i_7_cast9_fu_178_p1;
wire   [31:0] lshr_ln174_fu_225_p2;
wire  signed [2:0] xor_ln174_fu_233_p2;
wire   [63:0] zext_ln174_fu_238_p1;
wire   [3:0] zext_ln175_cast_fu_253_p3;
wire   [63:0] zext_ln175_fu_260_p1;
wire  signed [3:0] sext_ln176_fu_275_p1;
wire   [63:0] zext_ln176_fu_279_p1;
wire   [31:0] lshr_ln175_fu_299_p2;
wire   [31:0] lshr_ln176_fu_307_p2;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg    ap_loop_exit_ready_pp0_iter1_reg;
reg    ap_condition_exit_pp0_iter1_stage2;
reg    ap_idle_pp0_0to0;
reg   [3:0] ap_NS_fsm;
reg    ap_block_pp0_stage0_subdone;
reg    ap_idle_pp0_1to2;
reg    ap_block_pp0_stage1_subdone;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 4'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter0_reg = 1'b0;
#0 ap_done_reg = 1'b0;
end

md5_wrap_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage3),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((ap_loop_exit_ready_pp0_iter1_reg == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
            ap_enable_reg_pp0_iter0_reg <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter0_stage3)) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if (((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
            ap_enable_reg_pp0_iter2 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((ap_idle_pp0_0to0 == 1'b1) & (1'b1 == ap_condition_exit_pp0_iter1_stage2))) begin
        ap_loop_exit_ready_pp0_iter1_reg <= 1'b0;
    end else if (((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001))) begin
        ap_loop_exit_ready_pp0_iter1_reg <= ap_loop_exit_ready;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_fu_66 <= 3'd0;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        i_fu_66 <= i_4_fu_220_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln172_reg_351 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        gmem_addr_1_reg_378 <= add_ln174_fu_242_p2;
        gmem_addr_2_reg_384 <= add_ln175_fu_264_p2;
        gmem_addr_3_reg_390 <= add_ln176_fu_283_p2;
        trunc_ln174_reg_373 <= trunc_ln174_fu_229_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln172_fu_172_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        gmem_addr_reg_367 <= add_ln173_fu_208_p2;
        trunc_ln173_1_reg_362 <= trunc_ln173_1_fu_204_p1;
        zext_ln173_reg_355[4 : 3] <= zext_ln173_fu_194_p1[4 : 3];
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_3_reg_344 <= ap_sig_allocacmp_i_3;
        icmp_ln172_reg_351 <= icmp_ln172_fu_172_p2;
        icmp_ln172_reg_351_pp0_iter1_reg <= icmp_ln172_reg_351;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln172_reg_351 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001))) begin
        trunc_ln175_reg_396 <= trunc_ln175_fu_303_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln172_reg_351 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001))) begin
        trunc_ln176_reg_401 <= trunc_ln176_fu_311_p1;
    end
end

always @ (*) begin
    if (((icmp_ln172_reg_351 == 1'd1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
        ap_condition_exit_pp0_iter0_stage3 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage3 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (icmp_ln172_reg_351_pp0_iter1_reg == 1'd1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
        ap_condition_exit_pp0_iter1_stage2 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter1_stage2 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_exit_ready_pp0_iter1_reg == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
        ap_enable_reg_pp0_iter0 = ap_start_int;
    end else begin
        ap_enable_reg_pp0_iter0 = ap_enable_reg_pp0_iter0_reg;
    end
end

always @ (*) begin
    if (((ap_start_int == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if ((ap_enable_reg_pp0_iter0 == 1'b0)) begin
        ap_idle_pp0_0to0 = 1'b1;
    end else begin
        ap_idle_pp0_0to0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0))) begin
        ap_idle_pp0_1to2 = 1'b1;
    end else begin
        ap_idle_pp0_1to2 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0))) begin
        ap_sig_allocacmp_i_3 = 3'd0;
    end else begin
        ap_sig_allocacmp_i_3 = i_fu_66;
    end
end

always @ (*) begin
    if ((((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0)))) begin
        gmem_blk_n_AW = m_axi_gmem_AWREADY;
    end else begin
        gmem_blk_n_AW = 1'b1;
    end
end

always @ (*) begin
    if ((((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3)))) begin
        gmem_blk_n_B = m_axi_gmem_BVALID;
    end else begin
        gmem_blk_n_B = 1'b1;
    end
end

always @ (*) begin
    if ((((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1)))) begin
        gmem_blk_n_W = m_axi_gmem_WREADY;
    end else begin
        gmem_blk_n_W = 1'b1;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        m_axi_gmem_AWADDR = gmem_addr_3_reg_390;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001))) begin
        m_axi_gmem_AWADDR = gmem_addr_2_reg_384;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001))) begin
        m_axi_gmem_AWADDR = gmem_addr_1_reg_378;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        m_axi_gmem_AWADDR = gmem_addr_reg_367;
    end else begin
        m_axi_gmem_AWADDR = 'bx;
    end
end

always @ (*) begin
    if ((((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)))) begin
        m_axi_gmem_AWVALID = 1'b1;
    end else begin
        m_axi_gmem_AWVALID = 1'b0;
    end
end

always @ (*) begin
    if ((((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001)))) begin
        m_axi_gmem_BREADY = 1'b1;
    end else begin
        m_axi_gmem_BREADY = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_01001))) begin
        m_axi_gmem_WDATA = trunc_ln176_reg_401;
    end else if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_01001))) begin
        m_axi_gmem_WDATA = trunc_ln175_reg_396;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_01001))) begin
        m_axi_gmem_WDATA = trunc_ln174_reg_373;
    end else if (((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_01001))) begin
        m_axi_gmem_WDATA = trunc_ln173_1_reg_362;
    end else begin
        m_axi_gmem_WDATA = 'bx;
    end
end

always @ (*) begin
    if ((((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001)) | ((icmp_ln172_reg_351 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)))) begin
        m_axi_gmem_WVALID = 1'b1;
    end else begin
        m_axi_gmem_WVALID = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_start_int == 1'b0) & (ap_idle_pp0_1to2 == 1'b1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_pp0_stage2 : begin
            if (((ap_idle_pp0_0to0 == 1'b1) & (1'b1 == ap_condition_exit_pp0_iter1_stage2))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else if ((1'b0 == ap_block_pp0_stage2_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end
        end
        ap_ST_fsm_pp0_stage3 : begin
            if ((1'b0 == ap_block_pp0_stage3_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln173_fu_208_p2 = (i_7_cast9_fu_178_p1 + hash);

assign add_ln174_fu_242_p2 = (zext_ln174_fu_238_p1 + hash);

assign add_ln175_fu_264_p2 = (zext_ln175_fu_260_p1 + hash);

assign add_ln176_fu_283_p2 = (zext_ln176_fu_279_p1 + hash);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_pp0_stage2 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_pp0_stage3 = ap_CS_fsm[32'd3];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_01001 = ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1));
end

always @ (*) begin
    ap_block_pp0_stage0_11001 = (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state5_io)) | ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state5_io)) | ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)));
end

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage1_01001 = ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1));
end

always @ (*) begin
    ap_block_pp0_stage1_11001 = (((m_axi_gmem_WREADY == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b1)) | ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state2_io)));
end

always @ (*) begin
    ap_block_pp0_stage1_subdone = (((m_axi_gmem_WREADY == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b1)) | ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state2_io)));
end

assign ap_block_pp0_stage2 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage2_01001 = ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1));
end

always @ (*) begin
    ap_block_pp0_stage2_11001 = (((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state3_io)));
end

always @ (*) begin
    ap_block_pp0_stage2_subdone = (((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state3_io)));
end

assign ap_block_pp0_stage3 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage3_01001 = ((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b1));
end

always @ (*) begin
    ap_block_pp0_stage3_11001 = (((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state4_io)));
end

always @ (*) begin
    ap_block_pp0_stage3_subdone = (((m_axi_gmem_BVALID == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_block_state4_io)));
end

always @ (*) begin
    ap_block_state10_pp0_stage1_iter2 = (m_axi_gmem_BVALID == 1'b0);
end

always @ (*) begin
    ap_block_state11_pp0_stage2_iter2 = (m_axi_gmem_BVALID == 1'b0);
end

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state2_io = ((icmp_ln172_reg_351 == 1'd0) & (m_axi_gmem_AWREADY == 1'b0));
end

assign ap_block_state2_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state3_io = (((icmp_ln172_reg_351 == 1'd0) & (m_axi_gmem_AWREADY == 1'b0)) | ((icmp_ln172_reg_351 == 1'd0) & (m_axi_gmem_WREADY == 1'b0)));
end

assign ap_block_state3_pp0_stage2_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state4_io = (((icmp_ln172_reg_351 == 1'd0) & (m_axi_gmem_AWREADY == 1'b0)) | ((icmp_ln172_reg_351 == 1'd0) & (m_axi_gmem_WREADY == 1'b0)));
end

assign ap_block_state4_pp0_stage3_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state5_io = ((m_axi_gmem_WREADY == 1'b0) | (m_axi_gmem_AWREADY == 1'b0));
end

assign ap_block_state5_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state7_pp0_stage2_iter1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state8_pp0_stage3_iter1 = (m_axi_gmem_BVALID == 1'b0);
end

always @ (*) begin
    ap_block_state9_pp0_stage0_iter2 = (m_axi_gmem_BVALID == 1'b0);
end

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage3;

assign i_4_fu_220_p2 = (i_3_reg_344 + 3'd1);

assign i_7_cast9_fu_178_p1 = ap_sig_allocacmp_i_3;

assign icmp_ln172_fu_172_p2 = ((ap_sig_allocacmp_i_3 == 3'd4) ? 1'b1 : 1'b0);

assign lshr_ln173_fu_198_p2 = ctx_state_0_ret1 >> zext_ln173_fu_194_p1;

assign lshr_ln174_fu_225_p2 = ctx_state_1_ret1 >> zext_ln173_reg_355;

assign lshr_ln175_fu_299_p2 = ctx_state_2_ret1 >> zext_ln173_reg_355;

assign lshr_ln176_fu_307_p2 = ctx_state_3_ret1 >> zext_ln173_reg_355;

assign m_axi_gmem_ARADDR = 64'd0;

assign m_axi_gmem_ARBURST = 2'd0;

assign m_axi_gmem_ARCACHE = 4'd0;

assign m_axi_gmem_ARID = 1'd0;

assign m_axi_gmem_ARLEN = 32'd0;

assign m_axi_gmem_ARLOCK = 2'd0;

assign m_axi_gmem_ARPROT = 3'd0;

assign m_axi_gmem_ARQOS = 4'd0;

assign m_axi_gmem_ARREGION = 4'd0;

assign m_axi_gmem_ARSIZE = 3'd0;

assign m_axi_gmem_ARUSER = 1'd0;

assign m_axi_gmem_ARVALID = 1'b0;

assign m_axi_gmem_AWBURST = 2'd0;

assign m_axi_gmem_AWCACHE = 4'd0;

assign m_axi_gmem_AWID = 1'd0;

assign m_axi_gmem_AWLEN = 32'd1;

assign m_axi_gmem_AWLOCK = 2'd0;

assign m_axi_gmem_AWPROT = 3'd0;

assign m_axi_gmem_AWQOS = 4'd0;

assign m_axi_gmem_AWREGION = 4'd0;

assign m_axi_gmem_AWSIZE = 3'd0;

assign m_axi_gmem_AWUSER = 1'd0;

assign m_axi_gmem_RREADY = 1'b0;

assign m_axi_gmem_WID = 1'd0;

assign m_axi_gmem_WLAST = 1'b0;

assign m_axi_gmem_WSTRB = 1'd1;

assign m_axi_gmem_WUSER = 1'd0;

assign sext_ln176_fu_275_p1 = xor_ln174_fu_233_p2;

assign shl_ln1_fu_186_p3 = {{trunc_ln173_fu_182_p1}, {3'd0}};

assign trunc_ln173_1_fu_204_p1 = lshr_ln173_fu_198_p2[7:0];

assign trunc_ln173_fu_182_p1 = ap_sig_allocacmp_i_3[1:0];

assign trunc_ln174_fu_229_p1 = lshr_ln174_fu_225_p2[7:0];

assign trunc_ln175_fu_303_p1 = lshr_ln175_fu_299_p2[7:0];

assign trunc_ln176_fu_311_p1 = lshr_ln176_fu_307_p2[7:0];

assign xor_ln174_fu_233_p2 = (i_3_reg_344 ^ 3'd4);

assign zext_ln173_fu_194_p1 = shl_ln1_fu_186_p3;

assign zext_ln174_fu_238_p1 = $unsigned(xor_ln174_fu_233_p2);

assign zext_ln175_cast_fu_253_p3 = {{1'd1}, {i_3_reg_344}};

assign zext_ln175_fu_260_p1 = zext_ln175_cast_fu_253_p3;

assign zext_ln176_fu_279_p1 = $unsigned(sext_ln176_fu_275_p1);

always @ (posedge ap_clk) begin
    zext_ln173_reg_355[2:0] <= 3'b000;
    zext_ln173_reg_355[31:5] <= 27'b000000000000000000000000000;
end

endmodule //md5_wrap_md5_final_1_Pipeline_VITIS_LOOP_172_3
