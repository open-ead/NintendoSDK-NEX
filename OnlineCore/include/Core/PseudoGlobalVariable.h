/**
 * @file psuedo.h
 * @brief Psuedo variable implementation for NEX.
 */

#pragma once

#include <nn/nex/instance.h>
#include "Platform/Core/RootObject.h"

namespace nn {
namespace nex {
template <typename T>
class PseudoGlobalVariable : public nn::nex::PseudoGlobalVariableRoot {
public:
    PseudoGlobalVariable();

    virtual ~PseudoGlobalVariable();

    virtual void AllocateExtraContexts();
    virtual void FreeExtraContexts();
    virtual void ResetContext(u32);
    virtual PseudoGlobalVariableRoot* GetNext();
    virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable);
};
}  // namespace nex
}  // namespace nn
