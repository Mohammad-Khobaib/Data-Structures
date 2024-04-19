#pragma once

#include "node.hpp"
#include "list_iterator.hpp"

template<typename T>
class list {
private:
    node<T> *head;
    node<T> *tail;
    unsigned int m_size;

public:
    using iterator = list_iterator<list<T>>;
    using value_type = T;

    // Constructors
    list() : head(nullptr), tail(nullptr), m_size(0) {}
    template<typename... Args>
    list(Args... args) : head(nullptr), tail(nullptr), m_size(0) {
        for (const auto& it : {args...}) {
            push_back(it);
        }
    }

    // Destructor
    ~list() {
        clear();
    }

    // Push and Pop Operations
    void push_back(const T& element) {
        if (tail == nullptr) {
            tail = new node<T>(element);
            head = tail;
        } else {
            node<T> *new_node = new node<T>(element, tail, nullptr);
            tail->next = new_node;
            tail = new_node;
        }
        m_size++;
    }

    void push_front(const T& element) {
        if (head == nullptr) {
            head = new node<T>(element);
            tail = head;
        } else {
            node<T> *new_node = new node<T>(element, nullptr, head);
            head->prev = new_node;
            head = new_node;
        }
        m_size++;
    }

    void pop_front() {
        if (head == nullptr)
            return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            m_size--;
            return;
        }
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        m_size--;
    }

    void pop_back() {
        if (tail == nullptr)
            return;
        if (tail->prev == nullptr) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            m_size--;
            return;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        m_size--;
    }

    // Insert Operation
    iterator insert(iterator& position, unsigned int element_number, const T& element) {
        node<T> *current_node = position.getNode();
        node<T> *new_node = nullptr;
        for (unsigned int i = 1; i <= element_number; i++) {
            new_node = new node<T>(element, current_node, current_node->next);
            current_node->next = new_node;
            if (new_node->next != nullptr)
                new_node->next->prev = new_node;
            current_node = new_node;
        }
        m_size += element_number;
        return iterator(position.getNode()->next);
    }

    // Clearing the List
    void clear() {
        node<T> *current_node = head;
        node<T> *next_node = head;
        while (next_node != nullptr) {
            next_node = next_node->next;
            delete current_node;
            current_node = next_node;
        }
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }

    // Size and Empty Check
    unsigned int size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    // Front and Back Accessors
    const T& front() const {
        if (head == nullptr)
            throw T();
        else
            return head->data;
    }

    const T& back() const {
        if (tail == nullptr)
            throw T();
        else
            return tail->data;
    }

    // Iterators
    iterator begin() {
        return iterator(head);
    }

    iterator begin() const {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    iterator end() const {
        return iterator(nullptr);
    }
};
