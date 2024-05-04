#pragma once

#include<initializer_list>

#include "forward_list_node.hpp"
#include "forward_list_iterator.hpp"

namespace my_stl
{
template<typename T>
class forward_list {

public:
    using value_type = T;
    using iterator = forward_list_iterator<forward_list<value_type>>;
    using node = forward_list_node<value_type>;
    using size_type = unsigned int;
    using reference = value_type&;
    using pointer = value_type*;
    using difference_type = long int;
    using const_iterator = const iterator;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;

    forward_list<value_type>() : m_head(new node(value_type())) {}

    forward_list<value_type>(const std::initializer_list<value_type>& values) : m_head(new node(value_type())) {
        assign(values);
    }
    
    ~forward_list<value_type>() {
        clear();
        delete m_head;
    }

    void push_front(const value_type& val) {
        node* new_node = new node(val);
        node* prev_head = m_head -> next;
        new_node -> next = prev_head;
        m_head -> next = new_node;
    }

    void push_front(T&& val) {
        node* new_node = new node(val);
        node* prev_head = m_head -> next;
        new_node -> next = prev_head;
        m_head -> next = new_node;
    }

    void pop_front() {
        if (m_head == nullptr) 
            return;
        node* removed_node = m_head;
        m_head = m_head -> next;
        delete removed_node;
    }


    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void assign(iterator it1, iterator it2) {
        clear();
        node* tail = m_head;
        while (it1 != it2) {
            tail -> next = new node(*it1);
            tail = tail -> next;
            ++it1;
        }
    }

    void assign(size_type count, const_reference val) {
        clear();
        for (size_type i = 0; i < count; i++) {
            push_front(val);
        }
    }

    void assign(const std::initializer_list<value_type>& values) {
        clear();
        node* tail = m_head;
        for (const_reference value : values) {
            tail -> next = new node(value);
            tail = tail -> next;
        }
    }

    reference front() {
        return m_head -> next -> data;
    }

    const_reference front() const {
        return m_head -> next -> data;
    }

    iterator begin() {
        return iterator(m_head -> next);
    }

    const_iterator begin() const {
        return iterator(m_head -> next);
    }

    const_iterator before_begin() const {
        return iterator(m_head);
    }

    iterator before_begin() {
        return iterator(m_head);
    }

    const_iterator cbefore_begin() const {
        return iterator(m_head);
    }

    const_iterator cbegin() const {
        return iterator(m_head -> next);
    }

    const_iterator cend() const {
        return iterator(nullptr);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator end() const {
        return iterator(nullptr);
    }

    bool empty() const {
        return m_head -> next == nullptr;
    }

    iterator emplace_after(const_iterator position, value_type&& val) {
        iterator it = iterator(position.m_node);
        node* temp = it.m_node -> next;
        it.m_node -> next = new node(val, temp);
        ++it;
        return it;
    }

    void emplace_front(value_type&& val) {
        push_front(val);
    }

    iterator erase_after(const_iterator position) {
        iterator it = iterator(position.m_node);
        node* removed_node = it.m_node -> next;
        it.m_node -> next = removed_node -> next;
        delete removed_node;
        ++it;
        return it;
    }

    iterator erase_after(const_iterator first, const_iterator last) {
        iterator it_first = iterator(first.m_node);
        iterator it_last = iterator(last.m_node);
        node* current_node = it_first.m_node -> next;
        node* removed_node = current_node;
        it_first.m_node -> next = it_last.m_node;
        while (current_node != it_last.m_node) {
            current_node = current_node -> next;
            delete removed_node;
            removed_node = current_node;
        }
        return it_last;
    }

    iterator insert_after(const_iterator position, const_reference val) {
        return emplace_after(position, (value_type&&) val);
    }

    void insert_after(const_iterator position, size_type count, const_reference val) {
        for (size_type i = 0; i < count; i++) {
            emplace_after(position, (value_type&&) val);
        }
    }

    void insert_after(const_iterator position, const std::initializer_list<value_type>& values) {
        iterator it = iterator(position.m_node);
        for (const_reference value: values) {
            it = emplace_after(it, (value_type&&) value);
        }
    }

    iterator insert_after(const_iterator position, value_type&& val) {
        return emplace_after(position, (value_type&&) val);
    }

    void remove(const_reference val) {
        node* current_node = m_head;
        node* removed_node = nullptr;
        while (current_node -> next != nullptr) {
            if (current_node -> next -> data == val) {
                removed_node = current_node -> next;
                current_node -> next = removed_node -> next;
                delete removed_node;
            } else {
                current_node = current_node -> next;
            }
        }
    }

    template<typename Predicate>
    void remove_if(Predicate predicate) {
        node* current_node = m_head;
        node* removed_node = nullptr;
        while (current_node -> next != nullptr) {
            if (predicate(current_node -> next -> data)) {
                removed_node = current_node -> next;
                current_node -> next = removed_node -> next;
                delete removed_node;
            } else {
                current_node = current_node -> next;
            }
        }
    } 

    void merge(forward_list<value_type>& right) {
        node* first = m_head -> next;
        node* last = right.m_head -> next;
        node* dummy_node = new node();
        node* current_node = dummy_node;
        while (first != nullptr && last != nullptr) {
            if (first -> data < last -> data) {
                current_node -> next = first;
                current_node = first;
                first = first -> next;
            } else {
                current_node -> next = last;
                current_node = last;
                last = last -> next;
            }
        }
        if (first == nullptr)
            current_node -> next = last;
        else 
            current_node -> next = first;
        m_head -> next = dummy_node -> next;
        right.m_head -> next = nullptr;
        delete dummy_node;
    }

    template<typename Predicate>
    void merge(forward_list<value_type>& right, Predicate compare) {
        node* first = m_head -> next;
        node* last = right.m_head -> next;
        node* dummy_node = new node();
        node* current_node = dummy_node;
        while (first != nullptr && last != nullptr) {
            if (compare(last -> data, first -> data)) {
                current_node -> next = first;
                current_node = first;
                first = first -> next;
            } else {
                current_node -> next = last;
                current_node = last;
                last = last -> next;
            }
        }
        if (first == nullptr)
            current_node -> next = last;
        else 
            current_node -> next = first;
        m_head -> next = dummy_node -> next;
        right.m_head -> next = nullptr;
        delete dummy_node;
    }

    void resize(size_type new_size, const_reference val = value_type()) {
        size_type i = 0;
        node* current_node = m_head;
        while (i < new_size && current_node -> next != nullptr) {
            i++;
            current_node = current_node -> next;
        }
        if (current_node != nullptr) {
            const_iterator first = iterator(current_node);
            const_iterator last = end();
            erase_after(first, last);
        }
        if (i < new_size) {
            for (int j = i; j < new_size; j++) {
                current_node -> next = new node(val);
                current_node = current_node -> next;
            }
        }
    }

    void reverse() {
        node* prev = nullptr;
        node* current_node = m_head -> next;
        node* next = current_node;
        while (current_node != nullptr) {
            next = current_node -> next;
            current_node -> next = prev;
            prev = current_node;
            current_node = next;
        }
        m_head -> next = prev;
    }
private:
    node* m_head;
};
}
