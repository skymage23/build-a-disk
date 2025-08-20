#ifndef BUILD_A_DISK_COMMON
#define BUILD_A_DISK_COMMON

#include "platform_check.h"

#include <stdint.h>
#include <stddef.h>
#include "partitions.h"
//Data structures:
typedef struct BuildADiskPartition {
    char* name;
    size_t name_size;
    size_t partition_size;
    char* backing_file_path;
    size_t file_path_size;
} BuildADiskPartition;

//GUID Partition Table:
typedef struct BuildADiskGPTHeader {
    uint64_t signature;  //little endian required.
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;  //little endian required.
    uint32_t reserved;
    uint64_t current_lba;
    uint64_t backup_lba;
    uint64_t first_useable_lba;
    uint64_t last_usable_lba;
    uint16_t disk_guid;  //little endian required.
    uint64_t partition_array_start_lba;
    uint32_t num_partitions;
    uint32_t partition_array_element_size;
    uint32_t crc32_partition_array_entries; //little endian required.
    //rest of the block must be zero'd out.
} BuildADiskGPTHeader;

typedef struct BuildADiskGPT {
    BuildADiskGPTHeader header;
} BuildADiskGPT;





//Helper functions.

#endif
