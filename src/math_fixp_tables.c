#include <stdint.h>
#include "math_fixp_defines.h"

const uint16_t far SinTable[SIN_TABLE_SIZE] =
{
    0x0000, 0x0065, 0x00c9, 0x012e, 0x0192, 0x01f7, 0x025b, 0x02c0, 
    0x0324, 0x0389, 0x03ed, 0x0452, 0x04b6, 0x051b, 0x057f, 0x05e4, 
    0x0648, 0x06ad, 0x0711, 0x0776, 0x07da, 0x083f, 0x08a3, 0x0908, 
    0x096c, 0x09d1, 0x0a35, 0x0a9a, 0x0afe, 0x0b62, 0x0bc7, 0x0c2b, 
    0x0c90, 0x0cf4, 0x0d59, 0x0dbd, 0x0e21, 0x0e86, 0x0eea, 0x0f4e, 
    0x0fb3, 0x1017, 0x107b, 0x10e0, 0x1144, 0x11a8, 0x120d, 0x1271, 
    0x12d5, 0x1339, 0x139e, 0x1402, 0x1466, 0x14ca, 0x152e, 0x1593, 
    0x15f7, 0x165b, 0x16bf, 0x1723, 0x1787, 0x17eb, 0x1850, 0x18b4, 
    0x1918, 0x197c, 0x19e0, 0x1a44, 0x1aa8, 0x1b0c, 0x1b70, 0x1bd4, 
    0x1c38, 0x1c9b, 0x1cff, 0x1d63, 0x1dc7, 0x1e2b, 0x1e8f, 0x1ef3, 
    0x1f56, 0x1fba, 0x201e, 0x2082, 0x20e5, 0x2149, 0x21ad, 0x2210, 
    0x2274, 0x22d7, 0x233b, 0x239f, 0x2402, 0x2466, 0x24c9, 0x252d, 
    0x2590, 0x25f4, 0x2657, 0x26ba, 0x271e, 0x2781, 0x27e4, 0x2848, 
    0x28ab, 0x290e, 0x2971, 0x29d5, 0x2a38, 0x2a9b, 0x2afe, 0x2b61, 
    0x2bc4, 0x2c27, 0x2c8a, 0x2ced, 0x2d50, 0x2db3, 0x2e16, 0x2e79, 
    0x2edc, 0x2f3f, 0x2fa1, 0x3004, 0x3067, 0x30ca, 0x312c, 0x318f, 
    0x31f1, 0x3254, 0x32b7, 0x3319, 0x337c, 0x33de, 0x3440, 0x34a3, 
    0x3505, 0x3568, 0x35ca, 0x362c, 0x368e, 0x36f1, 0x3753, 0x37b5, 
    0x3817, 0x3879, 0x38db, 0x393d, 0x399f, 0x3a01, 0x3a63, 0x3ac5, 
    0x3b27, 0x3b88, 0x3bea, 0x3c4c, 0x3cae, 0x3d0f, 0x3d71, 0x3dd2, 
    0x3e34, 0x3e95, 0x3ef7, 0x3f58, 0x3fba, 0x401b, 0x407c, 0x40de, 
    0x413f, 0x41a0, 0x4201, 0x4262, 0x42c3, 0x4324, 0x4385, 0x43e6, 
    0x4447, 0x44a8, 0x4509, 0x456a, 0x45cb, 0x462b, 0x468c, 0x46ec, 
    0x474d, 0x47ae, 0x480e, 0x486f, 0x48cf, 0x492f, 0x4990, 0x49f0, 
    0x4a50, 0x4ab0, 0x4b10, 0x4b71, 0x4bd1, 0x4c31, 0x4c90, 0x4cf0, 
    0x4d50, 0x4db0, 0x4e10, 0x4e70, 0x4ecf, 0x4f2f, 0x4f8e, 0x4fee, 
    0x504d, 0x50ad, 0x510c, 0x516c, 0x51cb, 0x522a, 0x5289, 0x52e8, 
    0x5348, 0x53a7, 0x5406, 0x5464, 0x54c3, 0x5522, 0x5581, 0x55e0, 
    0x563e, 0x569d, 0x56fc, 0x575a, 0x57b9, 0x5817, 0x5875, 0x58d4, 
    0x5932, 0x5990, 0x59ee, 0x5a4c, 0x5aaa, 0x5b08, 0x5b66, 0x5bc4, 
    0x5c22, 0x5c80, 0x5cde, 0x5d3b, 0x5d99, 0x5df6, 0x5e54, 0x5eb1, 
    0x5f0f, 0x5f6c, 0x5fc9, 0x6026, 0x6084, 0x60e1, 0x613e, 0x619b, 
    0x61f8, 0x6254, 0x62b1, 0x630e, 0x636b, 0x63c7, 0x6424, 0x6480, 
    0x64dd, 0x6539, 0x6595, 0x65f2, 0x664e, 0x66aa, 0x6706, 0x6762, 
    0x67be, 0x681a, 0x6876, 0x68d1, 0x692d, 0x6989, 0x69e4, 0x6a40, 
    0x6a9b, 0x6af6, 0x6b52, 0x6bad, 0x6c08, 0x6c63, 0x6cbe, 0x6d19, 
    0x6d74, 0x6dcf, 0x6e2a, 0x6e85, 0x6edf, 0x6f3a, 0x6f94, 0x6fef, 
    0x7049, 0x70a3, 0x70fe, 0x7158, 0x71b2, 0x720c, 0x7266, 0x72c0, 
    0x731a, 0x7373, 0x73cd, 0x7427, 0x7480, 0x74da, 0x7533, 0x758d, 
    0x75e6, 0x763f, 0x7698, 0x76f1, 0x774a, 0x77a3, 0x77fc, 0x7855, 
    0x78ad, 0x7906, 0x795f, 0x79b7, 0x7a10, 0x7a68, 0x7ac0, 0x7b18, 
    0x7b70, 0x7bc8, 0x7c20, 0x7c78, 0x7cd0, 0x7d28, 0x7d7f, 0x7dd7, 
    0x7e2f, 0x7e86, 0x7edd, 0x7f35, 0x7f8c, 0x7fe3, 0x803a, 0x8091, 
    0x80e8, 0x813f, 0x8195, 0x81ec, 0x8243, 0x8299, 0x82f0, 0x8346, 
    0x839c, 0x83f2, 0x8449, 0x849f, 0x84f5, 0x854a, 0x85a0, 0x85f6, 
    0x864c, 0x86a1, 0x86f7, 0x874c, 0x87a1, 0x87f6, 0x884c, 0x88a1, 
    0x88f6, 0x894a, 0x899f, 0x89f4, 0x8a49, 0x8a9d, 0x8af2, 0x8b46, 
    0x8b9a, 0x8bef, 0x8c43, 0x8c97, 0x8ceb, 0x8d3f, 0x8d93, 0x8de6, 
    0x8e3a, 0x8e8d, 0x8ee1, 0x8f34, 0x8f88, 0x8fdb, 0x902e, 0x9081, 
    0x90d4, 0x9127, 0x9179, 0x91cc, 0x921f, 0x9271, 0x92c4, 0x9316, 
    0x9368, 0x93ba, 0x940c, 0x945e, 0x94b0, 0x9502, 0x9554, 0x95a5, 
    0x95f7, 0x9648, 0x969a, 0x96eb, 0x973c, 0x978d, 0x97de, 0x982f, 
    0x9880, 0x98d0, 0x9921, 0x9972, 0x99c2, 0x9a12, 0x9a63, 0x9ab3, 
    0x9b03, 0x9b53, 0x9ba3, 0x9bf2, 0x9c42, 0x9c92, 0x9ce1, 0x9d31, 
    0x9d80, 0x9dcf, 0x9e1e, 0x9e6d, 0x9ebc, 0x9f0b, 0x9f5a, 0x9fa8, 
    0x9ff7, 0xa045, 0xa094, 0xa0e2, 0xa130, 0xa17e, 0xa1cc, 0xa21a, 
    0xa268, 0xa2b5, 0xa303, 0xa350, 0xa39e, 0xa3eb, 0xa438, 0xa485, 
    0xa4d2, 0xa51f, 0xa56c, 0xa5b8, 0xa605, 0xa652, 0xa69e, 0xa6ea, 
    0xa736, 0xa782, 0xa7ce, 0xa81a, 0xa866, 0xa8b2, 0xa8fd, 0xa949, 
    0xa994, 0xa9df, 0xaa2a, 0xaa76, 0xaac1, 0xab0b, 0xab56, 0xaba1, 
    0xabeb, 0xac36, 0xac80, 0xacca, 0xad14, 0xad5e, 0xada8, 0xadf2, 
    0xae3c, 0xae85, 0xaecf, 0xaf18, 0xaf62, 0xafab, 0xaff4, 0xb03d, 
    0xb086, 0xb0ce, 0xb117, 0xb160, 0xb1a8, 0xb1f0, 0xb239, 0xb281, 
    0xb2c9, 0xb311, 0xb358, 0xb3a0, 0xb3e8, 0xb42f, 0xb477, 0xb4be, 
    0xb505, 0xb54c, 0xb593, 0xb5da, 0xb620, 0xb667, 0xb6ad, 0xb6f4, 
    0xb73a, 0xb780, 0xb7c6, 0xb80c, 0xb852, 0xb898, 0xb8dd, 0xb923, 
    0xb968, 0xb9ae, 0xb9f3, 0xba38, 0xba7d, 0xbac1, 0xbb06, 0xbb4b, 
    0xbb8f, 0xbbd4, 0xbc18, 0xbc5c, 0xbca0, 0xbce4, 0xbd28, 0xbd6b, 
    0xbdaf, 0xbdf2, 0xbe36, 0xbe79, 0xbebc, 0xbeff, 0xbf42, 0xbf85, 
    0xbfc7, 0xc00a, 0xc04c, 0xc08f, 0xc0d1, 0xc113, 0xc155, 0xc197, 
    0xc1d8, 0xc21a, 0xc25c, 0xc29d, 0xc2de, 0xc31f, 0xc360, 0xc3a1, 
    0xc3e2, 0xc423, 0xc463, 0xc4a4, 0xc4e4, 0xc524, 0xc564, 0xc5a4, 
    0xc5e4, 0xc624, 0xc663, 0xc6a3, 0xc6e2, 0xc721, 0xc761, 0xc7a0, 
    0xc7de, 0xc81d, 0xc85c, 0xc89a, 0xc8d9, 0xc917, 0xc955, 0xc993, 
    0xc9d1, 0xca0f, 0xca4d, 0xca8a, 0xcac7, 0xcb05, 0xcb42, 0xcb7f, 
    0xcbbc, 0xcbf9, 0xcc35, 0xcc72, 0xccae, 0xcceb, 0xcd27, 0xcd63, 
    0xcd9f, 0xcddb, 0xce17, 0xce52, 0xce8e, 0xcec9, 0xcf04, 0xcf3f, 
    0xcf7a, 0xcfb5, 0xcff0, 0xd02a, 0xd065, 0xd09f, 0xd0d9, 0xd113, 
    0xd14d, 0xd187, 0xd1c1, 0xd1fa, 0xd234, 0xd26d, 0xd2a6, 0xd2df, 
    0xd318, 0xd351, 0xd38a, 0xd3c2, 0xd3fb, 0xd433, 0xd46b, 0xd4a3, 
    0xd4db, 0xd513, 0xd54b, 0xd582, 0xd5ba, 0xd5f1, 0xd628, 0xd65f, 
    0xd696, 0xd6cd, 0xd703, 0xd73a, 0xd770, 0xd7a6, 0xd7dc, 0xd812, 
    0xd848, 0xd87e, 0xd8b4, 0xd8e9, 0xd91e, 0xd954, 0xd989, 0xd9be, 
    0xd9f2, 0xda27, 0xda5c, 0xda90, 0xdac4, 0xdaf8, 0xdb2c, 0xdb60, 
    0xdb94, 0xdbc8, 0xdbfb, 0xdc2f, 0xdc62, 0xdc95, 0xdcc8, 0xdcfb, 
    0xdd2d, 0xdd60, 0xdd92, 0xddc5, 0xddf7, 0xde29, 0xde5b, 0xde8c, 
    0xdebe, 0xdef0, 0xdf21, 0xdf52, 0xdf83, 0xdfb4, 0xdfe5, 0xe016, 
    0xe046, 0xe077, 0xe0a7, 0xe0d7, 0xe107, 0xe137, 0xe167, 0xe196, 
    0xe1c6, 0xe1f5, 0xe224, 0xe253, 0xe282, 0xe2b1, 0xe2df, 0xe30e, 
    0xe33c, 0xe36b, 0xe399, 0xe3c7, 0xe3f4, 0xe422, 0xe450, 0xe47d, 
    0xe4aa, 0xe4d7, 0xe504, 0xe531, 0xe55e, 0xe58b, 0xe5b7, 0xe5e3, 
    0xe610, 0xe63c, 0xe667, 0xe693, 0xe6bf, 0xe6ea, 0xe716, 0xe741, 
    0xe76c, 0xe797, 0xe7c2, 0xe7ec, 0xe817, 0xe841, 0xe86b, 0xe895, 
    0xe8bf, 0xe8e9, 0xe913, 0xe93c, 0xe966, 0xe98f, 0xe9b8, 0xe9e1, 
    0xea0a, 0xea32, 0xea5b, 0xea83, 0xeaab, 0xead4, 0xeafc, 0xeb23, 
    0xeb4b, 0xeb73, 0xeb9a, 0xebc1, 0xebe8, 0xec0f, 0xec36, 0xec5d, 
    0xec83, 0xecaa, 0xecd0, 0xecf6, 0xed1c, 0xed42, 0xed68, 0xed8d, 
    0xedb3, 0xedd8, 0xedfd, 0xee22, 0xee47, 0xee6b, 0xee90, 0xeeb4, 
    0xeed9, 0xeefd, 0xef21, 0xef45, 0xef68, 0xef8c, 0xefaf, 0xefd2, 
    0xeff5, 0xf018, 0xf03b, 0xf05e, 0xf080, 0xf0a3, 0xf0c5, 0xf0e7, 
    0xf109, 0xf12b, 0xf14c, 0xf16e, 0xf18f, 0xf1b1, 0xf1d2, 0xf1f3, 
    0xf213, 0xf234, 0xf254, 0xf275, 0xf295, 0xf2b5, 0xf2d5, 0xf2f5, 
    0xf314, 0xf334, 0xf353, 0xf372, 0xf391, 0xf3b0, 0xf3cf, 0xf3ed, 
    0xf40c, 0xf42a, 0xf448, 0xf466, 0xf484, 0xf4a2, 0xf4bf, 0xf4dd, 
    0xf4fa, 0xf517, 0xf534, 0xf551, 0xf56e, 0xf58a, 0xf5a6, 0xf5c3, 
    0xf5df, 0xf5fb, 0xf616, 0xf632, 0xf64e, 0xf669, 0xf684, 0xf69f, 
    0xf6ba, 0xf6d5, 0xf6ef, 0xf70a, 0xf724, 0xf73e, 0xf758, 0xf772, 
    0xf78c, 0xf7a5, 0xf7bf, 0xf7d8, 0xf7f1, 0xf80a, 0xf823, 0xf83b, 
    0xf854, 0xf86c, 0xf885, 0xf89d, 0xf8b4, 0xf8cc, 0xf8e4, 0xf8fb, 
    0xf913, 0xf92a, 0xf941, 0xf958, 0xf96e, 0xf985, 0xf99b, 0xf9b2, 
    0xf9c8, 0xf9de, 0xf9f3, 0xfa09, 0xfa1f, 0xfa34, 0xfa49, 0xfa5e, 
    0xfa73, 0xfa88, 0xfa9c, 0xfab1, 0xfac5, 0xfad9, 0xfaed, 0xfb01, 
    0xfb15, 0xfb28, 0xfb3c, 0xfb4f, 0xfb62, 0xfb75, 0xfb88, 0xfb9a, 
    0xfbad, 0xfbbf, 0xfbd1, 0xfbe3, 0xfbf5, 0xfc07, 0xfc18, 0xfc2a, 
    0xfc3b, 0xfc4c, 0xfc5d, 0xfc6e, 0xfc7f, 0xfc8f, 0xfca0, 0xfcb0, 
    0xfcc0, 0xfcd0, 0xfcdf, 0xfcef, 0xfcfe, 0xfd0e, 0xfd1d, 0xfd2c, 
    0xfd3b, 0xfd49, 0xfd58, 0xfd66, 0xfd74, 0xfd83, 0xfd90, 0xfd9e, 
    0xfdac, 0xfdb9, 0xfdc7, 0xfdd4, 0xfde1, 0xfdee, 0xfdfa, 0xfe07, 
    0xfe13, 0xfe1f, 0xfe2b, 0xfe37, 0xfe43, 0xfe4f, 0xfe5a, 0xfe66, 
    0xfe71, 0xfe7c, 0xfe87, 0xfe91, 0xfe9c, 0xfea6, 0xfeb0, 0xfeba, 
    0xfec4, 0xfece, 0xfed8, 0xfee1, 0xfeeb, 0xfef4, 0xfefd, 0xff06, 
    0xff0e, 0xff17, 0xff1f, 0xff28, 0xff30, 0xff38, 0xff3f, 0xff47, 
    0xff4e, 0xff56, 0xff5d, 0xff64, 0xff6b, 0xff71, 0xff78, 0xff7e, 
    0xff85, 0xff8b, 0xff91, 0xff96, 0xff9c, 0xffa2, 0xffa7, 0xffac, 
    0xffb1, 0xffb6, 0xffbb, 0xffbf, 0xffc4, 0xffc8, 0xffcc, 0xffd0, 
    0xffd4, 0xffd7, 0xffdb, 0xffde, 0xffe1, 0xffe4, 0xffe7, 0xffea, 
    0xffec, 0xffef, 0xfff1, 0xfff3, 0xfff5, 0xfff7, 0xfff8, 0xfffa, 
    0xfffb, 0xfffc, 0xfffd, 0xfffe, 0xffff, 0xffff, 0xffff, 0xffff
};

const uint16_t far SinAcosTable[SIN_ACOS_TABLE_SIZE] =
{
    0xffff, 0xffe0, 0xffc0, 0xffa0, 0xff80, 0xff60, 0xff40, 0xff20, 
    0xfeff, 0xfedf, 0xfebf, 0xfe9f, 0xfe7f, 0xfe5f, 0xfe3e, 0xfe1e, 
    0xfdfe, 0xfdde, 0xfdbd, 0xfd9d, 0xfd7d, 0xfd5d, 0xfd3c, 0xfd1c, 
    0xfcfb, 0xfcdb, 0xfcbb, 0xfc9a, 0xfc7a, 0xfc59, 0xfc39, 0xfc18, 
    0xfbf8, 0xfbd7, 0xfbb7, 0xfb96, 0xfb76, 0xfb55, 0xfb35, 0xfb14, 
    0xfaf3, 0xfad3, 0xfab2, 0xfa91, 0xfa71, 0xfa50, 0xfa2f, 0xfa0e, 
    0xf9ee, 0xf9cd, 0xf9ac, 0xf98b, 0xf96a, 0xf949, 0xf929, 0xf908, 
    0xf8e7, 0xf8c6, 0xf8a5, 0xf884, 0xf863, 0xf842, 0xf821, 0xf800, 
    0xf7df, 0xf7be, 0xf79d, 0xf77c, 0xf75b, 0xf739, 0xf718, 0xf6f7, 
    0xf6d6, 0xf6b5, 0xf694, 0xf672, 0xf651, 0xf630, 0xf60f, 0xf5ed, 
    0xf5cc, 0xf5ab, 0xf589, 0xf568, 0xf546, 0xf525, 0xf504, 0xf4e2, 
    0xf4c1, 0xf49f, 0xf47e, 0xf45c, 0xf43b, 0xf419, 0xf3f8, 0xf3d6, 
    0xf3b4, 0xf393, 0xf371, 0xf34f, 0xf32e, 0xf30c, 0xf2ea, 0xf2c9, 
    0xf2a7, 0xf285, 0xf263, 0xf242, 0xf220, 0xf1fe, 0xf1dc, 0xf1ba, 
    0xf198, 0xf176, 0xf154, 0xf132, 0xf110, 0xf0ee, 0xf0cc, 0xf0aa, 
    0xf088, 0xf066, 0xf044, 0xf022, 0xf000, 0xefde, 0xefbc, 0xef9a, 
    0xef77, 0xef55, 0xef33, 0xef11, 0xeeee, 0xeecc, 0xeeaa, 0xee87, 
    0xee65, 0xee43, 0xee20, 0xedfe, 0xeddb, 0xedb9, 0xed96, 0xed74, 
    0xed51, 0xed2f, 0xed0c, 0xecea, 0xecc7, 0xeca5, 0xec82, 0xec5f, 
    0xec3d, 0xec1a, 0xebf7, 0xebd5, 0xebb2, 0xeb8f, 0xeb6c, 0xeb49, 
    0xeb27, 0xeb04, 0xeae1, 0xeabe, 0xea9b, 0xea78, 0xea55, 0xea32, 
    0xea0f, 0xe9ec, 0xe9c9, 0xe9a6, 0xe983, 0xe960, 0xe93d, 0xe91a, 
    0xe8f7, 0xe8d3, 0xe8b0, 0xe88d, 0xe86a, 0xe847, 0xe823, 0xe800, 
    0xe7dd, 0xe7b9, 0xe796, 0xe773, 0xe74f, 0xe72c, 0xe708, 0xe6e5, 
    0xe6c1, 0xe69e, 0xe67a, 0xe657, 0xe633, 0xe610, 0xe5ec, 0xe5c8, 
    0xe5a5, 0xe581, 0xe55d, 0xe53a, 0xe516, 0xe4f2, 0xe4ce, 0xe4aa, 
    0xe487, 0xe463, 0xe43f, 0xe41b, 0xe3f7, 0xe3d3, 0xe3af, 0xe38b, 
    0xe367, 0xe343, 0xe31f, 0xe2fb, 0xe2d7, 0xe2b3, 0xe28f, 0xe26a, 
    0xe246, 0xe222, 0xe1fe, 0xe1d9, 0xe1b5, 0xe191, 0xe16d, 0xe148, 
    0xe124, 0xe0ff, 0xe0db, 0xe0b7, 0xe092, 0xe06e, 0xe049, 0xe025, 
    0xe000, 0xdfdb, 0xdfb7, 0xdf92, 0xdf6e, 0xdf49, 0xdf24, 0xdeff, 
    0xdedb, 0xdeb6, 0xde91, 0xde6c, 0xde47, 0xde23, 0xddfe, 0xddd9, 
    0xddb4, 0xdd8f, 0xdd6a, 0xdd45, 0xdd20, 0xdcfb, 0xdcd6, 0xdcb1, 
    0xdc8b, 0xdc66, 0xdc41, 0xdc1c, 0xdbf7, 0xdbd1, 0xdbac, 0xdb87, 
    0xdb62, 0xdb3c, 0xdb17, 0xdaf1, 0xdacc, 0xdaa7, 0xda81, 0xda5c, 
    0xda36, 0xda10, 0xd9eb, 0xd9c5, 0xd9a0, 0xd97a, 0xd954, 0xd92f, 
    0xd909, 0xd8e3, 0xd8bd, 0xd897, 0xd872, 0xd84c, 0xd826, 0xd800, 
    0xd7da, 0xd7b4, 0xd78e, 0xd768, 0xd742, 0xd71c, 0xd6f6, 0xd6d0, 
    0xd6aa, 0xd683, 0xd65d, 0xd637, 0xd611, 0xd5ea, 0xd5c4, 0xd59e, 
    0xd577, 0xd551, 0xd52b, 0xd504, 0xd4de, 0xd4b7, 0xd491, 0xd46a, 
    0xd444, 0xd41d, 0xd3f6, 0xd3d0, 0xd3a9, 0xd382, 0xd35c, 0xd335, 
    0xd30e, 0xd2e7, 0xd2c0, 0xd299, 0xd272, 0xd24c, 0xd225, 0xd1fe, 
    0xd1d7, 0xd1af, 0xd188, 0xd161, 0xd13a, 0xd113, 0xd0ec, 0xd0c5, 
    0xd09d, 0xd076, 0xd04f, 0xd027, 0xd000, 0xcfd9, 0xcfb1, 0xcf8a, 
    0xcf62, 0xcf3b, 0xcf13, 0xceec, 0xcec4, 0xce9c, 0xce75, 0xce4d, 
    0xce25, 0xcdfe, 0xcdd6, 0xcdae, 0xcd86, 0xcd5e, 0xcd36, 0xcd0e, 
    0xcce6, 0xccbe, 0xcc96, 0xcc6e, 0xcc46, 0xcc1e, 0xcbf6, 0xcbce, 
    0xcba6, 0xcb7d, 0xcb55, 0xcb2d, 0xcb04, 0xcadc, 0xcab4, 0xca8b, 
    0xca63, 0xca3a, 0xca12, 0xc9e9, 0xc9c1, 0xc998, 0xc96f, 0xc947, 
    0xc91e, 0xc8f5, 0xc8cc, 0xc8a4, 0xc87b, 0xc852, 0xc829, 0xc800, 
    0xc7d7, 0xc7ae, 0xc785, 0xc75c, 0xc733, 0xc70a, 0xc6e0, 0xc6b7, 
    0xc68e, 0xc665, 0xc63b, 0xc612, 0xc5e9, 0xc5bf, 0xc596, 0xc56c, 
    0xc543, 0xc519, 0xc4f0, 0xc4c6, 0xc49c, 0xc473, 0xc449, 0xc41f, 
    0xc3f6, 0xc3cc, 0xc3a2, 0xc378, 0xc34e, 0xc324, 0xc2fa, 0xc2d0, 
    0xc2a6, 0xc27c, 0xc252, 0xc228, 0xc1fd, 0xc1d3, 0xc1a9, 0xc17f, 
    0xc154, 0xc12a, 0xc0ff, 0xc0d5, 0xc0aa, 0xc080, 0xc055, 0xc02b, 
    0xc000, 0xbfd5, 0xbfab, 0xbf80, 0xbf55, 0xbf2a, 0xbeff, 0xbed4, 
    0xbea9, 0xbe7e, 0xbe53, 0xbe28, 0xbdfd, 0xbdd2, 0xbda7, 0xbd7c, 
    0xbd51, 0xbd25, 0xbcfa, 0xbccf, 0xbca3, 0xbc78, 0xbc4c, 0xbc21, 
    0xbbf5, 0xbbca, 0xbb9e, 0xbb72, 0xbb46, 0xbb1b, 0xbaef, 0xbac3, 
    0xba97, 0xba6b, 0xba3f, 0xba13, 0xb9e7, 0xb9bb, 0xb98f, 0xb963, 
    0xb937, 0xb90a, 0xb8de, 0xb8b2, 0xb885, 0xb859, 0xb82d, 0xb800, 
    0xb7d3, 0xb7a7, 0xb77a, 0xb74e, 0xb721, 0xb6f4, 0xb6c7, 0xb69a, 
    0xb66e, 0xb641, 0xb614, 0xb5e7, 0xb5ba, 0xb58d, 0xb55f, 0xb532, 
    0xb505, 0xb4d8, 0xb4aa, 0xb47d, 0xb450, 0xb422, 0xb3f5, 0xb3c7, 
    0xb399, 0xb36c, 0xb33e, 0xb310, 0xb2e3, 0xb2b5, 0xb287, 0xb259, 
    0xb22b, 0xb1fd, 0xb1cf, 0xb1a1, 0xb173, 0xb145, 0xb116, 0xb0e8, 
    0xb0ba, 0xb08b, 0xb05d, 0xb02f, 0xb000, 0xafd1, 0xafa3, 0xaf74, 
    0xaf45, 0xaf17, 0xaee8, 0xaeb9, 0xae8a, 0xae5b, 0xae2c, 0xadfd, 
    0xadce, 0xad9f, 0xad70, 0xad40, 0xad11, 0xace2, 0xacb2, 0xac83, 
    0xac53, 0xac24, 0xabf4, 0xabc4, 0xab95, 0xab65, 0xab35, 0xab05, 
    0xaad5, 0xaaa5, 0xaa75, 0xaa45, 0xaa15, 0xa9e5, 0xa9b5, 0xa984, 
    0xa954, 0xa924, 0xa8f3, 0xa8c3, 0xa892, 0xa861, 0xa831, 0xa800, 
    0xa7cf, 0xa79e, 0xa76d, 0xa73d, 0xa70b, 0xa6da, 0xa6a9, 0xa678, 
    0xa647, 0xa616, 0xa5e4, 0xa5b3, 0xa581, 0xa550, 0xa51e, 0xa4ed, 
    0xa4bb, 0xa489, 0xa457, 0xa425, 0xa3f4, 0xa3c2, 0xa38f, 0xa35d, 
    0xa32b, 0xa2f9, 0xa2c7, 0xa294, 0xa262, 0xa22f, 0xa1fd, 0xa1ca, 
    0xa198, 0xa165, 0xa132, 0xa0ff, 0xa0cc, 0xa099, 0xa066, 0xa033, 
    0xa000, 0x9fcd, 0x9f99, 0x9f66, 0x9f33, 0x9eff, 0x9ecc, 0x9e98, 
    0x9e64, 0x9e31, 0x9dfd, 0x9dc9, 0x9d95, 0x9d61, 0x9d2d, 0x9cf9, 
    0x9cc4, 0x9c90, 0x9c5c, 0x9c27, 0x9bf3, 0x9bbe, 0x9b8a, 0x9b55, 
    0x9b20, 0x9aeb, 0x9ab6, 0x9a81, 0x9a4c, 0x9a17, 0x99e2, 0x99ad, 
    0x9977, 0x9942, 0x990d, 0x98d7, 0x98a1, 0x986c, 0x9836, 0x9800, 
    0x97ca, 0x9794, 0x975e, 0x9728, 0x96f2, 0x96bb, 0x9685, 0x964e, 
    0x9618, 0x95e1, 0x95ab, 0x9574, 0x953d, 0x9506, 0x94cf, 0x9498, 
    0x9461, 0x9429, 0x93f2, 0x93bb, 0x9383, 0x934c, 0x9314, 0x92dc, 
    0x92a4, 0x926d, 0x9235, 0x91fc, 0x91c4, 0x918c, 0x9154, 0x911b, 
    0x90e3, 0x90aa, 0x9072, 0x9039, 0x9000, 0x8fc7, 0x8f8e, 0x8f55, 
    0x8f1c, 0x8ee2, 0x8ea9, 0x8e70, 0x8e36, 0x8dfc, 0x8dc3, 0x8d89, 
    0x8d4f, 0x8d15, 0x8cdb, 0x8ca1, 0x8c66, 0x8c2c, 0x8bf1, 0x8bb7, 
    0x8b7c, 0x8b41, 0x8b06, 0x8acb, 0x8a90, 0x8a55, 0x8a1a, 0x89df, 
    0x89a3, 0x8968, 0x892c, 0x88f0, 0x88b4, 0x8878, 0x883c, 0x8800, 
    0x87c4, 0x8787, 0x874b, 0x870e, 0x86d2, 0x8695, 0x8658, 0x861b, 
    0x85de, 0x85a0, 0x8563, 0x8526, 0x84e8, 0x84aa, 0x846c, 0x842f, 
    0x83f0, 0x83b2, 0x8374, 0x8336, 0x82f7, 0x82b9, 0x827a, 0x823b, 
    0x81fc, 0x81bd, 0x817e, 0x813e, 0x80ff, 0x80bf, 0x8080, 0x8040, 
    0x8000, 0x7fc0, 0x7f80, 0x7f3f, 0x7eff, 0x7ebe, 0x7e7e, 0x7e3d, 
    0x7dfc, 0x7dbb, 0x7d7a, 0x7d38, 0x7cf7, 0x7cb5, 0x7c73, 0x7c32, 
    0x7bef, 0x7bad, 0x7b6b, 0x7b29, 0x7ae6, 0x7aa3, 0x7a60, 0x7a1d, 
    0x79da, 0x7997, 0x7953, 0x7910, 0x78cc, 0x7888, 0x7844, 0x7800, 
    0x77bc, 0x7777, 0x7733, 0x76ee, 0x76a9, 0x7664, 0x761e, 0x75d9, 
    0x7593, 0x754e, 0x7508, 0x74c2, 0x747b, 0x7435, 0x73ee, 0x73a8, 
    0x7361, 0x731a, 0x72d2, 0x728b, 0x7243, 0x71fc, 0x71b4, 0x716b, 
    0x7123, 0x70db, 0x7092, 0x7049, 0x7000, 0x6fb7, 0x6f6d, 0x6f24, 
    0x6eda, 0x6e90, 0x6e46, 0x6dfb, 0x6db1, 0x6d66, 0x6d1b, 0x6cd0, 
    0x6c84, 0x6c39, 0x6bed, 0x6ba1, 0x6b55, 0x6b08, 0x6abc, 0x6a6f, 
    0x6a22, 0x69d4, 0x6987, 0x6939, 0x68eb, 0x689d, 0x684f, 0x6800, 
    0x67b1, 0x6762, 0x6713, 0x66c3, 0x6673, 0x6623, 0x65d3, 0x6582, 
    0x6531, 0x64e0, 0x648f, 0x643d, 0x63ec, 0x6399, 0x6347, 0x62f4, 
    0x62a1, 0x624e, 0x61fb, 0x61a7, 0x6153, 0x60ff, 0x60aa, 0x6055, 
    0x6000, 0x5fab, 0x5f55, 0x5eff, 0x5ea8, 0x5e52, 0x5dfb, 0x5da3, 
    0x5d4c, 0x5cf4, 0x5c9b, 0x5c43, 0x5bea, 0x5b90, 0x5b37, 0x5add, 
    0x5a82, 0x5a28, 0x59cd, 0x5971, 0x5916, 0x58b9, 0x585d, 0x5800, 
    0x57a3, 0x5745, 0x56e7, 0x5689, 0x562a, 0x55ca, 0x556b, 0x550b, 
    0x54aa, 0x5449, 0x53e8, 0x5386, 0x5323, 0x52c1, 0x525d, 0x51fa, 
    0x5196, 0x5131, 0x50cc, 0x5066, 0x5000, 0x4f99, 0x4f32, 0x4eca, 
    0x4e62, 0x4df9, 0x4d90, 0x4d26, 0x4cbc, 0x4c51, 0x4be5, 0x4b79, 
    0x4b0c, 0x4a9e, 0x4a30, 0x49c2, 0x4952, 0x48e2, 0x4871, 0x4800, 
    0x478e, 0x471b, 0x46a7, 0x4633, 0x45be, 0x4548, 0x44d2, 0x445a, 
    0x43e2, 0x4369, 0x42ef, 0x4274, 0x41f8, 0x417c, 0x40fe, 0x4080, 
    0x4000, 0x3f7f, 0x3efe, 0x3e7b, 0x3df8, 0x3d73, 0x3ced, 0x3c66, 
    0x3bde, 0x3b54, 0x3aca, 0x3a3e, 0x39b0, 0x3922, 0x3892, 0x3800, 
    0x376d, 0x36d8, 0x3642, 0x35aa, 0x3511, 0x3476, 0x33d9, 0x333a, 
    0x3299, 0x31f6, 0x3151, 0x30a9, 0x3000, 0x2f54, 0x2ea6, 0x2df5, 
    0x2d41, 0x2c8b, 0x2bd1, 0x2b15, 0x2a55, 0x2992, 0x28cb, 0x2800, 
    0x2731, 0x265e, 0x2586, 0x24a9, 0x23c7, 0x22df, 0x21f1, 0x20fc, 
    0x2000, 0x1efc, 0x1def, 0x1cd8, 0x1bb6, 0x1a88, 0x194c, 0x1800, 
    0x16a1, 0x152a, 0x1399, 0x11e3, 0x1000, 0x0ddb, 0x0b50, 0x0800
};


// generate sin/cos lookup table
/*
#include <stdio.h>
#include <math.h>

#define SIN_TABLE_SIZE 1024

int main()
{
    unsigned trig_table[SIN_TABLE_SIZE];

    int i;
    double angle; // radians
    unsigned long result;
    
    for (i=0; i<SIN_TABLE_SIZE; i++)
    {
        angle = ((double)i/SIN_TABLE_SIZE) * (M_PI/2.0);
        result = (sin(angle) * 0x10000) + 0.5;
        trig_table[i] = (result > 65535UL) ? 65535U : result;
    }
    
    for (i=0; i<SIN_TABLE_SIZE; i++)
    {
        if (i%8==0) putchar('\n');
        printf("0x%04x, ", trig_table[i]);
    }
    
    return 0;
}
*/

// generate sinAcos lookup table
/*
#include <stdio.h>
#include <math.h>

#define SIN_ACOS_TABLE_SIZE 1024

int main()
{
    unsigned trig_table[SIN_ACOS_TABLE_SIZE];

    int i;
    double coefficient;
    unsigned long result;
    
    for (i=0; i<SIN_ACOS_TABLE_SIZE; i++)
    {
        coefficient = (double)i/SIN_ACOS_TABLE_SIZE;
        result = sqrt(1.0-coefficient) * 0x10000 + 0.5;
        trig_table[i] = (result > 65535UL) ? 65535U : result;
    }
    
    for (i=0; i<SIN_ACOS_TABLE_SIZE; i++)
    {
        if (i%8==0) putchar('\n');
        printf("0x%04x, ", trig_table[i]);
    }
    
    return 0;
}
*/
