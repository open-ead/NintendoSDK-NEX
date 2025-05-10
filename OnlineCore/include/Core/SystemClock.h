/**
 * @file time.h
 * @brief NEX Time Library.
 */

#pragma once

#include <nn/types.h>

namespace nn::nex {
class Time;
class TimeProvider;

class SystemClock {
public:
    SystemClock();

    virtual ~SystemClock();

    static void RegisterTimeProvider(TimeProvider*, bool);
    static void ApplyCorrection(Time curTime, Time newTime);
    static Time ProtectedGetTime();
    static Time GetTimeImpl(bool);
    static Time GetTimeImplCorrectless();
    static void Reset();

    static TimeProvider* s_pTimeProvider;
    static bool s_needCorrection;
    static bool s_tiCorrection;
};
}  // namespace nn::nex
