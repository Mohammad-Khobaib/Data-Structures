#pragma once

#include "node.hpp"

template<typename forward_list>
class forward_list_iterator {
public:
    using T = typename forward_list::value_type;
    forward_list_iterator(node<T>* element) : element(element) {}
    bool operator!=(const forward_list_iterator& other) {
        return element != other.element;
    }
    forward_list_iterator& operator++() {
        element = element -> next;
        return *this;
    }

    T& operator*() {
        return element -> data;
    }
private:
    node<T>* element;
};
