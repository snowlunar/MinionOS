/*
 * Common.h
 *
 *  Created on: 5 Apr 2017
 *      Author: Mathias
 */

#ifndef KERNEL_COMMON_MMIO_H_
#define KERNEL_COMMON_MMIO_H_

#include <inttypes.h>
#include "../../global/bitManipulation.h"

#define NULLPOINTER     0x00000000

/**
 * Provides basic methods to set and get a value at a given address.
 */
extern void set32(uint32_t address, uint32_t value);
extern uint32_t get32(uint32_t address);
extern void or32(uint32_t address, uint32_t value);
extern void and32(uint32_t address, uint32_t value);
extern void clear32(uint32_t address, uint32_t value);


#endif /* KERNEL_COMMON_MMIO_H_ */
