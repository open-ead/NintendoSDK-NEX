#include "Platform/Core/VersionInfo.h"

namespace nn::nex {
const char* VersionInfo::GetCopyrightString() {
    return "Copyright (c) 1998-2009 Quazal Technologies Inc";
}

uint16_t VersionInfo::V1() {
    return 4;
}

uint16_t VersionInfo::V2() {
    return 1;
}

uint16_t VersionInfo::V3() {
    return 2;
}

uint16_t VersionInfo::V4() {
    return 0x0FA7;
}

uint32_t VersionInfo::VersionMajor() {
    return 0x40001;
}

uint32_t VersionInfo::VersionMinor() {
    return 0x20FA7;
}

uint32_t VersionInfo::ExtractFirstNumber(uint32_t versionNumber) {
    return versionNumber >> 0x10;
}

uint32_t VersionInfo::ExtractSecondNumber(uint32_t versionNumber) {
    return versionNumber & 0xFFFFFFFF;
}

void VersionInfo::Banner(const char*) {}

}  // namespace nn::nex
