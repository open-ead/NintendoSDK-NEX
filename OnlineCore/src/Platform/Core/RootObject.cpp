#include "Platform/Core/RootObject.h"
#include "Platform/Core/MemoryManager.h"

namespace nn::nex {

void* RootObject::operator new(size_t size) {
    return MemoryManager::Allocate(size);
}

__attribute__((noinline)) void RootObject::operator delete(void* ptr) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(size_t size, const char*, uint32_t) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](size_t size) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](size_t size, const char*, uint32_t) {
    return MemoryManager::Allocate(size);
}

void RootObject::operator delete[](void* ptr) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete(void* ptr, const char*, uint32_t) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete[](void* ptr, const char*, uint32_t) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(size_t, RootObject::TargetPool) {}

void* RootObject::operator new(size_t, RootObject::TargetPool, const char*, uint32_t) {}

}  // namespace nn::nex
