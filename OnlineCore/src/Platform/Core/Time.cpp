#include "Platform/Core/Time.h"
#include "Platform/Core/SystemClock.h"

namespace nn::nex {
u64 Time::GetTime() {
    if (SystemClock::s_needCorrection)
        SystemClock::s_cachedTime = SystemClock::GetTimeImpl(false);
    else
        SystemClock::s_cachedTime = SystemClock::GetTimeImplCorrectless();
    return SystemClock::s_cachedTime;
}
}  // namespace nn::nex
