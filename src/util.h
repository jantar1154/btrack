#pragma once

#include <algorithm>
#include <alloca.h>
#include <memory>
#include <optional>

template <typename T>
struct Vec2D {
    T x;
    T y;
    bool operator == (const Vec2D<T> &rhs);
}; // Vec2D

namespace bt {

template <typename T>
class Vector {
    std::allocator<T> allocator;
    T *items;
    size_t size = 0;
    size_t max_size = 4;

public:
    Vector();
    ~Vector();

    void add(const T&);
    void add(T&&);
    std::optional<T> get(size_t) const;
    void remove(size_t);
}; // Vector

template <typename T>
Vector<T>::Vector() { items = allocator.allocate(max_size); }

template <typename T>
Vector<T>::~Vector() { if (items) allocator.deallocate(items, max_size); }

template <typename T>
void Vector<T>::add(const T &item) {
    if (size == max_size) {
        max_size *= 2;
        // make array larger
        T *tmp = allocator.allocate(max_size);
        if (items) {
            std::copy(items, items + size, tmp);
            allocator.deallocate(items, max_size); // Use max_size here
        }

        items = tmp;
    }
    items[size++] = item;
}

template <typename T>
void Vector<T>::add(T &&item) {
    if (size == max_size) {
        max_size *= 2;
        // make array larger
        T *tmp = allocator.allocate(max_size);
        std::copy(items, items + size, tmp);
        allocator.deallocate(items, max_size); // Use max_size here

        items = tmp;
    }
    items[size++] = item;
}

template <typename T>
std::optional<T> Vector<T>::get(size_t index) const {
    if (index >= size) return std::nullopt;
    return items[index];
}

template <typename T>
void Vector<T>::remove(size_t index) {
    if (index >= size) return;
    std::copy(items + index + 1, items + size, items + index);
    size --;
}

} // namespace
