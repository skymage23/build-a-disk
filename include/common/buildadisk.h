#ifndef BUILD_A_DISK
#define BUILD_A_DISK

#include "platform_check.h"

#include "buildadisk_disk.h"
#include <stddef.h>

typedef struct BuildADiskDisk {
    char* name;
    size_t name_size;
    unsigned short num_partitions;
} BuildADiskDisk;

typedef struct BuildADisk {
    BuildADiskPartitionFlagMap part_flag_map;
    char* disk_path;
    size_t disk_path_size;
    BuildADiskDisk curr_disk;
} BuildADisk;

//functions
BuildADisk BuildADisk_new();
bool BuildADisk_commit_to_backing_store(BuildADisk disk);
bool BuildADisk_add_partition(BuildADisk disk);
bool BuildADisk_remove_partition(BuildADisk disk)
#endif