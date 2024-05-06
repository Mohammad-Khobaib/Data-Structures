#pragma once

#include <initializer_list>

#include "list_node.hpp"
#include "list_iterator.hpp"
#include "../iterators/reverse_iterator/reverse_iterator.hpp"

namespace my_stl
{
template<typename T>
class list {
public:
    using value_type = T;
    using reference = value_type&;
    using size_type = unsigned int;
    using iterator = list_iterator<list<value_type>>;
    using const_iterator = list_iterator<const list<value_type>>;
    using pointer = value_type*;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;
    using node = list_node<value_type>;
    using difference_type = long int;

    list<value_type>() : m_head(new node()), m_tail(new node()), m_size(0) {
        m_head -> next = m_tail;
        m_tail -> prev = m_head;
    }

    list<value_type>(const std::initializer_list<value_type>& values) : m_head(new node()), m_tail(new node()), m_size(0) {
        m_head -> next = m_tail;
        m_tail -> prev = m_head;
        for (const_reference value : values) {
            push_back(value);
        }
    }

    ~list<value_type>() {
        clear();
        delete m_head;
        delete m_tail;
    }

    void push_back(const_reference val) {
        node* next = m_tail;
        node* prev = m_tail -> prev;
        node* new_node = new node(val, prev, next);
        prev -> next = new_node;
        next -> prev = new_node;
        m_size++;
    }

    void push_back(value_type&& val) {
        node* next = m_tail;
        node* prev = m_tail -> prev;
        node* new_node = new node((value_type&&) val, prev, next);
        prev -> next = new_node;
        next -> prev = new_node;
        m_size++;
    }

    void push_front(const_reference val) {
        node* prev = m_head;
        node* next = m_head -> next;
        node* new_node = new node(val, prev, next);
        prev -> next = new_node;
        next -> prev = new_node;
        m_size++;
    }

    void push_front(value_type&& val) {
        node* prev = m_head;
        node* next = m_head -> next;
        node* new_node = new node((value_type&&) val, prev, next);
        prev -> next = new_node;
        next -> prev = new_node;
        m_size++;
    }

    void emplace_front(value_type&& val) {
        push_front((value_type&&) val);
    }

    void emplace_back(value_type&& val) {
        push_back((value_type&&) val);
    }

    void pop_front() {
        if (m_head -> next == m_tail)
            return;
        node* removed_node = m_head -> next;
        node* next = removed_node -> next;
        node* prev = removed_node -> prev;
        prev -> next = next;
        next -> prev = prev;
        delete removed_node;
        m_size--;
    }

    void pop_back() {
        if (m_tail -> prev == m_head)
            return;
        node* removed_node = m_tail -> prev;
        node* next = removed_node -> next;
        node* prev = removed_node -> prev;
        prev -> next = next;
        next -> prev = prev;
        delete removed_node;
        m_size--;
    }

    reference back() {
        return m_tail -> prev -> data;
    }

    const_reference back() const {
        return m_tail -> prev -> data;
    }

    reference front() {
        return m_head -> next -> data;
    }

    const_reference front() const {
        return m_head -> next -> data;
    }

    size_type size() const {
        return m_size;
    }

    const_iterator begin() const {
        return const_iterator(m_head -> next);
    }

    iterator begin() {
        return iterator(m_head -> next);
    }

    const_iterator end() const {
        return const_iterator(m_tail);
    }

    iterator end() {
        return iterator(m_tail);
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        node* current_node = m_head -> next;
        node* removed_node = nullptr;
        while (current_node != m_tail) {
            removed_node = current_node;
            current_node = current_node -> next;
            delete removed_node;
        }
        m_head -> next = m_tail;
        m_tail -> prev = m_head;
    }

    void assign(size_type count, const_reference value) {
        clear();
        for (size_type i = 0; i < count; i++) {
            push_back(value);
        }
    }

    void assign(const std::initializer_list<value_type>& values) {
        clear();
        for (const_reference value: values) {
            push_back(value);
        }
    }

    reverse_iterator rbegin() {
        return reverse_iterator(m_tail -> prev);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(m_tail -> prev);
    }

    reverse_iterator rend() {
        return reverse_iterator(m_head);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(m_head);
    }

    const_iterator cbegin() const {
        return const_iterator(m_head -> next);
    }

    const_iterator cend() const {
        return const_iterator(m_tail);
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(m_tail -> prev);
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(m_head);
    }

    iterator emplace(iterator position, value_type&& val) {
        node* new_node = new node((value_type&&) val);
        node* next = position.m_node;
        node* prev = position.m_node -> prev;

        next -> prev = new_node;
        new_node -> next = next;
        prev -> next = new_node;
        new_node -> prev = prev;
        
        m_size++;

        return iterator(new_node);
    }

    iterator erase(iterator& position) {
        node* removed_node = position.m_node;
        node* next = removed_node -> next;
        node* prev = removed_node -> prev;
        prev -> next = next;
        next -> prev = prev;
        delete removed_node;
        m_size--;
        position.m_node = next;
        return iterator(next);
    }

    iterator erase(iterator first, iterator last) {
        while (first != last) {
            erase(first);
            ++first;
        }
        return last;
    }

    iterator insert(iterator position, const_reference val) {
        node* new_node = new node(val);
        node* next = position.m_node;
        node* prev = position.m_node -> prev;

        next -> prev = new_node;
        new_node -> next = next;
        prev -> next = new_node;
        new_node -> prev = prev;
        return iterator(new_node);
    }

    iterator insert(iterator& position, value_type&& val) {
        iterator it = emplace(position, (value_type&&) val);
        position.m_node = it.m_node;
        return it;
    }

    iterator insert(iterator position, size_type count, const_reference val) {
        for (size_type i = 0; i < count; i++) {
            insert(position, val);
        }
        return position;
    }

    iterator insert(iterator position, const std::initializer_list<value_type>& values) {
        for (const_reference val: values) {
            insert(position, val);
        }
        return position;
    }

    void merge(const list<value_type>& right) {
        node* dummy_node = new node();
        node* current_node = dummy_node;
        node* first = m_head -> next;
        node* last = right.m_head -> next;
        while (first != m_tail && last != right.m_tail) {
            if (first -> data < last -> data) {
                current_node -> next = first;
                first -> prev = current_node;
                current_node = first;
                first = first -> next;
            } else {
                current_node -> next = last;
                last -> prev = current_node;
                current_node = last;
                last = last -> next;
            }
        }
        if (last == nullptr) {
            current_node -> next = first;
            first -> prev = current_node;
        } else {
            current_node -> next = last;
            last -> prev = current_node;

            m_tail -> prev = right.m_tail -> prev;
            m_tail -> prev -> next = m_tail;
        }

        m_head -> next = dummy_node -> next;
        m_head -> next -> prev = m_head;

        right.m_head -> next = right.m_tail;
        right.m_tail -> prev = right.m_head;
        delete dummy_node;
    }

    void remove(const_reference val) {
        node* current_node = m_head -> next;
        node* next = nullptr;
        node* prev = nullptr;
        while (current_node != m_tail) {
            if (current_node -> data == val) {
                next = current_node -> next;
                prev = current_node -> prev;
                prev -> next = next;
                next -> prev = prev;
                delete current_node;
                current_node = next;
            } else {
                current_node = current_node -> next;
            }
        }
    }

    template<typename Predicate>
    void remove_if(Predicate compare) {
        node* current_node = m_head -> next;
        node* next = nullptr;
        node* prev = nullptr;
        while (current_node != m_tail) {
            if (compare(current_node -> data)) {
                next = current_node -> next;
                prev = current_node -> prev;
                prev -> next = next;
                next -> prev = prev;
                delete current_node;
                current_node = next;
            } else {
                current_node = current_node -> next;
            }
        }
    }

    void resize(size_type new_size, const_reference val = value_type()) {
        if (new_size == m_size)
            return;
        if (new_size < m_size) {
            int delete_count = m_size - new_size;
            for (size_type i = 0; i < delete_count; i++) {
                pop_back();
            }
        } else {
            int insert_count = new_size - m_size;
            for (size_type i = 0; i < insert_count; i++) {
                push_back(val);
            }
        }
    }

    void sort() {
        if (m_head -> next == m_tail)
            return;
        node* head = m_head -> next;
        head -> prev = nullptr;
        m_tail -> prev -> next = nullptr;
        node* new_head = sort_help(head);
        m_head -> next = new_head;
        new_head -> prev = m_head;
        m_tail -> prev = find_last_node(new_head);
        m_tail -> prev -> next = m_tail;
    }

    void reverse() {
        node* prev = nullptr;
        node* next = nullptr;
        node* current_node = m_head;
        while (current_node != nullptr) {
            next = current_node -> next;
            current_node -> next = prev;
            current_node -> prev = next;
            prev = current_node;
            current_node = next;
        }
        swap(m_head, m_tail);
    }

    void splice(const_iterator position, list<value_type>& source) {
        node* position_node = position.m_node;
        node* current_node = source.m_head -> next;
        node* next = nullptr;
        while (current_node != source.m_tail) {
            next = current_node -> next;
            insert_before(position_node, current_node);
            current_node = next;
            m_size++;
        }
        source.m_head -> next = source.m_tail;
        source.m_tail -> prev = source.m_head;
    }

    void swap(list<value_type>& right) {
        swap(m_head, right.m_head);
        swap(m_tail, right.m_tail);
    }

private:
    node *m_head;
    node *m_tail;
    size_type m_size;

    void insert_before(node* position, node* new_node) {
        node* prev = position -> prev;
        node* next = position;

        new_node -> next = next;
        new_node -> prev = prev;

        prev -> next = new_node;
        next -> prev = new_node;
    }

    void swap(node*& a, node*& b) {
        node* temp = a;
        a = b;
        b = temp;
    }

    node* find_last_node(node* head) {
        node* current_node = head;
        while (current_node -> next != nullptr) {
            current_node = current_node -> next;
        }
        return current_node;
    }

    node* sort_help(node* head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        node* middle = find_middle(head);
        node* middle_next = middle -> next;
        middle -> next = nullptr;
        middle_next -> prev = nullptr;
        node* left = sort_help(head);
        node* right = sort_help(middle_next);
        return merge(left, right);
    }

    node* find_middle(node* head) {
        node* fast = head -> next;
        node* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    node* merge(node* head1, node* head2) {
        node* dummy_node = new node();
        node* current_node = dummy_node;
        node* first = head1;
        node* last = head2;
        while (first != nullptr && last != nullptr) {
            if (first -> data < last -> data) {
                current_node -> next = first;
                first -> prev = current_node;
                current_node = first;
                first = first -> next;
            } else {
                current_node -> next = last;
                last -> prev = current_node;
                current_node = last;
                last = last -> next;
            }
        }
        if (last == nullptr) {
            current_node -> next = first;
            first -> prev = current_node;
        } else {
            current_node -> next = last;
            last -> prev = current_node;
        }
        node* new_head = dummy_node -> next;
        new_head -> prev = nullptr;
        delete dummy_node;
        return new_head;
    }
};
}
