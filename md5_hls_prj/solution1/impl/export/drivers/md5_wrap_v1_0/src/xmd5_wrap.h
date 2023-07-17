// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMD5_WRAP_H
#define XMD5_WRAP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmd5_wrap_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
    u64 Ctrl_BaseAddress;
} XMd5_wrap_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u64 Ctrl_BaseAddress;
    u32 IsReady;
} XMd5_wrap;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMd5_wrap_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMd5_wrap_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMd5_wrap_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMd5_wrap_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMd5_wrap_Initialize(XMd5_wrap *InstancePtr, u16 DeviceId);
XMd5_wrap_Config* XMd5_wrap_LookupConfig(u16 DeviceId);
int XMd5_wrap_CfgInitialize(XMd5_wrap *InstancePtr, XMd5_wrap_Config *ConfigPtr);
#else
int XMd5_wrap_Initialize(XMd5_wrap *InstancePtr, const char* InstanceName);
int XMd5_wrap_Release(XMd5_wrap *InstancePtr);
#endif

void XMd5_wrap_Start(XMd5_wrap *InstancePtr);
u32 XMd5_wrap_IsDone(XMd5_wrap *InstancePtr);
u32 XMd5_wrap_IsIdle(XMd5_wrap *InstancePtr);
u32 XMd5_wrap_IsReady(XMd5_wrap *InstancePtr);
void XMd5_wrap_EnableAutoRestart(XMd5_wrap *InstancePtr);
void XMd5_wrap_DisableAutoRestart(XMd5_wrap *InstancePtr);
u32 XMd5_wrap_Get_return(XMd5_wrap *InstancePtr);

void XMd5_wrap_Set_text_input(XMd5_wrap *InstancePtr, u64 Data);
u64 XMd5_wrap_Get_text_input(XMd5_wrap *InstancePtr);
void XMd5_wrap_Set_result(XMd5_wrap *InstancePtr, u64 Data);
u64 XMd5_wrap_Get_result(XMd5_wrap *InstancePtr);
void XMd5_wrap_Set_text_length(XMd5_wrap *InstancePtr, u32 Data);
u32 XMd5_wrap_Get_text_length(XMd5_wrap *InstancePtr);

void XMd5_wrap_InterruptGlobalEnable(XMd5_wrap *InstancePtr);
void XMd5_wrap_InterruptGlobalDisable(XMd5_wrap *InstancePtr);
void XMd5_wrap_InterruptEnable(XMd5_wrap *InstancePtr, u32 Mask);
void XMd5_wrap_InterruptDisable(XMd5_wrap *InstancePtr, u32 Mask);
void XMd5_wrap_InterruptClear(XMd5_wrap *InstancePtr, u32 Mask);
u32 XMd5_wrap_InterruptGetEnabled(XMd5_wrap *InstancePtr);
u32 XMd5_wrap_InterruptGetStatus(XMd5_wrap *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
