#include "Platform/Core/Platform.h"
#include "Platform/Core/BadEvents.h"
#include "Platform/Core/EventLog.h"
#include "nn/os.h"

static bool s_HasInitialized;

namespace nn::nex {
Platform::Platform() {
    _Instance = this;
}

// NON_MATCHING: operator delete should inline here
Platform::~Platform() {}

Platform* Platform::Instance() {
    return _Instance;
}

void Platform::CreateInstance() {
    _Instance = new Platform();
}

void Platform::DeleteInstance() {
    if (_Instance)
        delete _Instance;
}

void Platform::Sleep(u32 milliseconds) {
    if (milliseconds)
        nn::os::SleepThread(nn::TimeSpan::FromMilliSeconds(milliseconds));
    else
        nn::os::YieldThread();
}

nn::os::Tick Platform::GetTick() {
    return nn::os::GetSystemTick();
}

void Platform::NetworkToHost(const unsigned char* network, u16* host) {
    *host = (network[0] << 8) + network[1];
}

void Platform::NetworkToHost(const unsigned char* network, u32* host) {
    *host = (network[0] << 24) + (network[1] << 16) + (network[2] << 8) + network[3];
}

void Platform::NetworkToHost(const unsigned char* network, u64* host) {
    *host = ((u64)network[0] << 56) + ((u64)network[1] << 48) + ((u64)network[2] << 40) +
                ((u64)network[3] << 32) + ((u64)network[4] << 24) + (network[5] << 16) +
                (network[6] << 8) |
            network[7];
}

void Platform::HostToNetwork(const u16* host, unsigned char* network) {
    network[0] = *host >> 8;
    network[1] = *host;
}

void Platform::HostToNetwork(const u32* host, unsigned char* network) {
    network[0] = *host >> 24;
    network[1] = *host >> 16;
    network[2] = *host >> 8;
    network[3] = *host;
}

void Platform::HostToNetwork(const u64* host, unsigned char* network) {
    network[0] = *host >> 56;
    network[1] = *host >> 48;
    network[2] = *host >> 40;
    network[3] = *host >> 32;
    network[4] = *host >> 24;
    network[5] = *host >> 16;
    network[6] = *host >> 8;
    network[7] = *host;
}

void Platform::WarnObsoleteMethod(const char* a2, const char* a3) {
    _QLOG(EventLog::_2, "WARNING  Using obsolete API '%s', use '%s' instead", a2, a3);
    if (BadEvents::s_pInstance)
        ++BadEvents::s_pInstance->field_0[3];
}

#define STATE_VECTOR_LENGTH 624

struct tagMTRand {
    u32 mt[STATE_VECTOR_LENGTH];
    u32 index;
} rand;

// MT19937 algorithm from https://github.com/ESultanik/mtwister/blob/master/mtwister.c#L19
void Platform::SetRandomNumberSeed(u32 seed) {
    u32 defaultSeed = 0x1105;

    rand.mt[0] = (seed == 0) ? defaultSeed : seed;
    rand.mt[1] = rand.mt[0] * 0x10DCD;

    for (rand.index = 2; rand.index < STATE_VECTOR_LENGTH; rand.index++)
        rand.mt[rand.index] = (0x10DCD * rand.mt[rand.index - 1]) & 0xFFFFFFFF;

    Platform::s_bSeedIsInitialized = true;
}

void Platform::GetRandomNumber(u32 val) {}

u32 Platform::GetRandomSeed() {
    u32 bytes = 0;
    nn::os::GenerateRandomBytes(&bytes, 4);
    return bytes;
}

void Platform::GetRealRandomNumber(f32 val) {}

u32 Platform::GetProcessID() {
    return 0;
}

u64 Platform::GetPlatformID() {
    if (!s_HasInitialized)
        s_HasInitialized = true;
    return 0;
}

void Platform::Breakpoint() {}

void Platform::YieldThread() {}

}  // namespace nn::nex
