#include "Platform/Core/DateTime.h"

/*
Bit representation of m_ulTime
| 63 - 40  | 39 - 26  | 25 - 22  | 21 - 17  | 16 - 12  | 11 - 6  |  5 - 0  |
| UNUSED   |  YEAR    |  MONTH   |   DAY    |   HOUR   | MINUTE  | SECOND  |
*/

namespace nn::nex {
DateTime::DateTime() : m_ulTime(0) {}

DateTime::DateTime(const DateTime& dateTime) : m_ulTime(dateTime.m_ulTime) {}

// DateTime::DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute,
// uint8_t second) {}

// DateTime::DateTime(const time::PosixTime& posixTime) {}

// DateTime& DateTime::operator=(const DateTime& dateTime) {}

// DateTime::DateTime(const time::CalendarTime& calendarTime) {}

DateTime::operator uint64_t() {
    return m_ulTime;
}

DateTime::operator uint64_t() const {
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

// void DateTime::FromUnixEpochTime(int64_t epochTime) {}

// int64_t DateTime::ToEpochTime() const {}

int32_t DateTime::GetYear() const {
    return (m_ulTime & 0xFFFC000000) >> 26;
}

int32_t DateTime::GetMonth() const {
    return (m_ulTime & 0x3C00000) >> 22;
}

int32_t DateTime::GetDay() const {
    return (m_ulTime & 0x3E0000) >> 17;
}

int32_t DateTime::GetHour() const {
    return (m_ulTime & 0x1F000) >> 12;
}

int32_t DateTime::GetMinute() const {
    return (m_ulTime & 0xFC0) >> 6;
}

int32_t DateTime::GetSecond() const {
    return m_ulTime & 0x3F;
}

// bool DateTime::IsValid() const {}

// bool DateTime::IsNever() const {}

// void DateTime::Trace(uint64_t) {}

// time::PosixTime DateTime::ToPosixTime() const {}

// int64_t DateTime::ToUnixEpochTime() const {}

// time::CalendarTime DateTime::ToCalendarTime() const {}

// void DateTime::GetSystemTime(DateTime& dateTime) {}

// void DateTime::GetLocalSystemTime(DateTime& dateTime) {}

// bool DateTime::IsLeapYear(int32_t year) const {}

// int32_t DateTime::DateToDays(int32_t year, int32_t month, int32_t day) const {}

// void DateTime::DaysToDate(int32_t days) {}

// void DateTime::FromCustomEpochTime(int64_t epochTime, int32_t customEpochYear) {}

// void DateTime::FromEpochTime(int64_t epochTime) {}

}  // namespace nn::nex
