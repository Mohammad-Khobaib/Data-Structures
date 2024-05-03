#pragma once

template<typename deque>
class deque_iterator {
public:
    using size_type = typename deque::size_type;
    using value_type = typename deque::value_type;
    using const_reference = const value_type&;
    using reference = value_type&;
    using difference_type = typename deque::difference_type;
    using pointer = typename deque::pointer;

    deque_iterator<deque>(size_type index, size_type front_idx, size_type capacity, value_type* data) : 
        m_index(index),
        m_front_idx(front_idx),
        m_capacity(capacity),
        m_data(data)
    {}

    deque_iterator<deque>(const deque_iterator<deque>& right) : 
        m_index(right.m_index),
        m_front_idx(right.m_front_idx),
        m_capacity(right.m_capacity),
        m_data(right.m_data)
    {}

    bool operator!=(const deque_iterator<deque>& right) const {
        return m_index != right.m_index;
    }

    deque_iterator<deque> operator+(size_type off) {
        return deque_iterator<deque>(m_index + off, m_front_idx, m_capacity, m_data);
    }

    deque_iterator<deque>& operator+=(size_type off) {
        m_index += off;
        return *this;
    }

    deque_iterator<deque>& operator++() {
        m_index++;
        return *this;
    }


    deque_iterator<deque> operator-(size_type off) {
        return deque_iterator<deque>(m_index - off, m_front_idx, m_capacity, m_data);
    }

    deque_iterator<deque>& operator-=(size_type off) {
        m_index -= off;
        return *this;
    }

    deque_iterator<deque>& operator--() {
        m_index--;
        return *this;
    }

    deque_iterator<deque> operator++(int) {
        deque_iterator<deque> copy = *this;
        ++(*this);
        return copy;
    }

    deque_iterator<deque> operator--(int) {
        deque_iterator<deque> copy = *this;
        --(*this);
        return copy;
    }

    value_type& operator*() const {
        return m_data[(m_front_idx + 1 + m_index) % m_capacity];
    }
private:
    size_type m_index;
    size_type m_front_idx;
    size_type m_capacity;
    value_type* m_data;
};
