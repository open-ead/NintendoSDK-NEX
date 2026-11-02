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

void OutputFormat::StartString(char* str, uint32_t) {
    *str = 0;
}

uint32_t OutputFormat::StartPrefixes(char* str, uint32_t startPos) {
    return AppendToString(str, "(", startPos);
}

uint32_t OutputFormat::AppendToString(char* dest, const char* append, uint32_t startPos) {
    size_t len = strlen(dest);
    size_t start = startPos - len;
    if (start != 0)
        return snprintf(&dest[len], start, "%s", append);
    return len;
}

void OutputFormat::PreparePrefix(char* dest, uint32_t val, const char* str, ...) {
    std::va_list args;
    va_start(args, str);

    *dest = 0;

    std::va_list args2;
    // va_copy(args2, args);

    AddMessageImpl(dest, val, str, args2);
}

uint32_t OutputFormat::AddMessageImpl(char* dest, uint32_t, const char* str, std::va_list) {
    return 0;
}

void OutputFormat::AddPrefixes(char* str, uint32_t) {}

void OutputFormat::EndPrefixes(char* str, uint32_t) {}

void OutputFormat::AddIndent(char* str, uint32_t) {}

uint32_t OutputFormat::AddMessage(char* dest, uint32_t, const char* str, std::va_list) {
    return 0;
}

void OutputFormat::EndString(char* str, uint32_t) {}

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

void OutputFormat::IncreaseIndent(uint32_t val) {
    m_Indent += val;
}

void OutputFormat::DecreaseIndent(uint32_t val) {
    m_Indent = (m_Indent > val) ? (m_Indent - val) : 0;
}

}  // namespace nn::nex
