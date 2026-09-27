#include "Platform/Core/Variant.h"

#include "Platform/Core/DateTime.h"
#include "Platform/Core/MemoryManager.h"
#include "Platform/Core/String.h"

namespace nn::nex {

template <typename T>
void SpecialDeleteArray(T* ptr) {  // This needs to be here to inline
    uint32_t* v1 = (uint32_t*)(ptr - 4);
    for (uint32_t i = 0; i < *v1; i++)  // from wii u, optimized out on switch
        ;
    MemoryManager::Free(v1);
}

Variant::Variant() {
    field_8 = Type::None;
}

Variant::Variant(const Variant& other) {
    *this = other;
}

// void Variant::operator=(const Variant& other) {}

Variant::~Variant() {}

Variant::Variant(int64_t value) {
    field_0.int64_t = value;
    field_8 = Type::Signed;
}

Variant::Variant(uint64_t value) {
    field_0.uint64_t = value;
    field_8 = Type::Unsigned;
}

Variant::Variant(int32_t value) {
    field_0.int64_t = value;
    field_8 = Type::Signed;
}

Variant::Variant(uint32_t value) {
    field_0.uint64_t = value;
    field_8 = Type::Unsigned;
}

Variant::Variant(double value) {
    field_0.d = value;
    field_8 = Type::Double;
}

Variant::Variant(bool value) {
    field_0.b = value;
    field_8 = Type::Bool;
}

// Variant::Variant(const String& value) : field_8(Type::String) {}

// Variant::Variant(const char* value) : field_8(Type::String) {}

Variant::Variant(const DateTime& value) : field_8(Type::DateTime) {
    field_0.uint64_t = value;
}

Variant::Type Variant::GetType() const {
    return field_8;
}

uint64_t Variant::GetUInt64Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.uint64_t;
    return 0;
}

int64_t Variant::GetInt64Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.int64_t;
    return 0;
}

int32_t Variant::GetInt32Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.int64_t;
    return 0;
}

uint32_t Variant::GetUInt32Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.uint64_t;
    return 0;
}

double Variant::GetDoubleValue() const {
    if (field_8 == Type::Double)
        return field_0.d;
    return 0.0;
}

bool Variant::GetBoolValue() const {
    return field_8 == Type::Bool && field_0.b != false;
}

// String Variant::GetStringValue() const {}

DateTime Variant::GetDateTimeValue() const {
    if (field_8 == Type::DateTime)
        return (DateTime)(field_0.uint64_t);

    return DateTime();
}

// bool Variant::operator==(const Variant& other) const {}

Variant& Variant::operator=(Variant&& other) {
    if (this == &other)
        return *this;

    if (field_8 == Type::String)
        SpecialDeleteArray<char>(field_0.str);

    field_8 = other.field_8;
    switch (other.field_8) {
    case Type::Signed:
        field_0.int64_t = other.field_0.int64_t;
        break;
    case Type::Double:
        field_0.d = other.field_0.d;
        break;
    case Type::String:
        field_0.str = other.field_0.str;
        break;
    case Type::DateTime:
        field_0.uint64_t = other.field_0.uint64_t;
        break;
    case Type::Unsigned:
        field_0.uint64_t = other.field_0.uint64_t;
        break;
    case Type::Bool:
        field_0.b = other.field_0.b;
        break;
    default:
        break;
    }
    other.field_8 = Type::None;

    return *this;
}

bool Variant::operator!=(const Variant& other) const {
    return !(this == &other);
}

void Variant::Trace(uint32_t level) const {}

}  // namespace nn::nex
