// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmd5_wrap.h"

extern XMd5_wrap_Config XMd5_wrap_ConfigTable[];

XMd5_wrap_Config *XMd5_wrap_LookupConfig(u16 DeviceId) {
	XMd5_wrap_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMD5_WRAP_NUM_INSTANCES; Index++) {
		if (XMd5_wrap_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMd5_wrap_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMd5_wrap_Initialize(XMd5_wrap *InstancePtr, u16 DeviceId) {
	XMd5_wrap_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMd5_wrap_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMd5_wrap_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

