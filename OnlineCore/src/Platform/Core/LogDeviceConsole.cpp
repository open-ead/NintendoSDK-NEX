#include "Platform/Core/LogDeviceConsole.h"
#include <cstdio>

namespace nn::nex {
LogDeviceConsole::LogDeviceConsole(void* ptr) : m_stdout(ptr) {
    if (!ptr)
        m_stdout = stdout;
}
}  // namespace nn::nex
