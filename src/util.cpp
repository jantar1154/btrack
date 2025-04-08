#include "util.h"

using bt::Vec2D;

template <typename T>
bool Vec2D<T>::operator == (const Vec2D<T> &rhs) {
    return (x == rhs.x and y == rhs.y);
}
