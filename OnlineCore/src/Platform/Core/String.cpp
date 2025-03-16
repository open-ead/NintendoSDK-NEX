#include "Platform/Core/String.h"
#include "Platform/Core/MemoryManager.h"

#include <cstring>

namespace nn::nex {
template <typename T>
void* SpecialNewArray(u32 a1, T* ptr, u32 a3) {
    void* mem = MemoryManager::Allocate(sizeof(ptr));
    return (void*)((int*)(mem) + 1);
}

template <typename T, T>
void StrCopy(T* str, const T* copyStr, u64 unk) {
    if (str) {
    }
}

String::String(const char* str) {
    if (str)
        size_t len = strlen(str);
    else
        str = nullptr;
}

void String::CopyString(char*, u64) const {}

}  // namespace nn::nex
