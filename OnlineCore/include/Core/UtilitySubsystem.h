#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class UtilitySubsystem : public RootObject {
private:
    static UtilitySubsystem* _Instance;

public:
    UtilitySubsystem();
    virtual ~UtilitySubsystem();
    static UtilitySubsystem* Instance();
};

}  // namespace nn::nex
