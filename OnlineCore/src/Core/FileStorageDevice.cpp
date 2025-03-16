#include "Core/FileStorageDevice.h"
#include "Core/StorageUnit.h"

namespace nn::nex {
FileStorageDevice::FileStorageDevice() {}

FileStorageDevice::~FileStorageDevice() {}

StorageUnit* FileStorageDevice::Create(const String&) {
    return nullptr;
}

StorageUnit* FileStorageDevice::Open(const String&) {
    return nullptr;
}

bool FileStorageDevice::Close(StorageUnit* storageUnit) {
    if (storageUnit)
        delete storageUnit;
    return false;
}

bool FileStorageDevice::Delete(const String&) {
    return false;
}

}  // namespace nn::nex
