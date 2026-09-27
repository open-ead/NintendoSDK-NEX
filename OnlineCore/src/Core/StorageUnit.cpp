#include "Core/StorageUnit.h"

namespace nn::nex {
inline uint64_t clampMax(uint64_t val, uint64_t max_) {
    return val > max_ ? max_ : val;
}

bool StorageUnit::AppendData(const StorageUnit* source, StorageUnit* destination) {
    uint8_t buffer[4096];
    size_t sourceSize = source->GetSize();
    size_t destinationSize = destination->GetSize();

    uint64_t offset = 0;
    while (offset < sourceSize) {
        uint64_t nextOffset = clampMax(offset + sizeof(buffer), sourceSize);

        if (source->Read(offset, nextOffset - offset, buffer) == 0)
            return 0;

        if (destination->Write(offset + destinationSize, nextOffset - offset, buffer) == 0)
            return 0;

        offset = nextOffset;
    }
    return 1;
}

bool StorageUnit::CopyData(const StorageUnit* source, StorageUnit* destination) {
    destination->Truncate();
    return AppendData(source, destination);
}

uint32_t StorageUnit::GetReservedSize() {
    return 0;
}

}  // namespace nn::nex
