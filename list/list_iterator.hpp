#pragma once

#include "node.hpp"

template<typename list>
class list_iterator {
public:
    using T = typename list::value_type;
private:
    node<T> *element;
public:
    list_iterator(node<T>* element) : element(element) {}
    list_iterator& operator++() {
        element = element -> next;
        return *this;
    }
    bool operator!=(list_iterator& other) {
        return element != other.element;
    }
    T& operator*() {
        return element -> data;
    }

    node<T> *getNode() {
        return element;
    }
};
