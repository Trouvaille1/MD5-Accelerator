set SynModuleInfo {
  {SRCNAME md5_transform MODELNAME md5_transform RTLNAME md5_wrap_md5_transform}
  {SRCNAME md5_wrap_Pipeline_VITIS_LOOP_127_1 MODELNAME md5_wrap_Pipeline_VITIS_LOOP_127_1 RTLNAME md5_wrap_md5_wrap_Pipeline_VITIS_LOOP_127_1
    SUBMODULES {
      {MODELNAME md5_wrap_flow_control_loop_pipe_sequential_init RTLNAME md5_wrap_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME md5_wrap_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME md5_final.1_Pipeline_VITIS_LOOP_152_2 MODELNAME md5_final_1_Pipeline_VITIS_LOOP_152_2 RTLNAME md5_wrap_md5_final_1_Pipeline_VITIS_LOOP_152_2}
  {SRCNAME md5_final.1_Pipeline_3 MODELNAME md5_final_1_Pipeline_3 RTLNAME md5_wrap_md5_final_1_Pipeline_3}
  {SRCNAME md5_final.1_Pipeline_VITIS_LOOP_147_1 MODELNAME md5_final_1_Pipeline_VITIS_LOOP_147_1 RTLNAME md5_wrap_md5_final_1_Pipeline_VITIS_LOOP_147_1}
  {SRCNAME md5_final.1_Pipeline_VITIS_LOOP_172_3 MODELNAME md5_final_1_Pipeline_VITIS_LOOP_172_3 RTLNAME md5_wrap_md5_final_1_Pipeline_VITIS_LOOP_172_3}
  {SRCNAME md5_final.1 MODELNAME md5_final_1 RTLNAME md5_wrap_md5_final_1}
  {SRCNAME md5_wrap MODELNAME md5_wrap RTLNAME md5_wrap IS_TOP 1
    SUBMODULES {
      {MODELNAME md5_wrap_ctx_data_RAM_AUTO_1R1W RTLNAME md5_wrap_ctx_data_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME md5_wrap_gmem_m_axi RTLNAME md5_wrap_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME md5_wrap_CTRL_s_axi RTLNAME md5_wrap_CTRL_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME md5_wrap_control_s_axi RTLNAME md5_wrap_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
