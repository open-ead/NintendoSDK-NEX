#pragma once

#include "Platform/Core/LogDevice.h"

namespace nn::nex {
class LogDeviceConsole : public LogDevice {
public:
    LogDeviceConsole(void*);
    virtual ~LogDeviceConsole();
    virtual void Output(const char*);

private:
    void* m_stdout;
};
}  // namespace nn::nex
