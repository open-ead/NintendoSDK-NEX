#pragma once

#include "Core/Checksum/Interface/ChecksumAlgorithm.h"

namespace nn {
namespace nex {
class Buffer;

class CRC16Checksum : public nn::nex::ChecksumAlgorithm {
public:
    CRC16Checksum();

    virtual ~CRC16Checksum();

    virtual bool ComputeChecksum(nn::nex::Buffer const&, nn::nex::Buffer*);
    virtual u32 ComputeChecksumForTransportArray(u8 const**, u64 const*, u64);
    virtual u32 GetChecksumLength();
};

}  // namespace nex
}  // namespace nn
