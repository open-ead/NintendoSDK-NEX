#include "Core/Checksum/SHA1/SHA1.h"
#include "Platform/Core/RootObject.h"
#include "nn/crypto.h"

namespace nn::nex {

Sha1::Sha1() {}

Sha1::~Sha1() {
    if (m_Sha1Impl)
        RootObject::operator delete(m_Sha1Impl);
}

void Sha1::Init() {
    if (m_Sha1Impl)
        return m_Sha1Impl->Initialize();

    crypto::detail::Sha1Impl* sha1Impl = (crypto::detail::Sha1Impl*)RootObject::operator new(
        sizeof(crypto::detail::Sha1Impl));  // operator new shouldn't inline here
    if (sha1Impl)
        sha1Impl->_68 = 0;

    m_Sha1Impl = sha1Impl;
    sha1Impl->Initialize();
}

void Sha1::Update(const void* ptr, u64 val) {
    m_Sha1Impl->Update(ptr, val);
}

void Sha1::GetHash(void* ptr, u64 val) {
    m_Sha1Impl->GetHash(ptr, val);
}

void Sha1::GenerateHash(void* ptr, u64 val, const void* ptr2, u64 val2) {
    crypto::GenerateSha1Hash(ptr, val, ptr2, val2);
}

}  // namespace nn::nex
