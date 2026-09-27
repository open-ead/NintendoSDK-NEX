#include "Platform/Stack/Core/InterfaceInfo.h"
#include <cstring>
#include "Platform/Core/StringConversion.h"
#include "nn/socket.h"

namespace nn::nex {
InterfaceInfo::InterfaceInfo() {
    m_Address = 0;
    m_BroadcastAddress = 0;
    m_Mask = 0;
    m_Flags = 0;
}

InterfaceInfo::~InterfaceInfo() {}

void InterfaceInfo::SetAddress(uint32_t addr) {
    m_Address = addr;
}

void InterfaceInfo::SetBroadcastAddress(uint32_t broadcastAddr) {
    m_BroadcastAddress = broadcastAddr;
}

void InterfaceInfo::SetMask(uint32_t mask) {
    m_Mask = mask;
}

void InterfaceInfo::SetFlags(uint32_t flags) {
    m_Flags = flags;
}

void InterfaceInfo::SetName(char* name) {
    m_Name = name;
}

bool InterfaceInfo::Addr2Str(uint32_t a2, char* out, uint32_t a4) {
    char dest[20];
    int32_t temp = a2;
    socket::InetNtop(2, &temp, dest, sizeof(dest));
    StringConversion::Char8_2T(dest, out, a4);
    return true;
}

bool InterfaceInfo::GetAddress(char* out, uint32_t a3) {
    char dest[20];
    int32_t temp = m_Address;
    socket::InetNtop(2, &temp, dest, sizeof(dest));
    StringConversion::Char8_2T(dest, out, a3);
    return true;
}

bool InterfaceInfo::GetBroadcastAddress(char* out, uint32_t a3) {
    char dest[20];
    int32_t temp = m_BroadcastAddress;
    socket::InetNtop(2, &temp, dest, sizeof(dest));
    StringConversion::Char8_2T(dest, out, a3);
    return true;
}

bool InterfaceInfo::GetMask(char* out, uint32_t a3) {
    char dest[20];
    int32_t temp = m_Mask;
    socket::InetNtop(2, &temp, dest, sizeof(dest));
    StringConversion::Char8_2T(dest, out, a3);
    return true;
}

bool InterfaceInfo::GetName(char* out, uint32_t a3) {
    const char* cstr = GetName();
    if (cstr) {
        strncpy(out, cstr, a3);
        out[a3 - 1] = '\0';
        return true;
    }
    return false;
}

bool InterfaceInfo::GetFlags(char* out, uint32_t size) {
    char dest[512] = {0};

    uint32_t flags = (uint32_t)m_Flags;
    if (flags & 0)
        strcat(dest, "POINT2POINT");
    if (flags & 4)
        strcat(dest, "LOOPBACK ");
    if (flags & 2)
        strcat(dest, "BROADCAST ");

    strncpy(out, dest, size);
    out[size - 1] = '\0';

    return true;
}

uint32_t InterfaceInfo::GetAddress() {
    return m_Address;
}

uint32_t InterfaceInfo::GetBroadcastAddress() {
    return m_BroadcastAddress;
}

uint32_t InterfaceInfo::GetMask() {
    return m_Mask;
}

uint32_t InterfaceInfo::GetFlags() {
    return m_Flags;
}

const char* InterfaceInfo::GetName() {
    return m_Name.cstr();
}

void InterfaceInfo::Trace(uint64_t) {
    char v6[128];
    char v7[512];
    const char* cstr = GetName();
    if (cstr) {
        strncpy(v6, cstr, 128);
        v6[127] = 0;
    }

    nn::socket::InetNtop(2, &m_Address, v7, 20);
    StringConversion::Char8_2T(v7, v6, 128);

    nn::socket::InetNtop(2, &m_BroadcastAddress, v7, 20);
    StringConversion::Char8_2T(v7, v6, 128);

    nn::socket::InetNtop(2, &m_Mask, v7, 20);
    StringConversion::Char8_2T(v7, v6, 128);

    memset(v7, 0, sizeof(v7));

    GetFlags(v6, 512);
}

}  // namespace nn::nex
