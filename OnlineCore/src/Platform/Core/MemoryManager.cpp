#include "Platform/Core/MemoryManager.h"
#include <cstdlib>
#include "Platform/Core/GlobalVariables.h"
#include "Platform/Core/MutexPrimitive.h"
#include "Platform/Core/WaterMark.h"
#include "nn/mem.h"

namespace nn::nex {
MemoryManager::MemoryManager(const char* watermarkName)
    : dword_8(0), m_pMemoryWaterMark(nullptr), m_pMutex(nullptr) {
    m_pMutex = new MutexPrimitive(true);
    m_pMemoryWaterMark = new WaterMark(watermarkName, true, 60000);
    s_eShutDownState = 0;
}

void* MemoryManager::Allocate(u64 size) {
    ulong aligned = size + 23 & ~7;

    void* ptr = GenericMalloc(aligned);

    *(void**)(ptr) = (void*)MemoryManager::s_fcnFree;
    return (void*)(reinterpret_cast<u64*>(ptr) + 2);
}

void* MemoryManager::GenericMalloc(u64 size) {
    if (s_fcnMalloc)
        return s_fcnMalloc(size);
    else
        return malloc(size);
}

void MemoryManager::Free(void* ptr) {
    if (ptr) {
        void** func = reinterpret_cast<void**>(ptr) - 2;
        void* mem = static_cast<void*>(func);

        GenericFree(reinterpret_cast<fcnFree>(*func), mem);
    }
}

void MemoryManager::GenericFree(fcnFree freeFunc, void* address) {
    if (freeFunc)
        freeFunc(address);
    else
        free(address);
}

void MemoryManager::AllocateThreadSafe(ulong ptr) {
    GlobalVariables::s_pGv->getStandardAllocator()->Allocate(ptr);
}

void MemoryManager::FreeThreadSafe(void* address) {
    GlobalVariables::s_pGv->getStandardAllocator()->Free(address);
}

void MemoryManager::Trace() {}

static const char* s_InstructionTypeStrings[11] = {"Unknown",
                                                   "DirectCall",
                                                   "UntrackedDirectCall",
                                                   "RootObjectNewDelete",
                                                   "RootObjectNewDeleteArray",
                                                   "GlobalNewDelete",
                                                   "GlobalNewDeleteArray",
                                                   "AllocatorClass",
                                                   "qSpecialNewDelete",
                                                   "qSpecialNewDeleteArray",
                                                   "qAllocFree"};

const char* MemoryManager::GetInstructionTypeString(_InstructionType instructionType) const {
    if (instructionType < 11)
        return s_InstructionTypeStrings[(s32)instructionType];
    else
        return "UNDEFINED INSTRUCTION TYPE!";
}

void MemoryManager::BeginProtection() {}

void MemoryManager::EndProtection() {}

}  // namespace nn::nex
