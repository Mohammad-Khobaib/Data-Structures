#pragma once

template<typename T>
class initializer_list {
private:
    T* m_data;
    unsigned int m_size;
public:
    initializer_list() : m_data(nullptr), m_size(0) {}
    
    template<typename... Args>
    initializer_list(Args... args) : m_data(new T[sizeof...(Args)]{args...}), m_size(sizeof...(Args)) {}
    
    ~initializer_list() {
        delete[] m_data;
    }

    unsigned int size() const {
        return m_size;
    }

    T* begin() {
        return &m_data[0];
    }

    const T* begin() const {
        return &m_data[0];
    }

    T* end() {
        return &m_data[m_size];
    }

    const T* end() const {
        return &m_data[m_size];
    }
};
