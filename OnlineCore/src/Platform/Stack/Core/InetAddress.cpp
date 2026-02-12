#include "Platform/Stack/Core/InetAddress.h"
#include <cstdio>
#include <cstring>
#include "Platform/Core/String.h"
#include "Platform/Core/StringConversion.h"
#include "Platform/Core/StringStream.h"
#include "nn/socket.h"

namespace nn::nex {
InetAddress::InetAddress() {
    Init();
}

InetAddress::InetAddress(const InetAddress& other) {
    memcpy(&m_Attributes.byte_8, &other.m_Attributes.byte_8, 0x80);
}

InetAddress::InetAddress(void* ptr, u32) {
    m_Attributes = *(InetAttributes*)ptr;
}

InetAddress::InetAddress(const char* address, u16 port) {
    Init();
    SetAddress(address);
    m_Attributes.port = nn::socket::InetHtons(port);
}

InetAddress::InetAddress(u32 addr, u16 port) {
    Init();
    m_Attributes.addr = socket::InetHtonl(addr);
    m_Attributes.port = nn::socket::InetHtons(port);
}

InetAddress::~InetAddress() = default;

u64 InetAddress::GetKey() const {
    return ((u64)m_Attributes.addr << 32) | socket::InetNtohs(m_Attributes.port);
}

u16 InetAddress::GetPortNumber() const {
    return nn::socket::InetHtons(m_Attributes.port);
}

void InetAddress::EnableAutoLookup(bool isAutoLookup) {
    s_bAutoLookup = isAutoLookup;
}

void InetAddress::Init() {
    memset(&m_Attributes, 0, sizeof(m_Attributes));
    m_Attributes.byte_9 = 2;
}

InetAddress& InetAddress::operator=(const InetAddress& other) {
    memcpy(&m_Attributes, &other.m_Attributes, 0x80);  // this seems like a bug
    return *this;
}

// void InetAddress::SetAddress(const char*) {}  // TODO

void InetAddress::SetPortNumber(u16 port) {
    m_Attributes.port = nn::socket::InetHtons(port);
}

void InetAddress::SetAddress(u32 addr) {
    m_Attributes.addr = nn::socket::InetHtonl(addr);
}

void InetAddress::SetLocalHost() {
    SetAddress("127.0.0.1");
}

bool InetAddress::IsLocalHost() const {
    InetAddress localHost;
    localHost.SetLocalHost();
    return GetAddress() == localHost.GetAddress();
}

u32 InetAddress::GetAddress() const {
    return nn::socket::InetNtohl(m_Attributes.addr);
}

u32 InetAddress::String2Address(const char* str) {
    u64 addr;
    if (nn::socket::InetPton(2, str, &addr) > 0)
        return addr;
    return -1;
}

bool InetAddress::GetAddress(char* output, u64 val) const {
    if (val < 16)
        return false;
    char dest[20];
    socket::InetNtop(2, &m_Attributes.addr, dest, sizeof(dest));
    StringConversion::Char8_2T(dest, output, val);
    return true;
}

void InetAddress::SetNetworkAddress(u32 addr) {
    m_Attributes.addr = addr;
}

String InetAddress::GetAddressStr() const {
    char dest[20];
    nn::socket::InetNtop(2, &m_Attributes.addr, dest, sizeof(dest));
    char dest2[128];
    StringConversion::Char8_2T(dest, dest2, sizeof(dest2));
    return dest;
}

void InetAddress::SetNetworkPortNumber(u16 port) {
    m_Attributes.port = port;
}

bool InetAddress::GetPortNumber(char* str, u32 size) const {
    snprintf(str, size, "%d", GetPortNumber());
    return true;
}

String InetAddress::GetPortNumberStr() const {
    char out[10];
    snprintf(out, 10, "%d", GetPortNumber());
    return out;
}

void InetAddress::Trace(u64) const {
    char out[128];
    ToStr(out);
}

void InetAddress::ToStr(char* out) const {
    String addrStr = GetAddressStr();
    String portStr = GetPortNumberStr();
    StringStream stringStream;

    stringStream << &addrStr << ":" << &portStr;

    strcpy(out, stringStream.Begin());
}

String InetAddress::ToStr() const {
    char out[200];
    ToStr(out);
    return out;
}

}  // namespace nn::nex
