#pragma once

#include "Platform/Core/RootObject.h"

namespace nn {
namespace nex {
class Buffer;
class SignatureBytes;

class ChecksumAlgorithm : public nn::nex::RootObject {
public:
    ChecksumAlgorithm();

    virtual ~ChecksumAlgorithm();

    virtual bool ComputeChecksum(nn::nex::Buffer const&, nn::nex::Buffer*) = 0;
    virtual bool ComputeChecksum(u8 const**, u64 const*, u64, nn::nex::SignatureBytes&) = 0;
    virtual bool IsReady() const;
    virtual void ComputeChecksumForTransport(u8 const*, u64);
    virtual u32 ComputeChecksumForTransportArray(u8 const**, u64 const*, u64) = 0;
    virtual u32 GetChecksumLength() = 0;

    u64 _8;
    u8 _10;
};

}  // namespace nex
}  // namespace nn
