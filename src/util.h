#pragma once

#include <cstddef>

template <typename T>
struct Vec2D {
    T x;
    T y;
    bool operator == (const Vec2D<T> &rhs);
};
