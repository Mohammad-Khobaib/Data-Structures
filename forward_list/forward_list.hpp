#pragma once

#include "node.hpp"
#include "forward_list_iterator.hpp"
#include "../initializer_list/initializer_list.hpp"

template<typename T>
class forward_list {
private:
    node<T>* head;
public:
    using value_type = T;
    using iterator = forward_list_iterator<forward_list<T>>;

    forward_list() : head(nullptr) {}

    template<typename... Args>
    forward_list(Args... args) : head(nullptr) {
        node<T>* current_node = head;
        for (const auto it: {args...}) {
            if (current_node == nullptr) {
                current_node = new node<T>(it);
                head = current_node;
            } else {
                current_node -> next = new node<T>(it);
                current_node = current_node -> next;
            }
        }
    }
    
    ~forward_list() {
        clear();
    }

    void push_front(const T& element) {
        node<T>* new_node = new node<T>(element);
        if (head == nullptr) {
            head = new_node;
        } else {
            new_node -> next = head;
            head = new_node;
        }
    }

    void pop_front() {
        if (head == nullptr) 
            return;
        node<T>* deleted_node = head;
        head = head -> next;
        delete deleted_node;
    }

    void remove(const T& val) {
        node<T>* current_node = head;
        node<T>* prev_node = nullptr;

        while (current_node != nullptr) {
            if (current_node->data == val) {
                if (prev_node == nullptr) {
                    pop_front();
                    prev_node = nullptr;
                    current_node = head;
                } else {
                    prev_node->next = current_node->next;
                    delete current_node;
                    current_node = prev_node -> next;
                }
            } else {
                prev_node = current_node;
                current_node = current_node -> next;
            }
        }
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void assign(iterator it1, iterator it2) {
        clear();
        node<T>* current_node = head;
        for (iterator it = it1; it != it2; ++it) {
            if (current_node == nullptr) {
                current_node = new node<T>(*it);
                head = current_node;
            } else {
                current_node -> next = new node<T>(*it);
                current_node = current_node -> next;
            }
        }
    }

    void assign(unsigned int n, const T& val) {
        clear();
        for (unsigned int i = 0; i < n; i++) {
            push_front(val);
        }
    }

    void assign(const initializer_list<T>& li) {
        clear();
        node<T>* current_node = head;
        for (const T& it : li) {
            if (current_node == nullptr) {
                current_node = new node<T>(it);
                head = current_node;
            } else {
                current_node -> next = new node<T>(it);
                current_node = current_node -> next;
            }
        }
    }

    const T& front() {
        return head -> data;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    bool empty() {
        return head == nullptr;
    }
};
