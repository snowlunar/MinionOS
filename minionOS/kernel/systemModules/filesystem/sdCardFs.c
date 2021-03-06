#include "sdCardFs.h"
#include "fileSystem.h"
#include "kernel/hal/mmc_sd/sdCard.h"
#include <stddef.h>

int sdFs_open(const char* fileName) {
    return fileSystem_openFile((uint8_t*) fileName);
}

void sdFs_close(int fileDescriptor) {
    return fileSystem_closeFile(fileDescriptor);
}

int sdFs_read(int fileDescriptor, uint8_t* buffer, unsigned int bufferSize) {
    int readBytes = fileSystem_readBytes(fileDescriptor, buffer, bufferSize);
    return readBytes;
}

void sdFs_write(int fileDescriptor, const uint8_t* buffer, unsigned int bufferSize) {

}

const char* sdFs_readdir(const char* dirName) {
    return (const char*) fileSystem_getNextEntryInDirectory((uint8_t*) dirName);
}


void sdFs_init() {
    sdCard_initialize_Ch1();
    filesystem_Initialize();
}

FileSystem_t sdCardFs = {
        .close = sdFs_close,
        .open = sdFs_open,
        .read = sdFs_read,
        .write = sdFs_write,
        .readdir = sdFs_readdir,
        .init = sdFs_init
};
