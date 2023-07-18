// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmd5_wrap.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMd5_wrap_CfgInitialize(XMd5_wrap *InstancePtr, XMd5_wrap_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMd5_wrap_Start(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL) & 0x80;
    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMd5_wrap_IsDone(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMd5_wrap_IsIdle(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMd5_wrap_IsReady(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMd5_wrap_EnableAutoRestart(XMd5_wrap *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL, 0x80);
}

void XMd5_wrap_DisableAutoRestart(XMd5_wrap *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_CTRL, 0);
}

u32 XMd5_wrap_Get_return(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_AP_RETURN);
    return Data;
}
void XMd5_wrap_Set_text_input(XMd5_wrap *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_TEXT_INPUT_DATA, (u32)(Data));
    XMd5_wrap_WriteReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_TEXT_INPUT_DATA + 4, (u32)(Data >> 32));
}

u64 XMd5_wrap_Get_text_input(XMd5_wrap *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_TEXT_INPUT_DATA);
    Data += (u64)XMd5_wrap_ReadReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_TEXT_INPUT_DATA + 4) << 32;
    return Data;
}

void XMd5_wrap_Set_result(XMd5_wrap *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_RESULT_DATA, (u32)(Data));
    XMd5_wrap_WriteReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_RESULT_DATA + 4, (u32)(Data >> 32));
}

u64 XMd5_wrap_Get_result(XMd5_wrap *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_RESULT_DATA);
    Data += (u64)XMd5_wrap_ReadReg(InstancePtr->Control_BaseAddress, XMD5_WRAP_CONTROL_ADDR_RESULT_DATA + 4) << 32;
    return Data;
}

void XMd5_wrap_Set_text_length(XMd5_wrap *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_TEXT_LENGTH_DATA, Data);
}

u32 XMd5_wrap_Get_text_length(XMd5_wrap *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_TEXT_LENGTH_DATA);
    return Data;
}

void XMd5_wrap_InterruptGlobalEnable(XMd5_wrap *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_GIE, 1);
}

void XMd5_wrap_InterruptGlobalDisable(XMd5_wrap *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_GIE, 0);
}

void XMd5_wrap_InterruptEnable(XMd5_wrap *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_IER);
    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_IER, Register | Mask);
}

void XMd5_wrap_InterruptDisable(XMd5_wrap *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_IER);
    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_IER, Register & (~Mask));
}

void XMd5_wrap_InterruptClear(XMd5_wrap *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMd5_wrap_WriteReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_ISR, Mask);
}

u32 XMd5_wrap_InterruptGetEnabled(XMd5_wrap *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_IER);
}

u32 XMd5_wrap_InterruptGetStatus(XMd5_wrap *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMd5_wrap_ReadReg(InstancePtr->Ctrl_BaseAddress, XMD5_WRAP_CTRL_ADDR_ISR);
}

