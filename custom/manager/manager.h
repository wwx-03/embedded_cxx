#pragma once

#include <stddef.h>

namespace custom {

template<typename T, size_t N>
struct manager {
    T p[N];
    size_t u = 0;

    constexpr size_t size() const { return N; }

    T &operator[](size_t offset) {
        return p[offset];
    }

    manager &operator++() {
        if (u < N) {
            ++u;
        }
        return *this;
    }

    manager operator++(int) {
        manager temp = *this;
        ++(*this);
        return temp;
    }

    T &next() {
        if (u >= N) {
            u = 0;
        }
        return p[u++];
    }
};

};
