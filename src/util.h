#pragma once

#include <algorithm>
#include <alloca.h>
#include <cstdint>
#include <memory>
#include <optional>

namespace bt {

template <typename T>
struct Vec2D {
    T x;
    T y;
    bool operator == (const Vec2D<T> &rhs);
}; // Vec2D

struct Datetime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    explicit Datetime(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    Datetime() = default;
    Datetime (const Datetime&);
    Datetime (Datetime&&);

    // YYYY-MM-DD HH:MM:SS
    static Datetime from_iso8601(const std::string&);

    Datetime& operator = (const Datetime&);
    Datetime& operator = (Datetime&&);

    std::string to_iso8061() const;

};

} // Namespace
