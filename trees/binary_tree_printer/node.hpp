#pragma once

template<typename T>
class node {
public:
    T data;
    node<T>* left;
    node<T>* right;
    node() : left(nullptr), right(nullptr) {}
    node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    node(const T& val, node<T>* left, node<T>* right) : data(val), left(left), right(right) {}
};
