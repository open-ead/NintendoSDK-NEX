#include "Platform/Core/String.h"
#include "Platform/Core/MemoryManager.h"

#include <cstring>

namespace nn::nex {
template <typename T>
void* SpecialNewArray(uint32_t a1, T* ptr, uint32_t a3) {
    void* mem = MemoryManager::Allocate(sizeof(ptr));
    return (void*)((int*)(mem) + 1);
}

template <typename T, T>
void StrCopy(T* str, const T* copyStr, uint64_t unk) {
    if (str) {
    }
}

String::String(const char* str) {
    if (str)
        strlen(str);
    else
        str = nullptr;
}

void String::CopyString(char*, uint64_t) const {}

}  // namespace nn::nex
