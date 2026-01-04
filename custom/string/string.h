#pragma once

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

namespace custom {

class string {
private:
    static constexpr size_t N = 64;

    char data_[N];

public:
    string() {
        memset(data_, 0, N);
    }

    string(const char *string) {
        strncpy(data_, string, N - 1);
        data_[N - 1] = '\0';
    }

    string(const char *fmt, ...) {
        memset(data_, 0, N); 
        va_list args; 
        va_start(args, fmt);
        vsnprintf(data_, N, fmt, args);
        va_end(args);
    }

    string(const uint8_t *const data, size_t size) {
        size_t copy_size = N - 1 > size ? size : N - 1;
        memcpy(data_, data, N > size ? size : N);
        data_[copy_size] = '\0';
    }

    ~string() = default;

    size_t length() { return strlen(data_); }
    constexpr size_t size() const { return N; }
    char *c_str() { return data_; }
    uint8_t *data() { return (uint8_t *)data_; }

    string &operator=(const char *other) {
        strncpy(data_, other, N - 1);
        data_[N - 1] = '\0';
        return *this;
    }

    string &operator+=(const char *other) {
        strncat(data_, other, N - length() - 1);
        return *this;
    }

    string &operator+=(char other) {
        size_t len = length();
        if (len < N - 1) {
            data_[len] = other;
            data_[len + 1] = '\0';
        }
        return *this;
    }
};

};
