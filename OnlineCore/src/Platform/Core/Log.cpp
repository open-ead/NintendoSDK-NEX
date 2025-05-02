#include "Platform/Core/Log.h"
#include <cstdarg>

#include "Platform/Core/LogDeviceConsole.h"
#include "Platform/Core/LogFilter.h"
#include "Platform/Core/OutputFormat.h"

namespace nn::nex {

Log::Log() {
    m_LogDevice = new LogDeviceConsole(nullptr);
    m_OutputFormat = new OutputFormat();
    m_LogFilter = nullptr;
}

Log::~Log() {
    if (m_OutputFormat)
        delete m_OutputFormat;

    if (m_LogFilter)
        delete m_LogFilter;
}

void Log::Output(const char* str, ...) {
    va_list va;
    va_list va1;
    va_start(va, str);
    va_start(va1, str);

    OutputImpl(str, va, nullptr);
}

void Log::OutputString(const char* str, ...) {
    va_list va;
    va_list va1;
    va_start(va, str);
    va_start(va1, str);

    OutputImpl(str, va, nullptr);
}

void Log::AddCustomPrefix(char*, s32, void*) {}

void Log::OutputImpl(const char* str, std::va_list va, void* ptr) {
    if (!m_LogDevice)
        return;

    if (m_LogFilter && !m_LogFilter->OutputCurrentTrace())
        return;

    if (!m_OutputFormat)
        return;

    // the code is flawless but it mismatches...
    char buffer[0x100] = {0};
    u32 size = sizeof(buffer) - 2;

    m_OutputFormat->StartString(buffer, size);
    m_OutputFormat->StartPrefixes(buffer, size);
    AddCustomPrefix(buffer, size, ptr);
    m_OutputFormat->AddPrefixes(buffer, size);
    m_OutputFormat->EndPrefixes(buffer, size);
    m_OutputFormat->AddIndent(buffer, size);
    m_OutputFormat->AddMessage(buffer, size + 1, str, va);
    m_OutputFormat->EndString(buffer, size);
    m_LogDevice->Output(buffer);
}

void Log::PrepareOutput(char* output, u32 val, void* ptr) {
    u32 i = val - 2;
    m_OutputFormat->StartString(output, i);
    AddCustomPrefix(output, val, ptr);
    m_OutputFormat->AddPrefixes(output, val);
    m_OutputFormat->EndPrefixes(output, val);
    m_OutputFormat->AddIndent(output, val);
}

void Log::SetOutputFormat(OutputFormat* outputFormat) {
    if (m_OutputFormat)
        delete m_OutputFormat;
    m_OutputFormat = outputFormat;
}

void Log::SetLogDevice(LogDevice* logDevice, bool a3) {
    LogDevice* prevLogDevice = m_LogDevice;
    m_LogDevice = logDevice;

    if (prevLogDevice && a3)
        delete prevLogDevice;
}

LogDevice* Log::GetLogDevice() {
    return m_LogDevice;
}

void Log::SetLogFilter(LogFilter* logFilter) {
    if (m_LogFilter)
        delete m_LogFilter;
    m_LogFilter = logFilter;
}

LogFilter* Log::GetLogFilter() {
    return m_LogFilter;
}

OutputFormat* Log::GetOutputFormat() {
    return m_OutputFormat;
}

}  // namespace nn::nex
