/**
 * @file psuedo.h
 * @brief Psuedo variable implementation for NEX.
 */

#pragma once

#include <nn/nex/instance.h>
#include "Platform/Core/RootObject.h"

namespace nn {
namespace nex {
class PseudoGlobalVariableList;

class PseudoGlobalVariableRoot : public nn::nex::RootObject {
public:
    PseudoGlobalVariableRoot();

    virtual ~PseudoGlobalVariableRoot();

    virtual void AllocateExtraContexts() = 0;
    virtual void FreeExtraContexts() = 0;
    virtual void ResetContext(u32) = 0;
    virtual PseudoGlobalVariableRoot* GetNext() = 0;
    virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable) = 0;

    static void ResetContextForAllVariables(u32);
    static void AllocateExtraContextsForAllVariables(u64);
    static void FreeExtraContextsForAllVariables();
    static s64 GetNbOfExtraContexts();

    nn::nex::PseudoGlobalVariableRoot* mNextRoot;  // _8

    static s64 s_uiNbOfExtraContexts;
    static PseudoGlobalVariableList s_oList;
};

}  // namespace nex
}  // namespace nn
