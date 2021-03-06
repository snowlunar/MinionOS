/*
 * processManager.c
 *
 *  Created on: 17 Apr 2017
 *      Author: Mathias
 */

#include "processManager.h"

int8_t processManager_loadProcess(uint32_t physicalStartAddress, uint32_t nrOfNeededBytes, uint32_t stackPointer, uint32_t entryPoint){
    PCB_t* pPcb = scheduler_startProcess(entryPoint, stackPointer, 0x60000110);
    return mmu_initProcess(physicalStartAddress, VIRTUAL_MEMORY_START_ADDRESS, nrOfNeededBytes, pPcb, 1);
}

uint32_t* processManager_getPhysicalMemoryForProcess(uint32_t nrOfNeededBytes) {
    uint32_t* pAddress = mmu_getPhysicalMemoryForProcess(nrOfNeededBytes);
    mmu_mapRegionDirectly((uint32_t)pAddress, nrOfNeededBytes, SECTION);
    return pAddress;
}

void processManager_killProcess(ProcessId_t processId) {
    mmu_killProcess(processId);
    scheduler_stopProcess(processId);
}

void processManager_terminateCurrentProcess(PCB_t* pcb) {
    scheduler_terminateCurrentProcess(pcb);
}
