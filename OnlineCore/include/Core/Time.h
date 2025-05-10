#pragma once

#include <nn/types.h>

namespace nn::nex {
class TimeProvider;

class Time {
public:
    static void Reset();
    static void RegisterTimeProvider(TimeProvider* provider);

    Time Multiply(f32) const;
    Time Divide(f32) const;
    Time Scale(f32) const;

    static Time ConvertTimeoutToDeadline(u32 timeout);
    static u32 ConvertDeadlineToTimeout(Time deadline);

    u64 mCurTime;

    static u64* s_pfGetSessionTime;  // some sort of callback?
};

}  // namespace nn::nex
