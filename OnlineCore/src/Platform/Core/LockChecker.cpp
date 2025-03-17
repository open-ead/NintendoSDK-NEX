#include "Platform/Core/LockChecker.h"

namespace nn::nex {
LockChecker::LockChecker(u32 val) {
    dword_C = val;
}

LockChecker::~LockChecker() {}

LockChecker::LockChecker(const LockChecker& other) : dword_C(other.dword_C) {}

void LockChecker::operator=(const LockChecker& other) {}

}  // namespace nn::nex
