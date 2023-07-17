// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of text_input
//        bit 31~0 - text_input[31:0] (Read/Write)
// 0x14 : Data signal of text_input
//        bit 31~0 - text_input[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of result
//        bit 31~0 - result[31:0] (Read/Write)
// 0x20 : Data signal of result
//        bit 31~0 - result[63:32] (Read/Write)
// 0x24 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define CONTROL_ADDR_TEXT_INPUT_DATA 0x10
#define CONTROL_BITS_TEXT_INPUT_DATA 64
#define CONTROL_ADDR_RESULT_DATA     0x1c
#define CONTROL_BITS_RESULT_DATA     64
