﻿#include <iostream>

const unsigned char S_BOX[256] =
{
	0x63, 0x7c,	0x77, 0x7b,	0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82,	0xc9 ,0x7d,	0xfa, 0x59,	0x47, 0xf0,	0xad, 0xd4,	0xa2, 0xaf,	0x9c, 0xa4,	0x72, 0xc0,
	0xb7, 0xfd,	0x93 ,0x26,	0x36, 0x3f,	0xf7, 0xcc,	0x34, 0xa5,	0xe5, 0xf1,	0x71, 0xd8,	0x31, 0x15,
	0x04, 0xc7,	0x23 ,0xc3,	0x18, 0x96,	0x05, 0x9a,	0x07, 0x12,	0x80, 0xe2,	0xeb, 0x27,	0xb2, 0x75,
	0x09, 0x83,	0x2c ,0x1a,	0x1b, 0x6e,	0x5a, 0xa0,	0x52, 0x3b,	0xd6, 0xb3,	0x29, 0xe3,	0x2f, 0x84,
	0x53, 0xd1,	0x00 ,0xed,	0x20, 0xfc,	0xb1, 0x5b,	0x6a, 0xcb,	0xbe, 0x39,	0x4a, 0x4c,	0x58, 0xcf,
	0xd0, 0xef,	0xaa ,0xfb,	0x43, 0x4d,	0x33, 0x85,	0x45, 0xf9,	0x02, 0x7f,	0x50, 0x3c,	0x9f, 0xa8,
	0x51, 0xa3,	0x40 ,0x8f,	0x92, 0x9d,	0x38, 0xf5,	0xbc, 0xb6,	0xda, 0x21,	0x10, 0xff,	0xf3, 0xd2,
	0xcd, 0x0c,	0x13 ,0xec,	0x5f, 0x97,	0x44, 0x17,	0xc4, 0xa7,	0x7e, 0x3d,	0x64, 0x5d,	0x19, 0x73,
	0x60, 0x81,	0x4f ,0xdc,	0x22, 0x2a,	0x90, 0x88,	0x46, 0xee,	0xb8, 0x14,	0xde, 0x5e,	0x0b, 0xdb,
	0xe0, 0x32, 0x3a ,0x0a,	0x49, 0x06,	0x24, 0x5c,	0xc2, 0xd3,	0xac, 0x62,	0x91, 0x95,	0xe4, 0x79,
	0xe7, 0xc8, 0x37 ,0x6d,	0x8d, 0xd5,	0x4e, 0xa9,	0x6c, 0x56,	0xf4, 0xea,	0x65, 0x7a,	0xae, 0x08,
	0xba, 0x78, 0x25 ,0x2e,	0x1c, 0xa6,	0xb4, 0xc6,	0xe8, 0xdd,	0x74, 0x1f,	0x4b, 0xbd,	0x8b, 0x8a,
	0x70, 0x3e, 0xb5 ,0x66,	0x48, 0x03,	0xf6, 0x0e,	0x61, 0x35,	0x57, 0xb9,	0x86, 0xc1,	0x1d, 0x9e,
	0xe1, 0xf8, 0x98 ,0x11,	0x69, 0xd9,	0x8e, 0x94,	0x9b, 0x1e,	0x87, 0xe9,	0xce, 0x55,	0x28, 0xdf,
	0x8c, 0xa1, 0x89 ,0x0d,	0xbf, 0xe6,	0x42, 0x68,	0x41, 0x99,	0x2d, 0x0f,	0xb0, 0x54,	0xbb, 0x16
};

const unsigned char INVERSE_S_BOX[256] =
{
	0x52,	0x09,	0x6a,	0xd5,	0x30,	0x36,	0xa5,	0x38,	0xbf,	0x40,	0xa3,	0x9e,	0x81,	0xf3,	0xd7,	0xfb,
	0x7c,	0xe3,	0x39,	0x82,	0x9b,	0x2f,	0xff,	0x87,	0x34,	0x8e,	0x43,	0x44,	0xc4,	0xde,	0xe9,	0xcb,
	0x54,	0x7b,	0x94,	0x32,	0xa6,	0xc2,	0x23,	0x3d,	0xee,	0x4c,	0x95,	0x0b,	0x42,	0xfa,	0xc3,	0x4e,
	0x08,	0x2e,	0xa1,	0x66,	0x28,	0xd9,	0x24,	0xb2,	0x76,	0x5b,	0xa2,	0x49,	0x6d,	0x8b,	0xd1,	0x25,
	0x72,	0xf8,	0xf6,	0x64,	0x86,	0x68,	0x98,	0x16,	0xd4,	0xa4,	0x5c,	0xcc,	0x5d,	0x65,	0xb6,	0x92,
	0x6c,	0x70,	0x48,	0x50,	0xfd,	0xed,	0xb9,	0xda,	0x5e,	0x15,	0x46,	0x57,	0xa7,	0x8d,	0x9d,	0x84,
	0x90,	0xd8,	0xab,	0x00,	0x8c,	0xbc,	0xd3,	0x0a,	0xf7,	0xe4,	0x58,	0x05,	0xb8,	0xb3,	0x45,	0x06,
	0xd0,	0x2c,	0x1e,	0x8f,	0xca,	0x3f,	0x0f,	0x02,	0xc1,	0xaf,	0xbd,	0x03,	0x01,	0x13,	0x8a,	0x6b,
	0x3a,	0x91,	0x11,	0x41,	0x4f,	0x67,	0xdc,	0xea,	0x97,	0xf2,	0xcf,	0xce,	0xf0,	0xb4,	0xe6,	0x73,
	0x96,	0xac,	0x74,	0x22,	0xe7,	0xad,	0x35,	0x85,	0xe2,	0xf9,	0x37,	0xe8,	0x1c,	0x75,	0xdf,	0x6e,
	0x47,	0xf1,	0x1a,	0x71,	0x1d,	0x29,	0xc5,	0x89,	0x6f,	0xb7,	0x62,	0x0e,	0xaa,	0x18,	0xbe,	0x1b,
	0xfc,	0x56,	0x3e,	0x4b,	0xc6,	0xd2,	0x79,	0x20,	0x9a,	0xdb,	0xc0,	0xfe,	0x78,	0xcd,	0x5a,	0xf4,
	0x1f,	0xdd,	0xa8,	0x33,	0x88,	0x07,	0xc7,	0x31,	0xb1,	0x12,	0x10,	0x59,	0x27,	0x80,	0xec,	0x5f,
	0x60,	0x51,	0x7f,	0xa9,	0x19,	0xb5,	0x4a,	0x0d,	0x2d,	0xe5,	0x7a,	0x9f,	0x93,	0xc9,	0x9c,	0xef,
	0xa0,	0xe0,	0x3b,	0x4d,	0xae,	0x2a,	0xf5,	0xb0,	0xc8,	0xeb,	0xbb,	0x3c,	0x83,	0x53,	0x99,	0x61,
	0x17,	0x2b,	0x04,	0x7e,	0xba,	0x77,	0xd6,	0x26,	0xe1,	0x69,	0x14,	0x63,	0x55,	0x21,	0x0c,	0x7d
};

//Lookup table for multiplication by 2
const unsigned char mul2[256] =
{
	0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
	0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
	0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
	0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
	0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
	0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
	0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
	0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
	0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
	0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
	0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
	0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
	0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
	0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
	0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
	0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};

//Lookup table for multiplication by 3
const unsigned char mul3[256] =
{
	0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
	0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
	0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
	0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
	0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
	0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
	0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
	0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
	0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
	0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
	0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
	0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
	0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
	0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
	0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
	0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
};

const unsigned char mul9[256] =
{
	0x00,0x09,0x12,0x1b,0x24,0x2d,0x36,0x3f,0x48,0x41,0x5a,0x53,0x6c,0x65,0x7e,0x77,
	0x90,0x99,0x82,0x8b,0xb4,0xbd,0xa6,0xaf,0xd8,0xd1,0xca,0xc3,0xfc,0xf5,0xee,0xe7,
	0x3b,0x32,0x29,0x20,0x1f,0x16,0x0d,0x04,0x73,0x7a,0x61,0x68,0x57,0x5e,0x45,0x4c,
	0xab,0xa2,0xb9,0xb0,0x8f,0x86,0x9d,0x94,0xe3,0xea,0xf1,0xf8,0xc7,0xce,0xd5,0xdc,
	0x76,0x7f,0x64,0x6d,0x52,0x5b,0x40,0x49,0x3e,0x37,0x2c,0x25,0x1a,0x13,0x08,0x01,
	0xe6,0xef,0xf4,0xfd,0xc2,0xcb,0xd0,0xd9,0xae,0xa7,0xbc,0xb5,0x8a,0x83,0x98,0x91,
	0x4d,0x44,0x5f,0x56,0x69,0x60,0x7b,0x72,0x05,0x0c,0x17,0x1e,0x21,0x28,0x33,0x3a,
	0xdd,0xd4,0xcf,0xc6,0xf9,0xf0,0xeb,0xe2,0x95,0x9c,0x87,0x8e,0xb1,0xb8,0xa3,0xaa,
	0xec,0xe5,0xfe,0xf7,0xc8,0xc1,0xda,0xd3,0xa4,0xad,0xb6,0xbf,0x80,0x89,0x92,0x9b,
	0x7c,0x75,0x6e,0x67,0x58,0x51,0x4a,0x43,0x34,0x3d,0x26,0x2f,0x10,0x19,0x02,0x0b,
	0xd7,0xde,0xc5,0xcc,0xf3,0xfa,0xe1,0xe8,0x9f,0x96,0x8d,0x84,0xbb,0xb2,0xa9,0xa0,
	0x47,0x4e,0x55,0x5c,0x63,0x6a,0x71,0x78,0x0f,0x06,0x1d,0x14,0x2b,0x22,0x39,0x30,
	0x9a,0x93,0x88,0x81,0xbe,0xb7,0xac,0xa5,0xd2,0xdb,0xc0,0xc9,0xf6,0xff,0xe4,0xed,
	0x0a,0x03,0x18,0x11,0x2e,0x27,0x3c,0x35,0x42,0x4b,0x50,0x59,0x66,0x6f,0x74,0x7d,
	0xa1,0xa8,0xb3,0xba,0x85,0x8c,0x97,0x9e,0xe9,0xe0,0xfb,0xf2,0xcd,0xc4,0xdf,0xd6,
	0x31,0x38,0x23,0x2a,0x15,0x1c,0x07,0x0e,0x79,0x70,0x6b,0x62,0x5d,0x54,0x4f,0x46
};

const unsigned char mul11[256] =
{
	0x00,0x0b,0x16,0x1d,0x2c,0x27,0x3a,0x31,0x58,0x53,0x4e,0x45,0x74,0x7f,0x62,0x69,
	0xb0,0xbb,0xa6,0xad,0x9c,0x97,0x8a,0x81,0xe8,0xe3,0xfe,0xf5,0xc4,0xcf,0xd2,0xd9,
	0x7b,0x70,0x6d,0x66,0x57,0x5c,0x41,0x4a,0x23,0x28,0x35,0x3e,0x0f,0x04,0x19,0x12,
	0xcb,0xc0,0xdd,0xd6,0xe7,0xec,0xf1,0xfa,0x93,0x98,0x85,0x8e,0xbf,0xb4,0xa9,0xa2,
	0xf6,0xfd,0xe0,0xeb,0xda,0xd1,0xcc,0xc7,0xae,0xa5,0xb8,0xb3,0x82,0x89,0x94,0x9f,
	0x46,0x4d,0x50,0x5b,0x6a,0x61,0x7c,0x77,0x1e,0x15,0x08,0x03,0x32,0x39,0x24,0x2f,
	0x8d,0x86,0x9b,0x90,0xa1,0xaa,0xb7,0xbc,0xd5,0xde,0xc3,0xc8,0xf9,0xf2,0xef,0xe4,
	0x3d,0x36,0x2b,0x20,0x11,0x1a,0x07,0x0c,0x65,0x6e,0x73,0x78,0x49,0x42,0x5f,0x54,
	0xf7,0xfc,0xe1,0xea,0xdb,0xd0,0xcd,0xc6,0xaf,0xa4,0xb9,0xb2,0x83,0x88,0x95,0x9e,
	0x47,0x4c,0x51,0x5a,0x6b,0x60,0x7d,0x76,0x1f,0x14,0x09,0x02,0x33,0x38,0x25,0x2e,
	0x8c,0x87,0x9a,0x91,0xa0,0xab,0xb6,0xbd,0xd4,0xdf,0xc2,0xc9,0xf8,0xf3,0xee,0xe5,
	0x3c,0x37,0x2a,0x21,0x10,0x1b,0x06,0x0d,0x64,0x6f,0x72,0x79,0x48,0x43,0x5e,0x55,
	0x01,0x0a,0x17,0x1c,0x2d,0x26,0x3b,0x30,0x59,0x52,0x4f,0x44,0x75,0x7e,0x63,0x68,
	0xb1,0xba,0xa7,0xac,0x9d,0x96,0x8b,0x80,0xe9,0xe2,0xff,0xf4,0xc5,0xce,0xd3,0xd8,
	0x7a,0x71,0x6c,0x67,0x56,0x5d,0x40,0x4b,0x22,0x29,0x34,0x3f,0x0e,0x05,0x18,0x13,
	0xca,0xc1,0xdc,0xd7,0xe6,0xed,0xf0,0xfb,0x92,0x99,0x84,0x8f,0xbe,0xb5,0xa8,0xa3
};

const unsigned char mul13[256] =
{
	0x00,0x0d,0x1a,0x17,0x34,0x39,0x2e,0x23,0x68,0x65,0x72,0x7f,0x5c,0x51,0x46,0x4b,
	0xd0,0xdd,0xca,0xc7,0xe4,0xe9,0xfe,0xf3,0xb8,0xb5,0xa2,0xaf,0x8c,0x81,0x96,0x9b,
	0xbb,0xb6,0xa1,0xac,0x8f,0x82,0x95,0x98,0xd3,0xde,0xc9,0xc4,0xe7,0xea,0xfd,0xf0,
	0x6b,0x66,0x71,0x7c,0x5f,0x52,0x45,0x48,0x03,0x0e,0x19,0x14,0x37,0x3a,0x2d,0x20,
	0x6d,0x60,0x77,0x7a,0x59,0x54,0x43,0x4e,0x05,0x08,0x1f,0x12,0x31,0x3c,0x2b,0x26,
	0xbd,0xb0,0xa7,0xaa,0x89,0x84,0x93,0x9e,0xd5,0xd8,0xcf,0xc2,0xe1,0xec,0xfb,0xf6,
	0xd6,0xdb,0xcc,0xc1,0xe2,0xef,0xf8,0xf5,0xbe,0xb3,0xa4,0xa9,0x8a,0x87,0x90,0x9d,
	0x06,0x0b,0x1c,0x11,0x32,0x3f,0x28,0x25,0x6e,0x63,0x74,0x79,0x5a,0x57,0x40,0x4d,
	0xda,0xd7,0xc0,0xcd,0xee,0xe3,0xf4,0xf9,0xb2,0xbf,0xa8,0xa5,0x86,0x8b,0x9c,0x91,
	0x0a,0x07,0x10,0x1d,0x3e,0x33,0x24,0x29,0x62,0x6f,0x78,0x75,0x56,0x5b,0x4c,0x41,
	0x61,0x6c,0x7b,0x76,0x55,0x58,0x4f,0x42,0x09,0x04,0x13,0x1e,0x3d,0x30,0x27,0x2a,
	0xb1,0xbc,0xab,0xa6,0x85,0x88,0x9f,0x92,0xd9,0xd4,0xc3,0xce,0xed,0xe0,0xf7,0xfa,
	0xb7,0xba,0xad,0xa0,0x83,0x8e,0x99,0x94,0xdf,0xd2,0xc5,0xc8,0xeb,0xe6,0xf1,0xfc,
	0x67,0x6a,0x7d,0x70,0x53,0x5e,0x49,0x44,0x0f,0x02,0x15,0x18,0x3b,0x36,0x21,0x2c,
	0x0c,0x01,0x16,0x1b,0x38,0x35,0x22,0x2f,0x64,0x69,0x7e,0x73,0x50,0x5d,0x4a,0x47,
	0xdc,0xd1,0xc6,0xcb,0xe8,0xe5,0xf2,0xff,0xb4,0xb9,0xae,0xa3,0x80,0x8d,0x9a,0x97
};

const unsigned char mul14[256] =
{
	0x00,0x0e,0x1c,0x12,0x38,0x36,0x24,0x2a,0x70,0x7e,0x6c,0x62,0x48,0x46,0x54,0x5a,
	0xe0,0xee,0xfc,0xf2,0xd8,0xd6,0xc4,0xca,0x90,0x9e,0x8c,0x82,0xa8,0xa6,0xb4,0xba,
	0xdb,0xd5,0xc7,0xc9,0xe3,0xed,0xff,0xf1,0xab,0xa5,0xb7,0xb9,0x93,0x9d,0x8f,0x81,
	0x3b,0x35,0x27,0x29,0x03,0x0d,0x1f,0x11,0x4b,0x45,0x57,0x59,0x73,0x7d,0x6f,0x61,
	0xad,0xa3,0xb1,0xbf,0x95,0x9b,0x89,0x87,0xdd,0xd3,0xc1,0xcf,0xe5,0xeb,0xf9,0xf7,
	0x4d,0x43,0x51,0x5f,0x75,0x7b,0x69,0x67,0x3d,0x33,0x21,0x2f,0x05,0x0b,0x19,0x17,
	0x76,0x78,0x6a,0x64,0x4e,0x40,0x52,0x5c,0x06,0x08,0x1a,0x14,0x3e,0x30,0x22,0x2c,
	0x96,0x98,0x8a,0x84,0xae,0xa0,0xb2,0xbc,0xe6,0xe8,0xfa,0xf4,0xde,0xd0,0xc2,0xcc,
	0x41,0x4f,0x5d,0x53,0x79,0x77,0x65,0x6b,0x31,0x3f,0x2d,0x23,0x09,0x07,0x15,0x1b,
	0xa1,0xaf,0xbd,0xb3,0x99,0x97,0x85,0x8b,0xd1,0xdf,0xcd,0xc3,0xe9,0xe7,0xf5,0xfb,
	0x9a,0x94,0x86,0x88,0xa2,0xac,0xbe,0xb0,0xea,0xe4,0xf6,0xf8,0xd2,0xdc,0xce,0xc0,
	0x7a,0x74,0x66,0x68,0x42,0x4c,0x5e,0x50,0x0a,0x04,0x16,0x18,0x32,0x3c,0x2e,0x20,
	0xec,0xe2,0xf0,0xfe,0xd4,0xda,0xc8,0xc6,0x9c,0x92,0x80,0x8e,0xa4,0xaa,0xb8,0xb6,
	0x0c,0x02,0x10,0x1e,0x34,0x3a,0x28,0x26,0x7c,0x72,0x60,0x6e,0x44,0x4a,0x58,0x56,
	0x37,0x39,0x2b,0x25,0x0f,0x01,0x13,0x1d,0x47,0x49,0x5b,0x55,0x7f,0x71,0x63,0x6d,
	0xd7,0xd9,0xcb,0xc5,0xef,0xe1,0xf3,0xfd,0xa7,0xa9,0xbb,0xb5,0x9f,0x91,0x83,0x8d
};

const unsigned char rcon[256] =
{
	0x8d,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36,0x6c,0xd8,0xab,0x4d,0x9a,
	0x2f,0x5e,0xbc,0x63,0xc6,0x97,0x35,0x6a,0xd4,0xb3,0x7d,0xfa,0xef,0xc5,0x91,0x39,
	0x72,0xe4,0xd3,0x8d,0x61,0xc2,0x9f,0x25,0x4a,0x94,0x33,0x66,0xcc,0x83,0x1d,0x3a,
	0x74,0xe8,0xcb,0xbd,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36,0x6c,0xd8,
};

int strLenght(const char* message)
{
	int index = 0;
	while (message[index++] != '\0');

	return index - 1;
}

void KeyExpansionCore(unsigned char* in, unsigned char i)
{
	//Rotate left
	unsigned char t = in[0];
	in[0] = in[1];
	in[1] = in[2];
	in[2] = in[3];
	in[3] = t;

	//unsigned int* q = (unsigned int*)in;
	//*q = (*q >> 8) | ((*q & 0xff) << 24);

	//S-Box four bytes
	in[0] = S_BOX[in[0]];
	in[1] = S_BOX[in[1]];
	in[2] = S_BOX[in[2]];
	in[3] = S_BOX[in[3]];

	//RCon
	in[0] ^= rcon[i];
}

void keyExpansion(unsigned char* inputKey, unsigned char* expandedKeys)
{
	//The first 16 bytes are original key
	for (int i = 0;i < 16;i++)
	{
		expandedKeys[i] = inputKey[i];
	}

	int bytesGenerated = 16;//We've generated 16 bytes
	int rconIteration = 1;//RCon iteration begins at 1;
	unsigned char temp[4];//Temporary storage for core

	while (bytesGenerated < 176)
	{
		//Read 4 bytes for the core
		for (int i = 0;i < 4;i++)
		{
			temp[i] = expandedKeys[i + bytesGenerated - 4];
		}

		// Perform the core once for each 16 byte key:
		if (bytesGenerated % 16 == 0)
		{
			KeyExpansionCore(temp, rconIteration);
			rconIteration++;
		}

		//XOR temp with [bytesGenerated-16], and store in expandedKeys:
		for (unsigned char a = 0;a < 4;a++)
		{
			expandedKeys[bytesGenerated] =
				expandedKeys[bytesGenerated - 16] ^ temp[a];
			bytesGenerated++;
		}
	}
}

void subBytes(unsigned char* state)
{
	for (int i = 0;i < 16;i++)
	{
		state[i] = S_BOX[state[i]];
	}
}

void shiftRows(unsigned char* state)
{
	char tmp[16] = {};

	tmp[0] = state[0];
	tmp[1] = state[5];
	tmp[2] = state[10];
	tmp[3] = state[15];

	tmp[4] = state[4];
	tmp[5] = state[9];
	tmp[6] = state[14];
	tmp[7] = state[3];

	tmp[8] = state[8];
	tmp[9] = state[13];
	tmp[10] = state[2];
	tmp[11] = state[7];

	tmp[12] = state[12];
	tmp[13] = state[1];
	tmp[14] = state[6];
	tmp[15] = state[11];

	for (int i = 0; i < 16; i++)
	{
		state[i] = tmp[i];
	}
}

/*
Mix Columns is matrix multiplication, where we multiply values of hec value of charachters whit encryption standart matrix
First Matrix is our state and the second one is encryption standart matrix
	2 3 1 1
	1 2 3 1
	1 1 2 3
	3 1 1 2
	Example
	[d0] = [2 3 1 1] [b0]
	[d1] = [1 2 3 1] [b1]
	[d2] = [1 1 2 3] [b2]
	[d3] = [3 1 1 2] [b3]
	The sum of values from every multiplictions happens with XOR
	[d0] = 2*b0 ^ 3*b0 ^ 1*b0 ^ 1b0
	[d1] = 1*b0 ^ 2*b0 ^ 3*b0 ^ 1b0
	[d2] = 1*b0 ^ 1*b0 ^ 2*b0 ^ 3b0
	[d3] = 3*b0 ^ 1*b0 ^ 1*b0 ^ 2b0
*/
void mixColums(unsigned char* state)
{
	char tmp[16] = {};

	tmp[0] = (unsigned char)(mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3]);
	tmp[1] = (unsigned char)(state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3]);
	tmp[2] = (unsigned char)(state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]]);
	tmp[3] = (unsigned char)(mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]]);

	tmp[4] = (unsigned char)(mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7]);
	tmp[5] = (unsigned char)(state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7]);
	tmp[6] = (unsigned char)(state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]]);
	tmp[7] = (unsigned char)(mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]]);

	tmp[8] = (unsigned char)(mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11]);
	tmp[9] = (unsigned char)(state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11]);
	tmp[10] = (unsigned char)(state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]]);
	tmp[11] = (unsigned char)(mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]]);

	tmp[12] = (unsigned char)(mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15]);
	tmp[13] = (unsigned char)(state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15]);
	tmp[14] = (unsigned char)(state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]]);
	tmp[15] = (unsigned char)(mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]]);

	for (int i = 0;i < 16;i++)
	{
		state[i] = tmp[i];
	}
}

void addRoundKey(unsigned char* state, unsigned char* roundKey)
{
	for (int i = 0; i < 16;i++)
	{
		state[i] = state[i] ^ roundKey[i];
	}
}

void aesEncrypt(unsigned char* message, unsigned char* key)
{
	unsigned char state[16] = {};
	for (int i = 0;i < 16;i++)
	{
		state[i] = message[i];
	}

	int numberOfRounds = 9;

	//Expand the keys:
	unsigned char expandedKey[176];
	keyExpansion(key, expandedKey);

	addRoundKey(state, key);	//Whitening/AddRoundKey

	//Rounds
	for (int i = 0; i < numberOfRounds;i++)
	{
		subBytes(state);
		shiftRows(state);
		mixColums(state);
		addRoundKey(state, expandedKey + (16 * (i + 1)));
	}
	//Final round
	subBytes(state);
	shiftRows(state);
	addRoundKey(state, expandedKey + 160);

	//Copy encrypted state to message:
	for (int i = 0;i < 16;i++)
	{
		message[i] = state[i];
	}

	//print expanded key -> used to get the key from encrypted message
	/*std::cout << std::endl;
	for (int i = 0;i < 176;i++)
	{
		if (i != 0 && i % 16 == 0) std::cout << std::endl;
		std::cout << (int)expandedKey[i] << ", ";
	}*/
}

void printHex(unsigned char x)
{
	if (x / 16 < 10) std::cout << (char)((x / 16) + '0');
	if (x / 16 >= 10) std::cout << (char)((x / 16 - 10) + 'A');

	if (x % 16 < 10) std::cout << (char)((x % 16) + '0');
	if (x % 16 >= 10) std::cout << (char)((x % 16 - 10) + 'A');
}

void encrypt(unsigned char* message, unsigned char  key[16])
{
	int originalLen = strLenght((const char*)message);
	int lenOfPaddedMessage = originalLen;

	//If message size is not 16bytes block, we fill the missing bytes with 0 zeros
	if (lenOfPaddedMessage % 16 != 0)
	{
		lenOfPaddedMessage = (lenOfPaddedMessage / 16 + 1) * 16;
	}

	unsigned char* paddedMessage = new unsigned char[lenOfPaddedMessage];
	for (int i = 0; i < lenOfPaddedMessage;i++)
	{
		if (i >= originalLen)
		{
			paddedMessage[i] = 0;
		}
		else
		{
			paddedMessage[i] = message[i];
		}
	}

	//Encrypted padded message:
	for (int i = 0;i < lenOfPaddedMessage;i += 16) {
		aesEncrypt(paddedMessage + i, key);
	}

	std::cout << "Encrypted message:" << std::endl;
	for (int i = 0;i < lenOfPaddedMessage;i++)
	{
		printHex(paddedMessage[i]);
		std::cout << " ";
	}

	delete[] paddedMessage;
}

void reverseShiftRows(unsigned char* state)
{
	char tmp[16] = {};

	tmp[0] = state[0];
	tmp[5] = state[1];
	tmp[10] = state[2];
	tmp[15] = state[3];

	tmp[4] = state[4];
	tmp[9] = state[5];
	tmp[14] = state[6];
	tmp[3] = state[7];

	tmp[8] = state[8];
	tmp[13] = state[9];
	tmp[2] = state[10];
	tmp[7] = state[11];

	tmp[12] = state[12];
	tmp[1] = state[13];
	tmp[6] = state[14];
	tmp[11] = state[15];

	for (int i = 0; i < 16; i++)
	{
		state[i] = tmp[i];
	}
}

void inverseSubBytes(unsigned char* state)
{
	for (int i = 0;i < 16;i++)
	{
		state[i] = INVERSE_S_BOX[state[i]];
	}
}

/*
Inverse Mix Columns is matrix multiplication, where we multiply values of hex value of charachters whith encryption standart matrix
First Matrix is encryption standart matrix and the second one is our first 4 charachter
On every 4 charachters we do matrix multiplication
	14 11 13 9
	 9 14 11 13
	13  9 14 11
	11 13  9 14
	Example
	[b0] = [14 11 13  9] [d0]
	[b1] = [ 9 14 11 13] [d1]
	[b2] = [13  9 14 11] [d2]
	[b3] = [11 13 9  14] [d3]
	The sum of values from every multiplictions happens with XOR
	[d0] = 14*b0 ^ 11*b0 ^ 13*b0 ^  9b0
	[d1] =  9*b0 ^ 14*b0 ^ 11*b0 ^ 13b0
	[d2] = 13*b0 ^  9*b0 ^ 14*b0 ^ 11b0
	[d3] = 11*b0 ^ 13*b0 ^  9*b0 ^ 14b0
*/
void inverseMixColums(unsigned char* state)
{
	char tmp[16] = {};

	tmp[0] = (unsigned char)(mul14[state[0]] ^ mul11[state[1]] ^ mul13[state[2]] ^ mul9[state[3]]);
	tmp[1] = (unsigned char)(mul9[state[0]] ^ mul14[state[1]] ^ mul11[state[2]] ^ mul13[state[3]]);
	tmp[2] = (unsigned char)(mul13[state[0]] ^ mul9[state[1]] ^ mul14[state[2]] ^ mul11[state[3]]);
	tmp[3] = (unsigned char)(mul11[state[0]] ^ mul13[state[1]] ^ mul9[state[2]] ^ mul14[state[3]]);

	tmp[4] = (unsigned char)(mul14[state[4]] ^ mul11[state[5]] ^ mul13[state[6]] ^ mul9[state[7]]);
	tmp[5] = (unsigned char)(mul9[state[4]] ^ mul14[state[5]] ^ mul11[state[6]] ^ mul13[state[7]]);
	tmp[6] = (unsigned char)(mul13[state[4]] ^ mul9[state[5]] ^ mul14[state[6]] ^ mul11[state[7]]);
	tmp[7] = (unsigned char)(mul11[state[4]] ^ mul13[state[5]] ^ mul9[state[6]] ^ mul14[state[7]]);

	tmp[8] = (unsigned char)(mul14[state[8]] ^ mul11[state[9]] ^ mul13[state[10]] ^ mul9[state[11]]);
	tmp[9] = (unsigned char)(mul9[state[8]] ^ mul14[state[9]] ^ mul11[state[10]] ^ mul13[state[11]]);
	tmp[10] = (unsigned char)(mul13[state[8]] ^ mul9[state[9]] ^ mul14[state[10]] ^ mul11[state[11]]);
	tmp[11] = (unsigned char)(mul11[state[8]] ^ mul13[state[9]] ^ mul9[state[10]] ^ mul14[state[11]]);

	tmp[12] = (unsigned char)(mul14[state[12]] ^ mul11[state[13]] ^ mul13[state[14]] ^ mul9[state[15]]);
	tmp[13] = (unsigned char)(mul9[state[12]] ^ mul14[state[13]] ^ mul11[state[14]] ^ mul13[state[15]]);
	tmp[14] = (unsigned char)(mul13[state[12]] ^ mul9[state[13]] ^ mul14[state[14]] ^ mul11[state[15]]);
	tmp[15] = (unsigned char)(mul11[state[12]] ^ mul13[state[13]] ^ mul9[state[14]] ^ mul14[state[15]]);

	for (int i = 0;i < 16;i++)
	{
		state[i] = tmp[i];
	}

}

void aesDecrypt(unsigned char* message, unsigned char* expandedKey, int block)
{
	unsigned char state[16] = {};
	for (int i = 0;i < 16;i++)
	{
		state[i] = message[i];
	}

	addRoundKey(state, expandedKey + 160);
	reverseShiftRows(state);
	inverseSubBytes(state);
	int numberOfRounds = 9;

	for (int i = numberOfRounds; i > 0;i--)
	{
		addRoundKey(state, expandedKey + (16 * (i)));
		inverseMixColums(state);
		reverseShiftRows(state);
		inverseSubBytes(state);
	}

	addRoundKey(state, expandedKey);

	//Copy decrypted state to message:
	for (int i = 0;i < 16;i++)
	{
		message[i] = state[i];
	}
}


bool isHEXSymbol(unsigned char& ch)
{
	if ((ch >= 'A' && ch <= 'F') || (ch >= '0' && ch <= '9'))
	{
		return true;
	}
	else if (ch >= 'a' && ch <= 'f')
	{
		ch -= 32;
		return true;
	}
	else
	{
		return false;
	}
}

int hexCharToDecimal(char hexChar) {
	
	switch (hexChar) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		default:
			return -1;
	}
}

int countOfWords(unsigned char* message, int lenght)
{
	if (!*countOfWords)
	{
		return -1;
	}

	int wordsCounter = 0;
	int characterCounter = 0;
	for (int i = 0; i < lenght;i++)
	{
		if (isHEXSymbol(message[i]))
		{
			characterCounter++;
		}
		else if (message[i] == ' ')
		{
			if (characterCounter == 2)
			{
				wordsCounter++;
				characterCounter = 0;
			}
			else if (characterCounter != 0)
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}

	if (message[lenght - 1] != ' ')
	{
		wordsCounter++;
	}

	return wordsCounter;
}

void hexToDecimal(unsigned char* encryptedMessage, int originalLen, unsigned char* message, int lenOfOriginalMessage)
{
	int decimalResult = 0;
	int messageInd = 0;
	for (int i = 0; i < originalLen;i++)
	{
		if (isHEXSymbol(encryptedMessage[i]))
		{
			decimalResult = 16 * decimalResult + hexCharToDecimal(encryptedMessage[i]);
		}
		else if (i > 0 && encryptedMessage[i - 1] != ' ')
		{
			message[messageInd] = decimalResult;
			decimalResult = 0;
			messageInd++;
		}
	}
	if (encryptedMessage[originalLen - 1] != ' ')
	{
		message[messageInd++] = decimalResult;
	}
}

void decrypt(unsigned char* encryptedMessage, unsigned char* expandedKey)
{
	int originalLen = strLenght((const char*)encryptedMessage);
	int lenOfOriginalMessage = countOfWords(encryptedMessage, originalLen);

	if (lenOfOriginalMessage < 0)
	{
		std::cout << "Invalid input!\n Your encrypted message should be in HEX!";
		return;
	}

	unsigned char* message = new unsigned char[lenOfOriginalMessage];

	hexToDecimal(encryptedMessage, originalLen, message, lenOfOriginalMessage);

	//Encrypted padded message:
	for (int i = lenOfOriginalMessage / 16 - 1;i >= 0;i--) {
		aesDecrypt(message + i * 16, expandedKey, i);
	}

	std::cout << "\nDecrypted message:" << std::endl;
	for (int i = 0;i < lenOfOriginalMessage;i++)
	{
		std::cout << *(message + i);
	}

	delete[] message;
}


int main()
{
	unsigned char message[] = "This is a message we will encrypt with AES!";
	unsigned char key[16] =
	{
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};
	encrypt(message, key);
	std::cout << std::endl;

	unsigned char finalMessage[] = "B6 4B 27 BB 16 15 A6 F5 32 18 6C C5 FA 94 B5 5E 5C  54 EA 1B DF 97 1E 3D E3 1B FC 02 75 22 76 52 D5 7B D5 42 BA 0F 68 50 CD FD 59 B8 EB 0E 83 D1 ";
	unsigned char expandedKey[176] =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		171, 116, 201, 211, 174, 114, 206, 219, 167, 120, 197, 215, 170, 118, 202, 199,
		145, 0, 15, 127, 63, 114, 193, 164, 152, 10, 4, 115, 50, 124, 206, 180,
		133, 139, 130, 92, 186, 249, 67, 248, 34, 243, 71, 139, 16, 143, 137, 63,
		254, 44, 247, 150, 68, 213, 180, 110, 102, 38, 243, 229, 118, 169, 122, 218,
		61, 246, 160, 174, 121, 35, 20, 192, 31, 5, 231, 37, 105, 172, 157, 255,
		140, 168, 182, 87, 245, 139, 162, 151, 234, 142, 69, 178, 131, 34, 216, 77,
		95, 201, 85, 187, 170, 66, 247, 44, 64, 204, 178, 158, 195, 238, 106, 211,
		247, 203, 51, 149, 93, 137, 196, 185, 29, 69, 118, 39, 222, 171, 28, 244,
		142, 87, 140, 136, 211, 222, 72, 49, 206, 155, 62, 22, 16, 48, 34, 226,
		188, 196, 20, 66, 111, 26, 92, 115, 161, 129, 98, 101, 177, 177, 64, 135
	};
	decrypt(finalMessage, expandedKey);

	return 0;
}