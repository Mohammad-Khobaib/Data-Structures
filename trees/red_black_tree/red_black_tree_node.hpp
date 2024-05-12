#pragma once

#include "../../utility/move.hpp"

namespace my_stl
{

template<typename T>
class red_black_tree;

template <typename RedBlackTree>
class red_black_tree_iterator;

template<typename T>
class red_black_tree_node {
public:
    using value_type = T;
    using reference = value_type&;
    using const_refernece = const value_type&;

    red_black_tree_node<value_type>() :
        data(value_type()),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        color('R')
    {}

    red_black_tree_node<value_type>(const_refernece data) :
        data(data),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        color('R') 
    {}

    red_black_tree_node<value_type>(value_type&& data) :
        data(move(data)),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        color('R') 
    {}

    red_black_tree_node<value_type>(const_refernece data, red_black_tree_node<value_type>* left, red_black_tree_node<value_type>* right) :
        data(data),
        left(left),
        right(right),
        parent(nullptr),
        color('R')
    {}

    red_black_tree_node<value_type>(value_type&& data, red_black_tree_node<value_type>* left, red_black_tree_node<value_type>* right) :
        data(movr(data)),
        left(left),
        right(right),
        parent(nullptr),
        color('R')
    {}

    bool is_leaf() {
        return left == nullptr && right == nullptr;
    }

    red_black_tree_node<value_type>* sibling() {
        if (parent == nullptr) 
            return nullptr;
        if (is_on_left()) 
            return parent -> right;
        else 
            return parent -> left;
    }

    red_black_tree_node<value_type>* in_order_successor() {
        red_black_tree_node<value_type>* temp = right;
        while (temp -> left != nullptr)
            temp = temp -> left;
        return temp;
    }

    red_black_tree_node<value_type>* in_order_predecessor() {
        red_black_tree_node<value_type>* temp = left;
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
    
    friend class red_black_tree<value_type>;
    friend class red_black_tree_iterator<red_black_tree<value_type>>;
public:
    value_type data;
    red_black_tree_node<value_type>* left;
    red_black_tree_node<value_type>* right;
    red_black_tree_node<value_type>* parent;
    char color;
};
} // namespace my_stl
