#pragma once

namespace my_stl
{
template<typename T>
class forward_list_node {
public:
    using value_type = T;
    value_type data;
    forward_list_node<value_type>* next;
    forward_list_node<value_type>() : data(value_type()), next(nullptr) {}
    forward_list_node<value_type>(const value_type& data) : data(data), next(nullptr) {}
    forward_list_node<value_type>(value_type&& data) : data((value_type&&) data), next(nullptr) {}
    forward_list_node<value_type>(const value_type& data, forward_list_node<value_type>* next) : data(data), next(next) {}
    forward_list_node<value_type>(value_type&& data, forward_list_node<value_type>* next) : data((value_type&&) data), next(next) {}
};
}
