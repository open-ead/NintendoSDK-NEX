#pragma once

#include <nn/os.h>
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Platform : public RootObject {
private:
    static Platform* _Instance;
    static u32 s_oRNG[];
    static bool s_bSeedIsInitialized;

public:
    Platform();
    virtual ~Platform();
    Platform* Instance();
    static void CreateInstance();
    static void DeleteInstance();

    void Sleep(u32);
    nn::os::Tick GetTick();
    static void NetworkToHost(unsigned const char*, u16*);
    static void NetworkToHost(unsigned const char*, u32*);
    static void NetworkToHost(unsigned const char*, u64*);
    static void HostToNetwork(const u16*, unsigned char*);
    static void HostToNetwork(const u32*, unsigned char*);
    static void HostToNetwork(const u64*, unsigned char*);
    static void WarnObsoleteMethod(const char*, const char*);
    static void SetRandomNumberSeed(u32);
    static void GetRandomNumber(u32);
    static u32 GetRandomSeed();
    static void GetRealRandomNumber(float);
    static u32 GetProcessID();
    static u64 GetPlatformID();
    static void Breakpoint();
    static void YieldThread();
};
}  // namespace nn::nex
