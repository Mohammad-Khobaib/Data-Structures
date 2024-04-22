#pragma once

template<typename T>
class node {
public:
    T data;
    node* next;
    node() : next(nullptr) {}
    node(const T& data) : data(data), next(nullptr) {}
    node(const T& data, node* next) : data(data), next(next) {}
};
