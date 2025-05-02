#include "Platform/Core/VersionInfo.h"

namespace nn::nex {
const char* VersionInfo::GetCopyrightString() {
    return "Copyright (c) 1998-2009 Quazal Technologies Inc";
}

u16 VersionInfo::V1() {
    return 4;
}

u16 VersionInfo::V2() {
    return 1;
}

u16 VersionInfo::V3() {
    return 2;
}

u16 VersionInfo::V4() {
    return 0x0FA7;
}

u32 VersionInfo::VersionMajor() {
    return 0x40001;
}

u32 VersionInfo::VersionMinor() {
    return 0x20FA7;
}

u32 VersionInfo::ExtractFirstNumber(u32 versionNumber) {
    return versionNumber >> 0x10;
}

void VersionInfo::ExtractSecondNumber(u32 versionNumber) {}

void VersionInfo::Banner(const char*) {}

}  // namespace nn::nex
