#include "Platform/Core/Variant.h"

#include "Platform/Core/DateTime.h"
#include "Platform/Core/MemoryManager.h"
#include "Platform/Core/String.h"

namespace nn::nex {

template <typename T>
void SpecialDeleteArray(T* ptr) {  // This needs to be here to inline
    u32* v1 = (u32*)(ptr - 4);
    for (u32 i = 0; i < *v1; i++)  // from wii u, optimized out on switch
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

Variant::Variant(s64 value) {
    field_0.s64 = value;
    field_8 = Type::Signed;
}

Variant::Variant(u64 value) {
    field_0.u64 = value;
    field_8 = Type::Unsigned;
}

Variant::Variant(s32 value) {
    field_0.s64 = value;
    field_8 = Type::Signed;
}

Variant::Variant(u32 value) {
    field_0.u64 = value;
    field_8 = Type::Unsigned;
}

Variant::Variant(f64 value) {
    field_0.f64 = value;
    field_8 = Type::Double;
}

Variant::Variant(bool value) {
    field_0.b = value;
    field_8 = Type::Bool;
}

// Variant::Variant(const String& value) : field_8(Type::String) {}

// Variant::Variant(const char* value) : field_8(Type::String) {}

Variant::Variant(const DateTime& value) : field_8(Type::DateTime) {
    field_0.u64 = value;
}

Variant::Type Variant::GetType() const {
    return field_8;
}

u64 Variant::GetUInt64Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.u64;
    return 0;
}

s64 Variant::GetInt64Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.s64;
    return 0;
}

s32 Variant::GetInt32Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.s64;
    return 0;
}

u32 Variant::GetUInt32Value() const {
    if (field_8 == Type::Unsigned || field_8 == Type::Signed)
        return field_0.u64;
    return 0;
}

f64 Variant::GetDoubleValue() const {
    if (field_8 == Type::Double)
        return field_0.f64;
    return 0.0;
}

bool Variant::GetBoolValue() const {
    return field_8 == Type::Bool && field_0.b != false;
}

// String Variant::GetStringValue() const {}

DateTime Variant::GetDateTimeValue() const {
    if (field_8 == Type::DateTime)
        return (DateTime)(field_0.u64);

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
        field_0.s64 = other.field_0.s64;
        break;
    case Type::Double:
        field_0.f64 = other.field_0.f64;
        break;
    case Type::String:
        field_0.str = other.field_0.str;
        break;
    case Type::DateTime:
        field_0.u64 = other.field_0.u64;
        break;
    case Type::Unsigned:
        field_0.u64 = other.field_0.u64;
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

void Variant::Trace(u32 level) const {}

}  // namespace nn::nex
