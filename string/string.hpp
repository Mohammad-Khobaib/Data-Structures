#pragma once

#include <iostream>

class string {
private:
    char* m_data;
    unsigned int m_size;

    unsigned int strlen(const char* str) {
        unsigned int length = 0;
        while (*str != '\0') {
            length++;
            str++;
        }
        return length;
    }

    void memcpy(char* dest, const char* src, unsigned int n) {
        for (unsigned int i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    }
public:
    string(): m_data(nullptr), m_size(0) {}

    string(const char* data) {
        m_size = strlen(data);
        m_data = new char[m_size + 1];
        memcpy(m_data, data, m_size + 1);
    }

    string(const string& other) {
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        memcpy(m_data, other.m_data, m_size + 1);
    }

    ~string() {
        delete[] m_data;
    }

    char operator[](unsigned int index) {
        return m_data[index];
    }

    char& at(unsigned int index) {
        return m_data[index];
    }

    unsigned int size() const {
        return m_size;
    }

    const char* data() const {
        return m_data;
    }

    void push_back(const char* str) {
        unsigned int str_size = strlen(str);
        char* new_data = new char[m_size + str_size + 1];
        memcpy(new_data, m_data, m_size);
        memcpy(new_data + m_size, str, str_size + 1);
        delete[] m_data;
        m_data = new_data;
        m_size += str_size;
    }

    string operator+(const string& other) {
        string result;
        result.push_back(m_data);
        result.push_back(other.m_data);
        return result;
    }

    string& operator+=(const string& other) {
        push_back(other.m_data);
        return *this;
    }

    void operator=(const string& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new char[m_size + 1];
            memcpy(m_data, other.m_data, m_size + 1);
        }
    }

};

std::ostream& operator<<(std::ostream& stream, const string& str) {
    stream << str.data();
    return stream;
}
