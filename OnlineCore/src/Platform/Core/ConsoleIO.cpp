#include "Platform/Core/ConsoleIO.h"
#include <cstdarg>
#include <cstdio>
#include "Platform/Core/VersionInfo.h"

namespace nn::nex::ConsoleIO {
bool InputIsSupported() {
    return false;
}

bool OutputIsSupported() {
    return true;
}

u8 GetChar(bool unk) {
    return 0;
}

void GetCStr(char* ret, u32 unk) {}

void Print(const char* format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[2048] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    printf("%s", buffer);
}

void PutString(const char* str) {
    printf("%s", str);
}

void Banner(const char* str) {
    Print("%s, version %d.%d.%d.%d\n", str, VersionInfo::V1(), VersionInfo::V2(), VersionInfo::V3(),
          VersionInfo::V4());
    Print("%s\n", VersionInfo::GetCopyrightString());
    Print("\n");
}

void Error() {}

}  // namespace nn::nex::ConsoleIO
