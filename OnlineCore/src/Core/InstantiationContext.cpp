#include "Core/InstantiationContext.h"

namespace nn::nex {
InstantiationContext::InstantiationContext() {
    byte_80 = true;
}

InstantiationContext::InstantiationContext(InstanceControl* instanceControl, u32) {}

InstantiationContext::~InstantiationContext() {}

void InstantiationContext::AddInstance(InstanceControl* instanceControl, u32) {}

void InstantiationContext::DelInstance(InstanceControl* instanceControl, u32) {}

#define SET_NULL(ptr)                                                                              \
    (ptr) = 0;                                                                                     \
    asm("");

void InstantiationContext::InitContext() {
    SET_NULL(m_Context[0]);
    SET_NULL(m_Context[1]);
    SET_NULL(m_Context[14]);
    SET_NULL(m_Context[2]);
    SET_NULL(m_Context[3]);
    SET_NULL(m_Context[4]);
    SET_NULL(m_Context[5]);
    SET_NULL(m_Context[6]);
    SET_NULL(m_Context[7]);
    SET_NULL(m_Context[8]);
    SET_NULL(m_Context[9]);
    SET_NULL(m_Context[10]);
    SET_NULL(m_Context[11]);
    SET_NULL(m_Context[12]);
    SET_NULL(m_Context[13]);
}

}  // namespace nn::nex