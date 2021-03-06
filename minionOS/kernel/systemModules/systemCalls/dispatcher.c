#include <stdbool.h>
#include "systemCallNumber.h"
#include "kernel/systemModules/systemCalls/dispatcher.h"
#include "kernel/hal/led/led.h"
#include "kernel/systemModules/filesystem/vfs.h"
#include "kernel/hal/dmx/dmx.h"
#include "drivers/dmx/tmh7/dmxTmh7.h"
#include "drivers/dmx/mhx25/dmxMhx25.h"
#include "kernel/systemModules/loader/loader.h"


int dispatcher_dispatch(SysCallArgs_t args) {
    switch (args.systemCallNumber) {
    case SYSCALL_FILE_OPEN:
        return vfs_open((const char*) args.a);
    case SYSCALL_FILE_READ:
        return vfs_read(args.a, (uint8_t*) args.b, args.c);
    case SYSCALL_FILE_WRITE:
        vfs_write(args.a, (const uint8_t*) args.b, args.c);
        break;
    case SYSCALL_FILE_CLOSE:
        vfs_close(args.a);
        break;
    case SYSCALL_READDIR:
        return (int) vfs_readdir((const char*) args.a);
    case SYSCALL_LOAD_PROGRAM:
        return loader_loadProcess((const char*) args.a, ELF);
    }
    return -1;
}

