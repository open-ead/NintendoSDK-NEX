#pragma once

#include "Platform/Core/RootObject.h"
namespace nn::nex {
class StringStream : public RootObject {
public:
    StringStream();
    virtual ~StringStream();

    void FreeBuffer();
    void GetLength() const;
    void Clear();
    void FreeBuffer(char*);
    void ResizeBuffer(u64);
    void TestFreeRoom(u64);
    void StreamNumber(u8);
    void AddBaseIfRequired();
    void StreamNumber(u32);
    void StreamNumber(s32);
    StringStream& operator<<(const char*);
    StringStream& operator<<(const nn::nex::StringStream&);
    StringStream& operator<<(bool);
    StringStream& operator<<(double);
    StringStream& operator<<(float);
    StringStream& operator<<(void const*);
    StringStream& operator<<(u64);
    StringStream& operator<<(long);
    void BytesDump(const unsigned char*, u64);
    void BytesAsciiDump(const unsigned char*, u64);
};
}  // namespace nn::nex
