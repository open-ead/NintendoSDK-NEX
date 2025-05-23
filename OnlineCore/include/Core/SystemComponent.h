#pragma once

#include "Platform/Core/RefCountedObject.h"

namespace nn::nex {
class String;

class SystemComponent : public RefCountedObject {
public:
    enum _State {
        State_Uninitialized = 1 << 0,
        State_Initializing = 1 << 1,
        State_Ready = 1 << 2,
        State_ReadyInUse = 1 << 3,
        State_Terminating = 1 << 4,
        State_TerminatingWhileInUse = 1 << 5,
        State_Terminated = 1 << 6,
        State_Faulty = 1 << 7,
        State_Unknown = 1 << 8,
        State_HighestState = 1 << 8
    };

    SystemComponent(const String&);

    virtual ~SystemComponent();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro() = 0;
    virtual void StateTransition(SystemComponent::_State);
    virtual void OnInitialize();
    virtual void OnTerminate();
    virtual bool BeginInitialization();
    virtual bool EndInitialization();
    virtual bool BeginTermination();
    virtual bool EndTermination();
    virtual bool ValidTransition(SystemComponent::_State);
    virtual bool UseIsAllowed();
    virtual SystemComponent::_State TestState();
    virtual void DoWork();

    _State Initialize();
    _State Terminate();

    u8 SystemComponent_xC;
    u8 _D;
    u8 _E;
    u8 _F;
    u64 _10;
    u64 _18;
    u64 _20;
    u32 _28;
    u32 _2C;
    u64 _30;
    _State mState;  // _38
    u32 _3C;
    u64 _40;
};
}  // namespace nn::nex
