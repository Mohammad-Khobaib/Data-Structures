#pragma once

#include "../../stack/stack.hpp"
#include "../../utility/reference_selector.hpp"
#include "../../utility/is_const.hpp"

namespace my_stl
{
template <typename RedBlackTree>
class red_black_tree_iterator {
public:
    using node = typename RedBlackTree::node;
    using reference = typename reference_selector<RedBlackTree, is_const<RedBlackTree>::value>::reference;
    using value_type = typename RedBlackTree::value_type&;
    using const_reference = const value_type&;
    using pointer = typename RedBlackTree::pointer;
    using difference_type = long int;

    red_black_tree_iterator<RedBlackTree>() : m_stack(stack<node*>()){}

    red_black_tree_iterator<RedBlackTree>(const stack<node*>& m_stack) : 
        m_stack(m_stack)
    {}

    red_black_tree_iterator<RedBlackTree>(stack<node*>&& m_stack) : 
        m_stack(move(m_stack))
    {}

    red_black_tree_iterator<RedBlackTree>& operator++() {
        if (m_stack.empty()) {
            return *this;
        }
        node* current_node = m_stack.top();
        m_stack.pop();
        if (current_node -> right != nullptr) {
            current_node = current_node -> right;
            m_stack.push(current_node);
            while (current_node -> left != nullptr) {
                current_node = current_node -> left;
                m_stack.push(current_node);
            }
        }
        return *this;
    }

    red_black_tree_iterator<RedBlackTree>& operator--() {
        if (m_stack.empty()) {
            return *this;
        }
        node* current_node = m_stack.top();
        m_stack.pop();
        if (current_node -> left != nullptr) {
            current_node = current_node -> left;
            m_stack.push(current_node);
            while (current_node -> right != nullptr) {
                current_node = current_node -> right;
                m_stack.push(current_node);
            }
        }
        return *this;
    }

    bool operator!=(const red_black_tree_iterator<RedBlackTree>& right) const {
        return m_stack != right.m_stack;
    }

    reference operator*() const {
        return m_stack.top() -> data;
    }
public:
    stack<node*> m_stack;
};
} // namespace my_stl
