#include "Core/Chrono.h"

namespace nn::nex {
Chrono::Chrono() {}

void Chrono::Reset() {
    dword_20 = 0;
    dword_24 = 2;
}

Chrono::~Chrono() {}

}  // namespace nn::nex
