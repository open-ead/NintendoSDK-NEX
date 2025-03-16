#include "Platform/Core/DateTime.h"

/*
Bit representation of m_ulTime
| 63 - 40  | 39 - 26  | 25 - 22  | 21 - 17  | 16 - 12  | 11 - 6  |  5 - 0  |
| UNUSED   |  YEAR    |  MONTH   |   DAY    |   HOUR   | MINUTE  | SECOND  |
*/

namespace nn::nex {
DateTime::DateTime() : m_ulTime(0) {}

DateTime::DateTime(const DateTime& dateTime) : m_ulTime(dateTime.m_ulTime) {}

// DateTime::DateTime(u16 year, u8 month, u8 day, u8 hour, u8 minute, u8 second) {}

// DateTime::DateTime(const time::PosixTime& posixTime) {}

// DateTime& DateTime::operator=(const DateTime& dateTime) {}

// DateTime::DateTime(const time::CalendarTime& calendarTime) {}

DateTime::operator u64() {
    return m_ulTime;
}

DateTime::operator u64() const {
    return m_ulTime;
}

bool DateTime::operator==(const DateTime& other) const {
    return m_ulTime == other.m_ulTime;
}

bool DateTime::operator!=(const DateTime& other) const {
    return m_ulTime != other.m_ulTime;
}

bool DateTime::operator<(const DateTime& other) const {
    return m_ulTime < other.m_ulTime;
}

bool DateTime::operator>(const DateTime& other) const {
    return m_ulTime > other.m_ulTime;
}

bool DateTime::operator<=(const DateTime& other) const {
    return m_ulTime <= other.m_ulTime;
}

bool DateTime::operator>=(const DateTime& other) const {
    return m_ulTime >= other.m_ulTime;
}

// DateTime DateTime::operator-(const DateTime& other) const {}

// void DateTime::FromUnixEpochTime(s64 epochTime) {}

// s64 DateTime::ToEpochTime() const {}

s32 DateTime::GetYear() const {
    return (m_ulTime & 0xFFFC000000) >> 26;
}

s32 DateTime::GetMonth() const {
    return (m_ulTime & 0x3C00000) >> 22;
}

s32 DateTime::GetDay() const {
    return (m_ulTime & 0x3E0000) >> 17;
}

s32 DateTime::GetHour() const {
    return (m_ulTime & 0x1F000) >> 12;
}

s32 DateTime::GetMinute() const {
    return (m_ulTime & 0xFC0) >> 6;
}

s32 DateTime::GetSecond() const {
    return m_ulTime & 0x3F;
}

// bool DateTime::IsValid() const {}

// bool DateTime::IsNever() const {}

// void DateTime::Trace(u64) {}

// time::PosixTime DateTime::ToPosixTime() const {}

// s64 DateTime::ToUnixEpochTime() const {}

// time::CalendarTime DateTime::ToCalendarTime() const {}

// void DateTime::GetSystemTime(DateTime& dateTime) {}

// void DateTime::GetLocalSystemTime(DateTime& dateTime) {}

// bool DateTime::IsLeapYear(s32 year) const {}

// s32 DateTime::DateToDays(s32 year, s32 month, s32 day) const {}

// void DateTime::DaysToDate(s32 days) {}

// void DateTime::FromCustomEpochTime(s64 epochTime, s32 customEpochYear) {}

// void DateTime::FromEpochTime(s64 epochTime) {}

}  // namespace nn::nex