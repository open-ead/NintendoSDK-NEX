#include "Core/Plugin.h"

namespace nn::nex {
Plugin::Plugin() {
    s_pInstance = this;
}

Plugin::~Plugin() {}

void Plugin::Unload() {}

void Plugin::Trace(u64) {}

bool Plugin::Initialize() {
    return true;
}

void Plugin::ThreadAttach() {}

void Plugin::ThreadDetach() {}

void Plugin::Destroy() {}

void Plugin::SetLibrary(void* library) {
    m_Library = library;
}

Plugin* Plugin::GetInstance() {
    return s_pInstance;
}
}  // namespace nn::nex
