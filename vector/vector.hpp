#pragma once

template<typename T>
class vector {
private:
    T* m_data;
    unsigned int m_size;
    unsigned int m_capacity;
    void re_allocate(unsigned int new_capacity) {
        T* new_data = (T*) malloc(sizeof(T) * new_capacity);
        for (unsigned int i = 0; i < m_size; i++) {
            new_data[i] = (T&&) m_data[i];
        }
        free(m_data);
        m_data = new_data;
        m_capacity = new_capacity;
    }
public:
    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}
    
    template<typename... Args>
    vector(Args... args) : m_data(new T[sizeof...(Args)]{args...}), m_size(sizeof...(Args)), m_capacity(sizeof...(Args)) {}
    
    vector(const vector& other): m_data(nullptr), m_size(other.size()), m_capacity(other.size()) {
        m_data = (T*) malloc(sizeof(T) * other.size());
        for (unsigned int i = 0; i < other.size(); i++) {
            m_data[i] = other[i];
        }
    }

    ~vector() {
        free(m_data);
    }

    // Push back methods
    void push_back(const T& element) {
        if (m_size == m_capacity) {
            if (m_size == 0) 
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
        m_data[m_size] = element;
        m_size++;
    }

    void push_back(T&& element) {
        if (m_size == m_capacity) {
            if (m_size == 0) 
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
        m_data[m_size] = std::move(element);
        m_size++;
    }

    // Emplace back method
    template<typename... Args>
    T& emplace_back(Args... args) {
        if (m_size == m_capacity) {
            if (m_size == 0) 
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
        new(&m_data[m_size]) T(std::forward<Args>(args)...); // Perfect forwarding for constructor arguments
        m_size++;
        return m_data[m_size - 1];
    }

    void shrink_to_fit() {
        if (m_capacity > m_size)
            re_allocate(m_size);
    }

    // Size and Capacity methods
    unsigned int size() const {
        return m_size;
    }

    unsigned int capacity() const {
        return m_capacity;
    }

    // Operator overloads
    T& operator[](unsigned int index) {
        return m_data[index];
    }

    const T& operator[](unsigned int index) const {
        return m_data[index];
    }

    // Iterators
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
