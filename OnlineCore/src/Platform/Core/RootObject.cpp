#include "Platform/Core/RootObject.h"
#include "Platform/Core/MemoryManager.h"

namespace nn::nex {

void* RootObject::operator new(ulong size) {
    return MemoryManager::Allocate(size);
}

__attribute__((noinline)) void RootObject::operator delete(void* ptr) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(ulong size, const char*, u32) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](ulong size) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](ulong size, const char*, u32) {
    return MemoryManager::Allocate(size);
}

void RootObject::operator delete[](void* ptr) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete(void* ptr, const char*, u32) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete[](void* ptr, const char*, u32) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(ulong, RootObject::TargetPool) {}

void* RootObject::operator new(ulong, RootObject::TargetPool, const char*, u32) {}

}  // namespace nn::nex
