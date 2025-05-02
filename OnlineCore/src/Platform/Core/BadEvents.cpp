#include "Platform/Core/BadEvents.h"

#include <algorithm>

namespace nn::nex {
BadEvents::BadEvents() {
    Reset();
}

void BadEvents::Reset() {
    std::fill(std::begin(field_0), std::end(field_0), 0);
    field_28 = 130;
}

BadEvents::~BadEvents() {}

void BadEvents::SetExpectedEvent(_ID id) {
    field_28 |= 1 << id;
}

BadEvents* BadEvents::CreateInstance() {
    BadEvents* instance = new BadEvents();
    s_pInstance = instance;
    return instance;
}

void BadEvents::DeleteInstance() {
    delete s_pInstance;
    s_pInstance = nullptr;
}

void BadEvents::SignalEvent(_ID id) {
    ++field_0[id];
}

void BadEvents::ClearExpectedEvent(_ID id) {
    field_28 &= ~(1 << id);
}

bool BadEvents::IsExpected(_ID id) const {
    return (field_28 & (1 << id)) != 0;
}

void BadEvents::ClearCount(_ID id) {
    field_0[id] = 0;
}

s32 BadEvents::GetCount(_ID id) const {
    return field_0[id];
}

bool BadEvents::GlobalNewDeleteAllowed() {
    if (s_pInstance)
        return ((s_pInstance->field_28) >> 1) & true;
    else
        return true;
}

void BadEvents::Signal(_ID id) {
    if (s_pInstance)
        ++s_pInstance->field_0[id];
}
}  // namespace nn::nex
