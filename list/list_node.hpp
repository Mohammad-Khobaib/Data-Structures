#pragma once

namespace my_stl
{
template<typename T> 
class list_node {
public:
    using value_type = T;
    using const_reference = const value_type&;
    
    value_type data;
    list_node<value_type> *prev;
    list_node<value_type> *next;

    list_node<value_type>() : 
        data(value_type()), 
        prev(nullptr), 
        next(nullptr) 
    {}

    list_node<value_type>(const_reference data) : 
        data(data), 
        prev(nullptr), 
        next(nullptr) 
    {}

    list_node<value_type>(value_type&& data) : 
        data((value_type&&) data), 
        prev(nullptr), 
        next(nullptr) 
    {}

    list_node<value_type>(const_reference data, list_node<value_type> *prev, list_node<value_type> *next) : 
        data(data), 
        prev(prev), 
        next(next) 
    {}

    list_node<value_type>(value_type&& data, list_node<value_type> *prev, list_node<value_type> *next) : 
        data((value_type&&) data), 
        prev(prev), 
        next(next) 
    {}
};
}
