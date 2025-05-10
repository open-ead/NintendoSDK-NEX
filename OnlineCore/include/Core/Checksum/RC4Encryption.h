/**
 * @file encryption.h
 * @brief NEX Encryption Algorithm.
 */

#pragma once

#include "Platform/Core/RootObject.h"

namespace nn {
namespace nex {
class Buffer;
class Key;

class RC4Encryption : public nn::nex::EncryptionAlgorithm {
public:
    RC4Encryption();

    virtual ~RC4Encryption();

    virtual bool Encrypt(nn::nex::Buffer const&, nn::nex::Buffer*);
    virtual bool Encrypt(nn::nex::Buffer*);
    virtual bool Decrypt(nn::nex::Buffer const&, nn::nex::Buffer*);
    virtual bool Decrypt(nn::nex::Buffer*);

    virtual void KeyHasChanged();

    void GetDefaultKey();
    void PrepareEncryption();
    void ReinitStateArray();
    void SetReinitEverytime(bool);

    u8 _48[0x298 - 0x48];
};
}  // namespace nex
}  // namespace nn
