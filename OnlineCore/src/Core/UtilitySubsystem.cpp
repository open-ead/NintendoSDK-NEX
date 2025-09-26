#include "Core/UtilitySubsystem.h"
#include "Core/LocalClock.h"
#include "Platform/Core/Platform.h"

namespace nn::nex {
UtilitySubsystem::UtilitySubsystem() {
    Platform::CreateInstance();
    if (!LocalClock::s_pInstance)
        LocalClock::s_pInstance = new LocalClock();
    _Instance = this;
}

UtilitySubsystem::~UtilitySubsystem() {
    if (LocalClock::s_pInstance) {
        delete LocalClock::s_pInstance;
        LocalClock::s_pInstance = nullptr;
    }
    Platform::DeleteInstance();
}

UtilitySubsystem* UtilitySubsystem::Instance() {
    return _Instance;
}
}  // namespace nn::nex
