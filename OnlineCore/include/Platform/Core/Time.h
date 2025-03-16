#pragma once

#include <nn/types.h>

namespace nn::nex {
class TimeProvider;

class Time {
public:
    static u64 GetTime();
    void Reset();
    void RegisterTimeProvider(TimeProvider*);
    void Multiply(f32) const;
    void Divide(f32) const;
    void Scale(f32) const;
    static void ConvertTimeoutToDeadline(u32);
    static void ConvertDeadlineToTimeout(Time);

    u64 GetTimeVal() const { return m_Time; }

    operator u64() const { return m_Time; }

private:
    u64 m_Time = 0;
};
}  // namespace nn::nex
