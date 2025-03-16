#include "Platform/Core/OutputFormat.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace nn::nex {
OutputFormat::OutputFormat() {
    m_Prefix = nullptr;
    m_ulTime = Time::GetTime();
}

OutputFormat::~OutputFormat() {}

void OutputFormat::StartString(char* str, u32) {
    *str = 0;
}

u32 OutputFormat::StartPrefixes(char* str, u32 startPos) {
    return AppendToString(str, "(", startPos);
}

u32 OutputFormat::AppendToString(char* dest, const char* append, u32 startPos) {
    size_t len = strlen(dest);
    size_t start = startPos - len;
    if (start != 0)
        return snprintf(&dest[len], start, "%s", append);
    return len;
}

void OutputFormat::PreparePrefix(char* dest, u32 val, const char* str, ...) {
    std::va_list args;
    va_start(args, str);

    *dest = 0;

    std::va_list args2;
    // va_copy(args2, args);

    AddMessageImpl(dest, val, str, args2);
}

u32 OutputFormat::AddMessageImpl(char* dest, u32, const char* str, std::va_list) {
    return 0;
}

void OutputFormat::AddPrefixes(char* str, u32) {}

void OutputFormat::EndPrefixes(char* str, u32) {}

void OutputFormat::AddIndent(char* str, u32) {}

u32 OutputFormat::AddMessage(char* dest, u32, const char* str, std::va_list) {
    return 0;
}

void OutputFormat::EndString(char* str, u32) {}

void OutputFormat::EnableNumberTraces(bool toggle) {
    field_c = toggle;
}

void OutputFormat::ShowProcessID(bool toggle) {
    field_11 = toggle;
}

void OutputFormat::ShowThreadID(bool toggle) {
    field_10 = toggle;
}

void OutputFormat::ShowLocalTime(bool toggle) {
    field_12 = toggle;
}

void OutputFormat::ShowDateTime(bool toggle) {
    field_13 = toggle;
}

void OutputFormat::ShowSystemThreadName(bool toggle) {
    field_15 = toggle;
}

void OutputFormat::ShowLocalStationHandle(bool toggle) {
    field_16 = toggle;
}

void OutputFormat::ShowSessionTime(bool toggle) {
    m_bShowSessionTime = toggle;
}

void OutputFormat::ShowCurrentContext(bool toggle) {
    m_bShowCurrentContext = toggle;
}

void OutputFormat::ShowCID(bool toggle) {
    m_bShowCID = toggle;
}

void OutputFormat::ShowPID(bool toggle) {
    m_bShowPID = toggle;
}

void OutputFormat::AddPrefix(const char* str) {
    m_Prefix = str;
}

void OutputFormat::IncreaseIndent(u32 val) {
    m_Indent += val;
}

void OutputFormat::DecreaseIndent(u32 val) {
    m_Indent = (m_Indent > val) ? (m_Indent - val) : 0;
}

}  // namespace nn::nex
