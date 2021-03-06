#include "systemCallArguments.h"
#include "systemCallNumber.h"
#include "systemCallApi.h"

#pragma SWI_ALIAS(makeSysCall, SYSTEM_CALL_SWI_NUMBER);
static int makeSysCall(SysCallArgs_t args);

int sysCalls_openFile(const char* fileName) {
    SysCallArgs_t args = { SYSCALL_FILE_OPEN, (int) fileName };
    return makeSysCall(args);
}

int sysCalls_readFile(int fileDescriptor, uint8_t* buffer, unsigned int bufferSize) {
    SysCallArgs_t args = { SYSCALL_FILE_READ, fileDescriptor, (int) buffer, bufferSize };
    return makeSysCall(args);
}

void sysCalls_writeFile(int fileDescriptor, const uint8_t* buffer, unsigned int bufferSize) {
    SysCallArgs_t args = { SYSCALL_FILE_WRITE, fileDescriptor, (int) buffer, bufferSize };
    makeSysCall(args);
}

void sysCalls_closeFile(int fileDescriptor) {
    SysCallArgs_t args = { SYSCALL_FILE_CLOSE, fileDescriptor };
    makeSysCall(args);
}

const char* sysCalls_readDirectory(const char* directoryName) {
    SysCallArgs_t args = { SYSCALL_READDIR, (int) directoryName };
    return (const char*) makeSysCall(args);
}

int sysCalls_loadProgramm(const char* fileName) {
    SysCallArgs_t args = { SYSCALL_LOAD_PROGRAM, (int) fileName };
    return makeSysCall(args);
}
