#pragma once

#include<initializer_list>

#include "forward_list_node.hpp"
#include "forward_list_iterator.hpp"
#include "../utility/move.hpp"
#include "../utility/lexicographical_compare.hpp"

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
    using const_iterator = forward_list_iterator<const forward_list<value_type>>;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;

    // Default constructor
    forward_list<value_type>() : 
        m_head(new node()) // Allocate a new node for the head of the new list
    {
        // Creates a new forward_list with a default constructed node as the head.
    }

    // Constructor taking an std::initializer_list
    forward_list<value_type>(const std::initializer_list<value_type>& values) : 
        m_head(new node()) // Allocate a new node for the head of the new list
    {
        // Creates a new forward_list with a default constructed node as the head,
        // and initializes it with the values from the provided initializer list.
        assign(values); // Assigns the values from the initializer list to the forward_list.
    }

    // Copy constructor
    forward_list<value_type>(const forward_list<value_type>& right) : 
        m_head(new node()) // Allocate a new node for the head of the new list
    {
        node* temp = m_head; // Create a pointer to traverse the new list
        node* right_node = right.m_head->next; // Pointer to traverse the original list

        // Iterate through the original list
        while (right_node != nullptr) {
            // Create a new node with the same data as the current node in the original list
            temp->next = new node(right_node->data);
            temp = temp->next; // Move to the next node in the new list
            right_node = right_node->next; // Move to the next node in the original list
        }
    }

    // Move constructor
    forward_list<value_type>(forward_list<value_type>&& right) : 
        m_head(new node()) // Allocate a new node for the head of the new list
    {
        // Move the head pointer from the 'right' list to the new list
        m_head->next = right.m_head->next;

        // Set the head pointer of the 'right' list to nullptr to indicate it's been moved from
        right.m_head->next = nullptr;
    }

    // Destructor
    ~forward_list<value_type>() {
        clear(); // Clear the list, deallocating all nodes except the head
        delete m_head; // Delete the head node
    }

    // Adds a new node with the given value to the front of the list
    void push_front(const_reference val) {
        // Create a new node with the given value
        node* new_node = new node(val);
        
        // Get the current head of the list
        node* prev_head = m_head->next;
        
        // Set the next pointer of the new node to the previous head
        new_node->next = prev_head;
        
        // Update the head of the list to point to the new node
        m_head->next = new_node;
    }

    // Adds a new node with the given value to the front of the list
    void push_front(value_type&& val) {
        // Create a new node with the given value (using move semantics)
        node* new_node = new node(move(val));
        
        // Get the current head of the list
        node* prev_head = m_head->next;
        
        // Set the next pointer of the new node to the previous head
        new_node->next = prev_head;
        
        // Update the head of the list to point to the new node
        m_head->next = new_node;
    }

    // Removes the first element from the list
    void pop_front() {
        // Check if the list is empty
        if (m_head->next == nullptr)
            return; // If empty, nothing to pop, so return

        // Get the pointer to the first node
        node* removed_node = m_head->next;

        // Update the head to point to the second node (removing the first node)
        m_head->next = removed_node->next;

        // Delete the removed node to free the memory
        delete removed_node;
    }

    // Removes all elements from the list
    void clear() {
        // Keep removing elements from the list until it's empty
        while (!empty()) {
            pop_front(); // Remove the first element from the list
        }
    }

    // Assigns elements from the range [it1, it2] to the list
    void assign(iterator first, iterator last) {
        clear(); // Clear the existing elements in the list

        // Initialize 'tail' pointer to the head of the list
        node* tail = m_head;

        // Iterate over the range [first, last)
        while (first != last) {
            // Create a new node with the value pointed to by 'first'
            tail -> next = new node(*first);
            
            // Move 'tail' to the newly added node
            tail = tail -> next;
            
            // Move to the next element in the range
            ++first;
        }
    }

    // Assigns 'count' elements with the value 'val' to the list
    void assign(size_type count, const_reference val) {
        clear(); // Clear the existing elements in the list

        // Add 'count' elements with the value 'val' to the list
        for (size_type i = 0; i < count; ++i) {
            push_front(val); // Add 'val' to the front of the list
        }
    }

    // Assigns elements from the initializer list 'values' to the list
    void assign(const std::initializer_list<value_type>& values) {
        clear(); // Clear the existing elements in the list

        // Initialize 'tail' pointer to the head of the list
        node* tail = m_head;

        // Iterate over the initializer list 'values'
        for (const_reference val : values) {
            // Create a new node with the value from the initializer list
            tail -> next = new node(val);
            
            // Move 'tail' to the newly added node
            tail = tail -> next;
        }
    }

    // Returns a reference to the first element in the list
    reference front() {
        return m_head -> next -> data; // Return a reference to the data of the first node after the head
    }

    // Returns a const reference to the first element in the list (for const objects)
    const_reference front() const {
        return m_head -> next -> data; // Return a const reference to the data of the first node after the head
    }

    // Returns an iterator pointing to the first element in the list
    iterator begin() {
        return iterator(m_head -> next); // Create an iterator starting from the first node after the head
    }

    // Returns a const iterator pointing to the first element in the list (for const objects)
    const_iterator begin() const {
        return const_iterator(m_head -> next); // Create a const iterator starting from the first node after the head
    }

    // Returns a const iterator pointing to the first element in the list (for const objects)
    const_iterator cbegin() const {
        return const_iterator(m_head -> next); // Create a const iterator starting from the first node after the head
    }

    // Returns a const iterator pointing to the past-the-end element in the list (for const objects)
    const_iterator cend() const {
        return const_iterator(nullptr); // Create a const iterator representing the past-the-end element
    }

    // Returns a const iterator pointing to the before-beginning element in the list (for const objects)
    const_iterator before_begin() const {
        return const_iterator(m_head); // Create a const iterator pointing to the before-beginning element
    }

    // Returns an iterator pointing to the before-beginning element in the list
    iterator before_begin() {
        return iterator(m_head); // Create an iterator pointing to the before-beginning element
    }

    // Returns a const iterator pointing to the before-beginning element in the list (for const objects)
    const_iterator cbefore_begin() const {
        return const_iterator(m_head); // Create a const iterator pointing to the before-beginning element
    }

    // Returns an iterator pointing to the end of the list
    iterator end() {
        return iterator(nullptr); // Create an iterator pointing to the end of the list
    }

    // Returns a const iterator pointing to the end of the list
    const_iterator end() const {
        return const_iterator(nullptr); // Create a const iterator pointing to the end of the list
    }

    // Checks if the list is empty
    bool empty() const {
        return m_head -> next == nullptr; // Returns true if the head's next pointer is null (indicating an empty list)
    }

    // Inserts a new element after the specified position using move semantics
    iterator emplace_after(const_iterator position, value_type&& new_value) {
        // Create an iterator pointing to the position after which the new element will be inserted
        iterator insert_position = iterator(position.m_node);

        // Save the next node after the insertion position
        node* next_node = insert_position.m_node -> next;

        // Insert the new node with the given value after the specified position
        insert_position.m_node -> next = new node(move(new_value), next_node);

        // Move the iterator to the newly inserted node
        ++insert_position;

        // Return the iterator pointing to the inserted element
        return insert_position;
    }

    // Inserts a new element at the front of the list using move semantics
    void emplace_front(value_type&& new_value) {
        // Pushes the new element to the front of the list, moving the value
        push_front(move(new_value));
    }

    // Removes the element following the specified position
    iterator erase_after(const_iterator position) {
        // Get a pointer to the node to be removed
        node* removed_node = position.m_node -> next;

        // Update the next pointer of the preceding node to skip the removed node
        position.m_node -> next = removed_node -> next;

        // Delete the removed node to free memory
        delete removed_node;

        // Return an iterator pointing to the element after the removed one
        return iterator(position.m_node -> next);
    }

     // Removes the elements in the range [first, last) from the list
    iterator erase_after(const_iterator first, const_iterator last) {
        // Convert const_iterators to iterators to enable modification
        iterator it_first = iterator(first.m_node);
        iterator it_last = iterator(last.m_node);

        // Get a pointer to the node after the first element to be removed
        node* current_node = it_first.m_node->next;

        // Pointer to the node being removed (initially set to the node after the first)
        node* removed_node = current_node;

        // Update the next pointer of the node before the first element to point to the node after the last element
        it_first.m_node->next = it_last.m_node;

        // Traverse the list and delete the nodes in the range [first, last)
        while (current_node != it_last.m_node) {
            // Move to the next node
            current_node = current_node->next;

            // Delete the removed node
            delete removed_node;

            // Update the pointer to the removed node
            removed_node = current_node;
        }

        // Return an iterator pointing to the node after the last removed element
        return it_last;
    }

    // Inserts a new element after the specified position with the given value
    iterator insert_after(const_iterator position, const_reference val) {
        return emplace_after(position, move(val));
    }

    // Inserts 'count' copies of 'val' after the specified position
    void insert_after(const_iterator position, size_type count, const_reference val) {
        for (size_type i = 0; i < count; i++) {
            insert_after(position, val);
        }
    }

    // Inserts elements from the initializer list 'values' after the specified position
    void insert_after(const_iterator position, const std::initializer_list<value_type>& values) {
        iterator it = iterator(position.m_node);
        for (const_reference value : values) {
            it = insert_after(it, value);
        }
    }

    // Removes all nodes with the given value from the list
    void remove(const_reference val) {
        // Start from the head of the list
        node *current_node = m_head;
        
        // Pointer to the node to be removed
        node *removed_node = nullptr;

        // Iterate through the list
        while (current_node -> next != nullptr) {
            // Check if the next node contains the value to be removed
            if (current_node -> next -> data == val) {
                // Save the node to be removed
                removed_node = current_node -> next;

                // Update the next pointer of the current node to skip the removed node
                current_node -> next = removed_node -> next;

                // Delete the removed node to free memory
                delete removed_node;
            } else {
                // Move to the next node
                current_node = current_node -> next;
            }
        }
    }

    // Removes elements from the list that satisfy the given predicate.
    template<typename Predicate>
    void remove_if(Predicate predicate) {
        // Initialize pointers for traversal
        node* current_node = m_head;
        node* removed_node = nullptr;

        // Traverse the list
        while (current_node -> next != nullptr) {
            // Check if the predicate holds true for the next node's data
            if (predicate(current_node -> next -> data)) {
                // If true, remove the node
                removed_node = current_node -> next;
                current_node -> next = removed_node -> next;
                delete removed_node;
            } else {
                // Move to the next node
                current_node = current_node -> next;
            }
        }
    }

    // Reverses the order of elements in the list.
    void reverse() {
        // Initialize pointers for traversal
        node* prev = nullptr;         // Pointer to the previous node
        node* current_node = m_head -> next; // Pointer to the current node being processed
        node* next = current_node;    // Pointer to the next node

        // Traverse the list and reverse pointers between nodes
        while (current_node != nullptr) {
            next = current_node -> next;    // Save the next node
            current_node -> next = prev;    // Reverse the pointer to the previous node
            prev = current_node;          // Move the prev pointer forward
            current_node = next;          // Move to the next node
        }

        m_head -> next = prev; // Update the head pointer to the new first element of the reversed list
    }

    // Merges the current forward_list with another forward_list.
    void merge(forward_list<value_type>& right) {
        // Perform the merge operation recursively and get the new head
        node* new_head = merge(m_head -> next, right.m_head -> next);
        // Update the head of the current list to point to the merged list
        m_head -> next = new_head;
        // Set the head of the 'right' list to nullptr as it's now merged
        right.m_head -> next = nullptr;
    }

    // Merges the current forward_list with another forward_list.
    template<typename Predicate>
    void merge(forward_list<value_type>& right, Predicate compare) {
        // Pointers to traverse both lists
        node* first = m_head -> next;
        node* last = right.m_head -> next;
        // Dummy node to simplify the merging process
        node* dummy_node = new node();
        // Pointer to keep track of the current node in the merged list
        node* current_node = dummy_node;

        // Traverse both lists until one of them reaches the end
        while (first != nullptr && last != nullptr) {
            // Compare the data of the current nodes based on the provided predicate
            if (compare(first -> data, last -> data)) {
                // If the data from 'last' list is smaller, attach it to the merged list
                current_node -> next = first;
                current_node = first;
                first = first -> next;
            } else {
                // If the data from 'first' list is smaller or equal, attach it to the merged list
                current_node -> next = last;
                current_node = last;
                last = last -> next;
            }
        }

        // Attach the remaining nodes of the non-empty list to the merged list
        if (first == nullptr) {
            current_node -> next = last;
        } else {
            current_node -> next = first;
        }

        // Update the head of the current list to point to the merged list
        m_head -> next = dummy_node -> next;
        // Set the head of the 'right' list to nullptr as it's now merged
        right.m_head -> next = nullptr;
        // Delete the dummy node used for merging
        delete dummy_node;
    }

    // Sorts the elements of the forward_list in ascending order.
    void sort() {
        // Call the private sort function to sort the list
        node* new_head = sort(m_head -> next);
        // Update the head of the list to point to the sorted list
        m_head -> next = new_head;
    }

    // Swaps the elements of the current forward_list with another forward_list.
    void swap(forward_list<value_type>& right) {
        node* temp = right.m_head -> next;
        right.m_head -> next = m_head -> next;
        m_head -> next = temp;
    }

    void unique()  {
        node* current_node = m_head -> next;
        while (current_node != nullptr && current_node -> next != nullptr) {
            if (current_node -> data == current_node -> next -> data) {
                erase_after(const_iterator(current_node));
            } else {
                current_node = current_node -> next;
            }
        }
    }

    void splice_after(const_iterator position, forward_list<value_type>& source) {
        if (source.m_head -> next == nullptr) {
            return;
        }
        node* tail = find_tail(source.m_head -> next);
        tail -> next = position.m_node -> next;
        position.m_node -> next = source.m_head -> next;
        source.m_head -> next = nullptr;
    }

    // Resize function to adjust the size of a linked list
    void resize(size_type new_size, const_reference val = value_type()) {
        size_type i = 0; // Initialize a counter for current size
        node* current_node = m_head; // Start from the head of the list

        // Traverse the list until either the new size is reached or the end of the list is reached
        while (i < new_size && current_node -> next != nullptr) {
            i++; // Increment the counter
            current_node = current_node -> next; // Move to the next node
        }

        // If there are remaining nodes beyond the new size, remove them
        if (current_node != nullptr) {
            const_iterator first = const_iterator(current_node); // Iterator pointing to the node to start deletion
            erase_after(first, const_iterator(nullptr)); // Erase nodes after 'first' until 'last'
        }

        // If the new size is greater than the current size, add new nodes with the given value
        if (i < new_size) {
            for (int j = i; j < new_size; j++) {
                current_node -> next = new node(val); // Create a new node with the given value
                current_node = current_node -> next; // Move to the next node
            }
        }
    }

    // Overloaded assignment operator to assign the contents of another forward list.
    forward_list<value_type>& operator=(const forward_list<value_type>& right) {
        if (this != &right) {
            assign(iterator(right.m_head -> next), iterator(nullptr));
        }
        return *this;
    }

    // Overloaded move assignment operator to move the contents of another forward list.
    forward_list<value_type>& operator=(forward_list<value_type>&& right) {
        if (this != &right) {
            clear();
            node* current_node = m_head;
            node* right_node = right.m_head -> next;
            while (right_node != nullptr) {
                current_node -> next = right_node;
                current_node = right_node;
                right_node = right_node -> next;
            }
            right.m_head -> next = nullptr;
        }
        return *this;
    }

    //Overloaded equality operator to compare two forward lists for equality.
    bool operator==(const forward_list<value_type>& right) {
        node* first = m_head -> next;
        node* last = right.m_head -> next;
        while (first != nullptr && last != nullptr) {
            if (first -> data != last -> data) {
                return false;
            }
            first = first -> next;
            last = last -> next;
        }
        if (first == nullptr && last == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    // Overloaded inequality operator to compare two forward lists for inequality.
    bool operator!=(const forward_list<value_type>& right) {
        return !(*this == right);
    }

    // Overloaded less-than operator to compare two forward lists lexicographically.
    bool operator<(const forward_list<value_type>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend());
    }

    // Overloaded greater-than operator to compare two forward lists lexicographically.
    bool operator>(const forward_list<value_type>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend());
    }

    // Overloaded greater-than or equal operator to compare two forward lists lexicographically.
    bool operator>=(const forward_list<value_type>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend()) || *this == right;
    }

    // Overloaded greater-than or equal operator to compare two forward lists lexicographically.
    bool operator<=(const forward_list<value_type>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend()) || *this == right;
    }

private:
    node* m_head;

    // Merges two sorted linked lists into a single sorted linked list.
    node* merge(node* head1, node* head2) {
        // Create a dummy node to simplify merging
        node* dummy_node = new node();
        node* current_node = dummy_node;

        // Merge the lists while both are non-empty
        while (head1 != nullptr && head2 != nullptr) {
            // Compare the data of the current nodes and attach the smaller one
            if (head1 -> data < head2 -> data) {
                current_node -> next = head1;
                current_node = head1;
                head1= head1 -> next;
            } else {
                current_node -> next = head2;
                current_node = head2;
                head2= head2 -> next;
            }
        }

        // Attach the remaining nodes of the non-empty list
        if (head1 == nullptr) {
            current_node -> next = head2;
        } else {
            current_node -> next = head1;
        }

        // Get the head of the merged list and delete the dummy node
        node* new_head = dummy_node -> next;
        delete dummy_node;
        return new_head;
    }

    // Inserts a new element after the specified position.
    iterator insert_after(iterator position, const_reference new_value) {
        // Create an iterator pointing to the position after which the new element will be inserted
        iterator insert_position = iterator(position.m_node);

        // Save the next node after the insertion position
        node* next_node = insert_position.m_node -> next;

        // Insert the new node with the given value after the specified position
        insert_position.m_node -> next = new node(move(new_value), next_node);

        // Move the iterator to the newly inserted node
        ++insert_position;

        // Return the iterator pointing to the inserted element
        return insert_position;
    }

    // Finds the middle node of a linked list.
    node* find_middle(node* head) {
        if (head == nullptr)
            return nullptr;
        node* fast = head -> next;
        node* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    // Sorts the elements of the forward_list recursively using merge sort algorithm.
    node* sort(node* head) {
        // Base case: if the list is empty or contains only one element, it is already sorted
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }

        // Find the middle node of the list
        node* middle = find_middle(head);

        // Sort the right half of the list recursively
        node* right = sort(middle -> next);
        // Disconnect the right half from the middle node to separate the list
        middle -> next = nullptr;

        // Sort the left half of the list recursively
        node* left = sort(head);

        // Merge the sorted left and right halves
        return merge(left, right);
    }

    // Finds the tail node of a singly-linked list starting from the given
    node* find_tail(node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        node* temp = head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }
        return temp;
    }
};
} // namespace my_stl
