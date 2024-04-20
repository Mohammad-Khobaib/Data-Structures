#pragma once

#include "deque_iterator.hpp"

template<typename T>
class deque {
private:
    T* m_data;
    unsigned int m_size;
    unsigned int m_capacity;
    unsigned int front_idx;
    unsigned int back_idx;

    void re_allocate(unsigned int new_capacity) {
        T* new_data = (T*) malloc(new_capacity * sizeof(T));
        
        for (unsigned int i = 0; i < back_idx; i++) {
            new_data[i] = (T&&) m_data[i];
        }

        for (unsigned int i = front_idx + 1; i < m_capacity; i++) {
            new_data[i + m_capacity] = (T&&) m_data[i];
        }

        free(m_data);
        m_data = new_data;
        front_idx = front_idx + m_capacity;
        m_capacity = new_capacity;
    }

public:
    using iterator = deque_iterator<deque<T>>;
    using value_type = T;
    deque() : 
        m_data(nullptr), 
        m_size(0), 
        m_capacity(0), 
        front_idx(0), 
        back_idx(0) 
    {}

    template<typename... Args>
    deque(Args... args) : 
        m_data(new T[sizeof...(Args)]{args...}), 
        m_size(sizeof...(Args)), 
        m_capacity(sizeof...(Args)), 
        front_idx(sizeof...(Args) - 1), 
        back_idx(sizeof...(Args)) 
    {}

    ~deque() {
        free(m_data);
    }

    void push_back(const T& element) {
        if (m_size == m_capacity) {
            if (m_size == 0)
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }

        m_data[back_idx] = element;
        back_idx++;
        m_size++;
    }

    void push_front(const T& element) {
        if (m_size == m_capacity) {
            if (m_size == 0)
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }

        m_data[front_idx] = element;
        front_idx--;
        m_size++;
    }

    void pop_front() {
        front_idx = front_idx + 1;
        m_data[front_idx] = T();
        m_size--;
    }

    void pop_back() {
        back_idx = back_idx - 1;
        m_data[back_idx] = T();
        m_size--;
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        free(m_data);
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
        front_idx = 0;
        back_idx = 0;
    }

    T& operator[](unsigned int index) {
        return m_data[(front_idx + 1 + index) % m_capacity];
    }

    iterator begin() {
        return iterator(front_idx, m_capacity, 0, m_data);
    }

    iterator end() {
        return iterator(front_idx, m_capacity, m_size, m_data);
    }

    unsigned int size() const {
        return m_size;
    }

    unsigned int capacity() const {
        return m_capacity;
    }
};
