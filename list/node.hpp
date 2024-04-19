#pragma once

template<typename T> 
class node {
public:
    T data;
    node<T> *prev;
    node<T> *next;
    node() : prev(nullptr), next(nullptr) {}
    node(T data) : data(data), prev(nullptr), next(nullptr) {}
    node(T data, node<T> *prev, node<T> *next) : data(data), prev(prev), next(next) {}
};
