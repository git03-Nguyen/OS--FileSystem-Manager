#pragma once

#pragma pack(push, 1)
struct FAT32_BS {
	uint8_t jmpBoot[3];	// 0x00
	char OEM_id[8];		// 0x03
	uint16_t bytesPerSec; // 0x0B
	uint8_t secPerClus;	// 0x0D
	uint16_t rsvdSec;	// 0x0E
	uint8_t numFATs;	// 0x10
	uint16_t RDETcnt16;	// 0x11
	uint16_t numSecs16;	// 0x13
	uint8_t media;		// 0x15 // val 0xF8 for hard disk
	uint16_t secPerFAT16; // 0x16
	uint16_t secPerTrk;	// 0x18
	uint16_t numHeads;	// 0x1A
	uint32_t hiddSecs;	// 0x1C
	uint32_t numSecs;	// 0x20
	uint32_t secPerFAT;	// 0x24
	uint16_t extFlags;	// 0x28
	uint8_t minFAT32Ver; // 0x2A
	uint8_t majFAT32Ver; // 0x2B
	uint32_t rootClus;	// 0x2C
	uint16_t infoFS;	// 0x30
	uint16_t backupBootSec;	// 0x32
	uint8_t reserved[12];	// 0x34
	uint8_t logicDrvNum; // 0x40
	uint8_t unused;		// 0x41
	uint8_t extSig;		// 0x42 - 29h
	uint32_t partitionSerial; // 0x43
	char volName[11]; // 0x47
	char FATname[8]; // 0x52 - FAT32
	char excutableCode[420]; // 0x5A
	uint16_t bootRecSig; // 0x1FE - 0xAA55
};
#pragma pack(pop)

#define _FAT32_BS_FOR_TEST  {															\
			0xEB, 0x58, 0x90, 0x4D, 0x53, 0x44, 0x4F, 0x53, 0x35, 0x2E, 0x30, 0x00,		\
			0x02, 0x10, 0x90, 0x0D, 0x02, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00,		\
			0x3F, 0x00, 0xFF, 0x00, 0x20, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0xCA, 0x01,		\
			0x38, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,		\
			0x01, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x29, 0xAE, 0xA2, 0x14, 0xD0, 0x4E,		\
			0x4F, 0x20, 0x4E, 0x41, 0x4D, 0x45, 0x20, 0x20, 0x20, 0x20, 0x46, 0x41,		\
			0x54, 0x33, 0x32, 0x20, 0x20, 0x20, 0x33, 0xC9, 0x8E, 0xD1, 0xBC, 0xF4,		\
			0x7B, 0x8E, 0xC1, 0x8E, 0xD9, 0xBD, 0x00, 0x7C, 0x88, 0x56, 0x40, 0x88,		\
			0x4E, 0x02, 0x8A, 0x56, 0x40, 0xB4, 0x41, 0xBB, 0xAA, 0x55, 0xCD, 0x13,		\
			0x72, 0x10, 0x81, 0xFB, 0x55, 0xAA, 0x75, 0x0A, 0xF6, 0xC1, 0x01, 0x74,		\
			0x05, 0xFE, 0x46, 0x02, 0xEB, 0x2D, 0x8A, 0x56, 0x40, 0xB4, 0x08, 0xCD,		\
			0x13, 0x73, 0x05, 0xB9, 0xFF, 0xFF, 0x8A, 0xF1, 0x66, 0x0F, 0xB6, 0xC6,		\
			0x40, 0x66, 0x0F, 0xB6, 0xD1, 0x80, 0xE2, 0x3F, 0xF7, 0xE2, 0x86, 0xCD,		\
			0xC0, 0xED, 0x06, 0x41, 0x66, 0x0F, 0xB7, 0xC9, 0x66, 0xF7, 0xE1, 0x66,		\
			0x89, 0x46, 0xF8, 0x83, 0x7E, 0x16, 0x00, 0x75, 0x39, 0x83, 0x7E, 0x2A,		\
			0x00, 0x77, 0x33, 0x66, 0x8B, 0x46, 0x1C, 0x66, 0x83, 0xC0, 0x0C, 0xBB,		\
			0x00, 0x80, 0xB9, 0x01, 0x00, 0xE8, 0x2C, 0x00, 0xE9, 0xA8, 0x03, 0xA1,		\
			0xF8, 0x7D, 0x80, 0xC4, 0x7C, 0x8B, 0xF0, 0xAC, 0x84, 0xC0, 0x74, 0x17,		\
			0x3C, 0xFF, 0x74, 0x09, 0xB4, 0x0E, 0xBB, 0x07, 0x00, 0xCD, 0x10, 0xEB,		\
			0xEE, 0xA1, 0xFA, 0x7D, 0xEB, 0xE4, 0xA1, 0x7D, 0x80, 0xEB, 0xDF, 0x98,		\
			0xCD, 0x16, 0xCD, 0x19, 0x66, 0x60, 0x80, 0x7E, 0x02, 0x00, 0x0F, 0x84,		\
			0x20, 0x00, 0x66, 0x6A, 0x00, 0x66, 0x50, 0x06, 0x53, 0x66, 0x68, 0x10,		\
			0x00, 0x01, 0x00, 0xB4, 0x42, 0x8A, 0x56, 0x40, 0x8B, 0xF4, 0xCD, 0x13,		\
			0x66, 0x58, 0x66, 0x58, 0x66, 0x58, 0x66, 0x58, 0xEB, 0x33, 0x66, 0x3B,		\
			0x46, 0xF8, 0x72, 0x03, 0xF9, 0xEB, 0x2A, 0x66, 0x33, 0xD2, 0x66, 0x0F,		\
			0xB7, 0x4E, 0x18, 0x66, 0xF7, 0xF1, 0xFE, 0xC2, 0x8A, 0xCA, 0x66, 0x8B,		\
			0xD0, 0x66, 0xC1, 0xEA, 0x10, 0xF7, 0x76, 0x1A, 0x86, 0xD6, 0x8A, 0x56,		\
			0x40, 0x8A, 0xE8, 0xC0, 0xE4, 0x06, 0x0A, 0xCC, 0xB8, 0x01, 0x02, 0xCD,		\
			0x13, 0x66, 0x61, 0x0F, 0x82, 0x74, 0xFF, 0x81, 0xC3, 0x00, 0x02, 0x66,		\
			0x40, 0x49, 0x75, 0x94, 0xC3, 0x42, 0x4F, 0x4F, 0x54, 0x4D, 0x47, 0x52,		\
			0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x0A, 0x44, 0x69,		\
			0x73, 0x6B, 0x20, 0x65, 0x72, 0x72, 0x6F, 0x72, 0xFF, 0x0D, 0x0A, 0x50,		\
			0x72, 0x65, 0x73, 0x73, 0x20, 0x61, 0x6E, 0x79, 0x20, 0x6B, 0x65, 0x79,		\
			0x20, 0x74, 0x6F, 0x20, 0x72, 0x65, 0x73, 0x74, 0x61, 0x72, 0x74, 0x0D,		\
			0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\
			0xAC, 0x01, 0xB9, 0x01, 0x00, 0x00, 0x55, 0xAA								\
		};


