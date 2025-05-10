#include "Platform/Core/MutexPrimitive.h"
#include "nn/os/os_Mutex.h"

namespace nn::nex {

MutexPrimitive::MutexPrimitive(bool unk) {
    nn::os::InitializeMutex(&m_MutexType, unk, 0);
}

MutexPrimitive::~MutexPrimitive() {
    nn::os::FinalizeMutex(&m_MutexType);
}

}  // namespace nn::nex
