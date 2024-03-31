#pragma once

template<typename T, unsigned int N>
class array {
private:
    T data[N]; /**< The array data. */

public:
    // Constructors
    array() {
        for (unsigned int i = 0; i < N; ++i) {
            data[i] = T(); // Default initialization
        }
    }
    
    template<typename... Args>
    array(Args&&... args) : data{args...} {}

    array(const array& other) {
        for (unsigned int i = 0; i < N; ++i) {
            data[i] = other.data[i];
        }
    }

    // Access operators
    T& operator[](unsigned int index) {
        return data[index];
    }

    const T& operator[](unsigned int index) const {
        return data[index];
    }

    // Equality operator
    bool operator==(const array<T, N>& rhs) const {
        for (unsigned int i = 0; i < N; ++i) {
            if (data[i] != rhs.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Iterators
    T* begin() {
        return &data[0];
    }

    const T* begin() const {
        return &data[0];
    }

    T* end() {
        return &data[N];
    }

    const T* end() const {
        return &data[N];
    }

    // Size
    constexpr unsigned int size() const {
        return N;
    }
};
