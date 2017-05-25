#ifndef __UART
#define __UART

#include <inttypes.h>
#include <stdbool.h>

typedef enum {
    UART1,
    UART2,
    UART3
} UartModule_t;

typedef enum {
    NO_PARITY,
    ODD_PARITY,
    EVEN_PARITY,
    FORCED_1,
    FORCED_0
} UartParityMode_t;

typedef enum {
    STOP_1,
    STOP_1_5
} UartStopMode_t;

typedef enum {
    LENGTH_5,
    LENGTH_6,
    LENGTH_7,
    LENGTH_8
} UartWordLength_t;

typedef enum {
    x16,
    x13
} UartBaudMultiple_t;

typedef struct {
    UartParityMode_t parityMode;
    UartStopMode_t stopMode;
    UartWordLength_t wordLength;
    uint64_t baudRate;
    UartBaudMultiple_t baudMultiple;
} UartConfig_t;


void receive(UartModule_t module, uint8_t* buffer, uint32_t bufferSize);

void transmit(UartModule_t module, const uint8_t* buffer, uint32_t bufferSize);

void enableModule(UartModule_t module);

void disableModule(UartModule_t module);

void initModule(UartModule_t module, UartConfig_t config);

#endif
