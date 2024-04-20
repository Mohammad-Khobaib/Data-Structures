#pragma once

template<typename deque>
class deque_iterator {
public:
    using T = typename deque::value_type;

    deque_iterator(unsigned int front_idx, unsigned int m_capacity, unsigned int index, T* data)
        : front_idx(front_idx), m_capacity(m_capacity), index(index), data(data) {}

    bool operator!=(const deque_iterator& other) {
        return index != other.index;
    }

    deque_iterator& operator++() {
        index++;
        return *this;
    }

    T& operator*() {
        return data[(front_idx + 1 + index) % m_capacity];
    }

private:
    unsigned int front_idx;
    unsigned int m_capacity;
    unsigned int index;
    T* data;
};
