#pragma once

template<typename T>
class node {
public:
    T data;
    node<T>* left;
    node<T>* right;
    node<T>* parent;
    char color;

    node() : left(nullptr), right(nullptr), parent(nullptr), color('R') {}
    node(const T& data) : data(data), left(nullptr), right(nullptr), parent(nullptr), color('R') {}
    node(const T& data, node<T>* left, node<T>* right) : data(data), left(left), right(right), color('R') {}

    bool is_leaf() {
        return left == nullptr && right == nullptr;
    }

    node<T>* sibling() {
        if (parent == nullptr) 
            return nullptr;
        if (is_on_left()) 
            return parent -> right;
        else 
            return parent -> left;
    }

    node<T>* successor() {
        node<T>* temp = right;
        while (temp -> left != nullptr)
            temp = temp -> left;
        return temp;
    }

    node<T>* predecessor() {
        node<T>* temp = left;
        while (temp -> right != nullptr)
            temp = temp -> right;
        return temp;
    }

    bool has_red_child() {
        return (left != nullptr && left -> color == 'R') || (right != nullptr && right -> color == 'R');
    }

    bool is_on_left() {
        return this == parent -> left;
    }
};
