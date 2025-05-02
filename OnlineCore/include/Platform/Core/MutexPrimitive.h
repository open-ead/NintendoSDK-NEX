#pragma once

#include "nn/os/os_Mutex.h"

namespace nn::nex {
class MutexPrimitive {
public:
    MutexPrimitive(bool unk) { nn::os::InitializeMutex(m_MutexType, unk, 0); }

    virtual ~MutexPrimitive();

private:
    os::MutexType* m_MutexType;
};
}  // namespace nn::nex
