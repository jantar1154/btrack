#pragma once

#include <algorithm>
#include <alloca.h>
#include <memory>
#include <optional>

namespace bt {

template <typename T>
struct Vec2D {
    T x;
    T y;
    bool operator == (const Vec2D<T> &rhs);
}; // Vec2D

} // Namespace
