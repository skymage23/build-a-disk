#ifndef BUILD_A_DISK_DISK_H
#define BUILD_A_DISK

#include <stddef.h>

typedef struct BuildADiskDisk {
    char* name;
    size_t name_size;
    char* 
    unsigned short num_partitions;
} BuildADiskDisk;

//Functions:
BuildADiskDisk BuildADiskDisk_new();


#endif