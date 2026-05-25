#pragma once

#include "Core/StorageDevice.h"

namespace nn::nex {
class String;
class StorageUnit;

class FileStorageDevice : public StorageDevice {
public:
    FileStorageDevice();
    virtual ~FileStorageDevice();
    virtual StorageUnit* Create(const String&);
    virtual StorageUnit* Open(const String&);
    virtual bool Close(StorageUnit*);
    virtual bool Delete(const String&);
};
}  // namespace nn::nex
