#pragma once

#include <nn/mem.h>
#include "Platform/Core/RefCountedObject.h"

namespace nn::nex {
class GlobalVariables : public RefCountedObject {
public:
    static GlobalVariables* s_pGv;

    nn::mem::StandardAllocator* getStandardAllocator() const { return m_Allocator; }

private:
    void* filler[70];
    nn::mem::StandardAllocator* m_Allocator;
};
}  // namespace nn::nex
