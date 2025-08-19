#ifndef BUILDADISK_PARTITION_H
#if !defined __linux__ || !defined __APPLE__
#error "You are building for an unsupported platform. We must stop here. Supported platforms are Linux and Mac OS."
#endif

#define BUILDADISK_PARTITION_H

#define PARTITION_NAME_BYTE_LIMIT 72
typedef struct BuildADiskGPTPartitionEntry {
    uint16_t partition_type_guid; //Little endian required.
    uint16_t partition_guid;  //Little endian required.
    uint64_t first_lba  //little endian required.
    uint64_t last_lba //inclusive, little endian
    uint64_t attribute_flags;
    char part_name[PARTITION_NAME_BYTE_LIMIT];  //(36 UTF-16LE code units)
} BuildADiskGPTPartitionEntry;

typedef struct PartFlagMap {
    char* name;
    uint32_t name_size;
    uint16_t flag_index;
} PartFlagMap;

typedef struct BuildADiskPartition { 
    BuildADiskGPTPartitionEntry gpt_entry;
    char* backing_filename;
}

//Generic GPT partition flags:
#define PART_ATTR_NAME_PLATFORM_REQUIRED "platform_required"
#define PART_ATTR_MASK_PLATFORM_REQUIRED 0x0000000000000001

#define PART_ATTR_NAME_EFI		 "efi"
#define PART_ATTR_MASK_EFI               0x0000000000000002

#define PART_ATTR_NAME_BIOS_BOOTABLE     "BIOS Bootable"
#define PART_ATTR_MASK_BIOS_BOOTABLE     0x0000000000000004

#define PART_ATTR_RANGE_MASK_FUTURE_RESERVED   0x00007FFFFFFFFFF8
#define PART_ATTR_RANGE_MASK_PART_TYPE_DEF     0xFFFF800000000000

//Microsoft Basic Data Partition Flags:
#define PART_ATTR_MASK_MS_READ_ONLY          0x10000000000000000000
#define PART_ATTR_MASK_MS_SHADOW_COPY        0x20000000000000000000
#define PART_ATTR_MASK_MS_HIDDEN             0x40000000000000000000
#define PART_ATTR_MASK_MS_NO_DRIVE_LETTER    0x80000000000000000000  


//function defs:
void load_vendor_flag_maps();
void init_part_flag_maps();
BuildADiskGPTPartitionEntry BuildADiskGPTPartitionEnty_new();
BuildADiskPartition_new();


#endif
