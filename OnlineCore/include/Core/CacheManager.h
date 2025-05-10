#pragma once

#include <nn/types.h>

namespace nn::nex {
class String;
class BasicCache;

class CacheManager {
public:
    CacheManager();
    ~CacheManager();

    BasicCache* GetCache(String const&);
};

}  // namespace nn::nex
