#ifndef KERNEL_SYSTEMMODULES_SYSTEMCALLS_SYSTEMCALLNUMBER_H_
#define KERNEL_SYSTEMMODULES_SYSTEMCALLS_SYSTEMCALLNUMBER_H_

typedef enum {
    SYSCALL_DMX_SEND,
    SYSCALL_DMX_CREATE_PACKET,
    SYSCALL_LED,
    SYSCALL_FILE_OPEN,
    SYSCALL_FILE_READ,
    SYSCALL_FILE_WRITE,
    SYSCALL_FILE_CLOSE,
    SYSCALL_READDIR,
    SYSCALL_LOAD_PROGRAM
} SystemCallNumber;

#endif /* KERNEL_SYSTEMMODULES_SYSTEMCALLS_SYSTEMCALLNUMBER_H_ */
