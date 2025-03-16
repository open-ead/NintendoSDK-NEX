#pragma once

#include <nn/types.h>

namespace nn::nex::ConsoleIO {
bool InputIsSupported();
bool OutputIsSupported();
u8 GetChar(bool unk);
void GetCStr(char* ret, u32 unk);
void Print(const char* str, ...);
void PutString(const char* str);
void Banner(const char* str);
void Error();
}  // namespace nn::nex::ConsoleIO
