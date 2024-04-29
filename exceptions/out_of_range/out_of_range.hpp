#pragma once


namespace my_stl
{
class out_of_range {
private:
    char* m_message;
public:
    out_of_range(const char* message) : m_message((char*) message) {}
    const char* what() {
        return m_message;
    }
}; 
}
