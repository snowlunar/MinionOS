#ifndef APPLICATIONS_SYSTEMCALLAPI_H_
#define APPLICATIONS_SYSTEMCALLAPI_H_

#include <stdbool.h>
#include <inttypes.h>

#define LED_0   0
#define LED_1   1

void sysCalls_ctrlDmx(const uint8_t * buffer, uint16_t bufferSize);

void sysCalls_enableLed(bool turnOn, int led);

int sysCalls_openFile(const char* fileName);

int sysCalls_readFile(int fileDescriptor, uint8_t* buffer, unsigned int bufferSize);

void sysCalls_writeFile(int fileDescriptor, const uint8_t* buffer, unsigned int bufferSize);

const char* sysCalls_readDirectory(const char* directoryName);

void sysCalls_closeFile(int fileDescriptor);

int sysCalls_loadProgramm(const char* fileName);

#endif /* APPLICATIONS_SYSTEMCALLAPI_H_ */
