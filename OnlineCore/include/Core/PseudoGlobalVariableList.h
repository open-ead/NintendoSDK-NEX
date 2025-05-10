/**
 * @file psuedo.h
 * @brief Psuedo variable implementation for NEX.
 */

#pragma once

#include <nn/nex/instance.h>
#include "Platform/Core/RootObject.h"

namespace nn {
namespace nex {

class PseudoGlobalVariableList : public nn::nex::RootObject {
public:
    PseudoGlobalVariableList();

    virtual ~PseudoGlobalVariableList();

    void AddVariable(nn::nex::PseudoGlobalVariableRoot*);
    void RemoveVariable(nn::nex::PseudoGlobalVariableRoot*);
    static nn::nex::PseudoGlobalVariableRoot* GetVariable(u32 idx);
    static u32 FindVariableIndex(nn::nex::PseudoGlobalVariableRoot*);
    void AllocateExtraContextsForAllVariables();
    void FreeExtraContextsForAllVariables();
    void ResetContextForAllVariables(u32);
    static u32 GetNbOfVariables();

    static PseudoGlobalVariableRoot* s_pVariableListHead;
    static u32 m_uiNbOfVariables;
};

}  // namespace nex
}  // namespace nn
