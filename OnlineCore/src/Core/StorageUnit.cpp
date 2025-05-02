#include "Core/StorageUnit.h"

namespace nn::nex {
inline u64 clampMax(u64 val, u64 max_) {
    return val > max_ ? max_ : val;
}

bool StorageUnit::AppendData(const StorageUnit* source, StorageUnit* destination) {
    u8 buffer[4096];
    size_t sourceSize = source->GetSize();
    size_t destinationSize = destination->GetSize();

    u64 offset = 0;
    while (offset < sourceSize) {
        u64 nextOffset = clampMax(offset + sizeof(buffer), sourceSize);

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

bool StorageUnit::Reserve(u64) {
    return false;
}

u32 StorageUnit::GetReservedSize() {
    return 0;
}

}  // namespace nn::nex
