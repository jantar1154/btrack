#include "util.h"
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using bt::Vec2D, bt::Datetime;

template <typename T>
bool Vec2D<T>::operator == (const Vec2D<T> &rhs) {
    return (x == rhs.x and y == rhs.y);
}

Datetime::Datetime(
    uint16_t year,
    uint8_t month,
    uint8_t day,
    uint8_t hour,
    uint8_t minute,
    uint8_t second):
    year {year},
    month {month},
    day {day},
    hour {hour},
    minute {minute},
    second {second} {}

Datetime::Datetime (const Datetime& other):
    year {other.year},
    month {other.month},
    day {other.day},
    hour {other.hour},
    minute {other.minute},
    second {other.second} { }

Datetime::Datetime (Datetime&& other):
    year {std::move(other.year)},
    month {std::move(other.month)},
    day {std::move(other.day)},
    hour {std::move(other.hour)},
    minute {std::move(other.minute)},
    second {std::move(other.second)} { }

Datetime& Datetime::operator = (const Datetime& other) {
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    this->hour = other.hour;
    this->minute = other.minute;
    this->second = other.second;

    return *this;
}

Datetime& Datetime::operator = (Datetime&& other) {
    this->year = std::move(other.year);
    this->month = std::move(other.month);
    this->day = std::move(other.day);
    this->hour = std::move(other.hour);
    this->minute = std::move(other.minute);
    this->second = std::move(other.second);

    return *this;
}

// YYYY-MM-DD HH:MM:SS
Datetime Datetime::from_iso8601(const std::string& str) {
    Datetime dt;
    std::stringstream ss {str};
    std::string tmp;

    std::getline(ss, tmp, '-');
    dt.year = static_cast<uint16_t> (std::stol(tmp));
    std::getline(ss, tmp, '-');
    dt.month = static_cast<uint8_t> (std::stoi(tmp));
    std::getline(ss, tmp, ' ');
    dt.day = static_cast<uint8_t> (std::stoi(tmp));
    std::getline(ss, tmp, ':');
    dt.hour = static_cast<uint8_t> (std::stoi(tmp));
    std::getline(ss, tmp, ':');
    dt.minute = static_cast<uint8_t> (std::stoi(tmp));
    std::getline(ss, tmp);
    dt.second = static_cast<uint8_t> (std::stoi(tmp));

    return dt;
}

std::string Datetime::to_iso8061() const {
    char ret[64];
    std::cerr << "MINUTE: " << static_cast<uint16_t>(minute) << std::endl;
    snprintf(ret, 64, "%04d-%02d-%02d %02d:%02d:%02d",
        year,
        month,
        day,
        hour,
        minute,
        second
    );

    return std::string { std::move(ret) };
}
