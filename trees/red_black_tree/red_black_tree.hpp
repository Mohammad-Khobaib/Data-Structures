#pragma once

#include<initializer_list>

#include "red_black_tree_node.hpp"
#include "../../exceptions/runtime_error/runtime_error.hpp"
#include "../../stack/stack.hpp"
#include "../../iterators/reverse_iterator/reverse_iterator.hpp"
#include "red_black_tree_iterator.hpp"

namespace my_stl
{
template<typename T>
class red_black_tree {
public:
    using value_type = T;
    using reference = value_type&;
    using pointer = value_type*;
    using size_type = unsigned int;
    using const_reference = const value_type&;
    using node = red_black_tree_node<value_type>;
    using iterator = red_black_tree_iterator<red_black_tree<value_type>>;
    using const_iterator = red_black_tree_iterator<const red_black_tree<value_type>>;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;

    // Red-Black Tree constructor initializing root and color flags.
    red_black_tree<value_type>() : 
        root(nullptr),
        m_size(0),
        ll(false),
        rr(false),
        rl(false),
        lr(false)
    {}

    // Constructor taking an std::initializer_list
    red_black_tree<value_type>(const std::initializer_list<value_type>& values) : 
        root(nullptr),
        m_size(0),
        ll(false),
        rr(false),
        rl(false),
        lr(false)
    {
        for (const_reference val: values) {
            insert_node(val);
        }
    }

    // Red-Black Tree destructor calling destroy_tree to deallocate memory.
    ~red_black_tree() {
        destroy_tree(root);
    }
    
    // Inserts a new node with the given data into the Red-Black Tree.
    void insert_node(const_reference data) {
        if (root == nullptr) {
            root = new node(data);
            root -> color = 'B';
        } else {
            root = insert_help(root, data);
        }
    }

    // Deletes the node containing the given data from the Red-Black Tree.
    void delete_node(const_reference data) {
        node* deletable_node = find_deletable_node(root, data);
        if (deletable_node == nullptr) {
            return;
        }
        delete_help(deletable_node);
    }

    // Searches for a node containing the given data in the Red-Black Tree.
    reference search_node(const_reference data) {
        node* result = search_node(root, data);
        if (result == nullptr)
            throw runtime_error("node not found");
        else 
            return result -> data;
    }

    // Searches for a node containing the given data in the Red-Black Tree.
    const_reference search_node(const_reference data) const {
        node* result = search_node(root, data);
        if (result == nullptr)
            throw runtime_error("node not found");
        else 
            return result -> data;
    }
    
    // Returns an iterator pointing to the first element in the Red-Black Tree.
    iterator begin() {
        iterator it = iterator();
        populate_stack_with_leftmost_nodes(root, it.m_stack);
        return it;
    }

    // Returns a const iterator pointing to the first element in the Red-Black Tree.
    const_iterator begin() const {
        const_iterator it = const_iterator();
        populate_stack_with_leftmost_nodes(root, it.m_stack);
        return it;
    }

    // Returns an iterator pointing to the position just beyond the last element in the Red-Black Tree.
    iterator end() {
        return iterator(stack<node*>());
    }

    // Returns a const iterator pointing to the position just beyond the last element in the Red-Black Tree.
    const_iterator end() const {
        return const_iterator(stack<node*>());
    }
    
    // Returns a constant iterator pointing to the first element in the Red-Black Tree.
    const_iterator cbegin() const {
        const_iterator it = const_iterator();
        populate_stack_with_leftmost_nodes(root, it.m_stack);
        return it;
    }

    // Returns a constant iterator pointing to the position just beyond the last element in the Red-Black Tree.
    const_iterator cend() const {
        return const_iterator(stack<node*>());
    }

    // Returns a reverse iterator pointing to the last element in the Red-Black Tree.
    reverse_iterator rbegin() {
        iterator it = iterator();
        populate_stack_with_rightmost_nodes(root, it.m_stack);
        return reverse_iterator(it);
    }

    // Returns a const reverse iterator pointing to the last element in the Red-Black Tree.
    const_reverse_iterator rbegin() const {
        const_iterator it = const_iterator();
        populate_stack_with_rightmost_nodes(root, it.m_stack);
        return const_reverse_iterator(it);
    }

    // Returns a reverse iterator pointing to the position just before the first element in the Red-Black Tree.
    reverse_iterator rend() {
        return reverse_iterator(iterator(stack<node*>()));
    }

    // Returns a const reverse iterator pointing to the position just before the first element in the Red-Black Tree.
    const_reverse_iterator rend() const {
        return const_reverse_iterator(const_iterator(stack<node*>()));
    }

    // Returns a const reverse iterator pointing to the first element in the Red-Black Tree from the end.
    const_reverse_iterator crbegin() const {
        const_iterator it = const_iterator();
        populate_stack_with_rightmost_nodes(root, it.m_stack);
        return const_reverse_iterator(it);
    }

    // Returns a const reverse iterator pointing to the position just before the first element in the Red-Black Tree.
    const_reverse_iterator crend() const {
        return const_reverse_iterator(const_iterator(stack<node*>()));
    }

    // Returns the number of nodes in the Red-Black Tree.
    size_type size() const {
        return m_size;
    }

    node* get_root() {
        return root;
    }
    
private:
    node* root;
    size_type m_size;

    bool ll;
    bool rr;
    bool rl;
    bool lr;

    // Recursively destroys the binary tree rooted at the given node.
    void destroy_tree(node* root) {
        if (root != nullptr) {
            destroy_tree(root->left);
            destroy_tree(root->right);
            delete root;
        }
    }

    // Perform a left rotation on the given root node.
    node* left_rotate(node* root) {
        // Store references to nodes involved in the rotation
        node* right_child = root -> right;
        node* left_grandchild = right_child -> left;
        node* parent = root -> parent;

        // Update parent's child pointer to point to the right child
        if (parent != nullptr) {
            if (root -> is_on_left())
                parent -> left = right_child;
            else
                parent -> right = right_child;
        } else {
            // If root is the root of the tree, update tree's root
            this -> root = right_child;
        }
        
        // Perform rotation
        right_child -> left = root;
        root -> parent = right_child;

        // Attach left grandchild to root
        root -> right = left_grandchild;
        if (left_grandchild != nullptr)
            left_grandchild -> parent = root;

        // Update parent of right child
        right_child -> parent = parent;

        return right_child; // Return the new root of the subtree
    }

    // Perform a right rotation on the given root node.
    node* right_rotate(node* root) {
        // Store references to nodes involved in the rotation
        node* left_child = root->left;
        node* right_grandchild = left_child->right;
        node* parent = root->parent;

        // Update parent's child pointer to point to the left child
        if (parent != nullptr) {
            if (root->is_on_left())
                parent->left = left_child;
            else
                parent->right = left_child;
        } else {
            // If root is the root of the tree, update tree's root
            this->root = left_child;
        }

        // Perform rotation
        left_child->right = root;
        root->parent = left_child;
        left_child->parent = parent;

        // Attach right grandchild to root
        root->left = right_grandchild;
        if (right_grandchild != nullptr)
            right_grandchild->parent = root;
        
        return left_child; // Return the new root of the subtree
    }

    // Fixes red-red conflict at the given root node using appropriate rotations and color adjustments.
    node* fix_red_red_conflict(node* root) {
        if (ll) {
            root = left_rotate(root);
            root -> color = 'B';
            root -> left -> color = 'R';
            ll = false;
        } else if (rr) {
            root = right_rotate(root);
            root -> color = 'B';
            root -> right -> color = 'R';
            rr = false;
        } else if(rl) {
            root -> right = right_rotate(root -> right);
            root -> right -> parent = root;
            root = left_rotate(root);
            root -> color = 'B';
            root -> left -> color = 'R';
            rl = false;
        } else if (lr) {
            root -> left = left_rotate(root -> left);
            root -> left -> parent = root;
            root = right_rotate(root);
            root -> color = 'B';
            root -> right -> color = 'R';
            lr = false;
        }
        return root;
    }

    // Fixes double black violation at the given node by performing rotations and color adjustments.
    void fix_double_black(node* double_black_node) {
        if (double_black_node == this -> root)
            return;
        node* parent = double_black_node -> parent;
        node* sibling = double_black_node -> sibling();
        if (sibling == nullptr) {
            fix_double_black(parent);
        } else {
            if (sibling -> color == 'R') {
                // Sibling red
                parent -> color = 'R';
                sibling -> color = 'B';
                if (sibling -> is_on_left()) {
                    // left case
                    right_rotate(parent);
                } else {
                    // right case
                    left_rotate(parent);
                }
                fix_double_black(double_black_node);
            } else {
                // Sibling black
                if (sibling -> has_red_child()) {
                    // at least 1 red children
                    if (sibling -> left != nullptr && sibling -> left -> color == 'R') {
                        if (sibling -> is_on_left()) {
                            // left left
                            sibling -> left -> color = 'B';
                            sibling -> color = parent -> color;
                            right_rotate(parent);
                        } else {
                            // right left
                            sibling -> left -> color = parent -> color;
                            right_rotate(sibling);
                            left_rotate(parent);
                        }
                    } else {
                        if (sibling -> is_on_left()) {
                            // left right
                            sibling -> right -> color = parent -> color;
                            left_rotate(sibling);
                            right_rotate(parent);
                        } else {
                            // right right
                            sibling -> right -> color = 'B';
                            sibling -> color = parent -> color;
                            left_rotate(parent);
                        }
                    }
                    parent -> color = 'B';
                } else {
                    // 2 black children
                    sibling -> color = 'R';
                    if (parent -> color == 'B')
                        fix_double_black(parent);
                    else
                        parent -> color = 'B';
                }
            }
        }
    }

    // Recursively searches for a node containing the given data in the subtree rooted at the provided node.
    node* search_node(node* root, const_reference data) const {
        if (root == nullptr)
            return nullptr;
        if (root -> data == data)
            return root;
        else if (data < root -> data)
            return search_node(root -> left, data);
        else 
            return search_node(root -> right, data);
    }

    // Recursively inserts a node containing the given data into the subtree rooted at the provided node, and fixes any potential red-red conflicts.
    node* insert_help(node* root, const_reference data) {
        bool flag = false; // flag to check RED-RED conflict
        if (root == nullptr) {
            m_size++;
            return new node(data);
        } else if (data < root -> data) {
            root -> left = insert_help(root -> left, data);
            root -> left -> parent = root;
            if (root != this -> root && root -> color == 'R' && root -> left -> color == 'R')
                flag = true;
        } else if (data > root -> data) {
            root -> right = insert_help(root -> right, data);
            root -> right -> parent = root;
            if (root != this -> root && root -> color == 'R' && root -> right -> color == 'R')
                flag = true;
        } else {
            return root;
        }

        root = fix_red_red_conflict(root);

        if (flag == true) {
            if (root -> is_on_left()) {
                if (root -> parent -> right == nullptr || root -> parent -> right -> color == 'B') {
                    if (root -> left != nullptr && root -> left -> color == 'R')
                        rr = true;
                    else if (root -> right != nullptr && root -> right -> color == 'R')
                        lr = true;
                } else {
                    root -> parent -> right -> color = 'B';
                    root -> color = 'B';
                    if (root -> parent != this->root)
                        root -> parent -> color = 'R';
                }
            } else {
                if (root -> parent -> left == nullptr || root -> parent -> left -> color == 'B') {
                    if (root -> left != nullptr && root -> left -> color == 'R')
                        rl = true;
                    else if (root -> right != nullptr && root -> right -> color == 'R')
                        ll = true;
                } else {
                    root -> parent -> left -> color = 'B';
                    root -> color = 'B';
                    if (root -> parent != this->root)
                        root -> parent -> color = 'R';
                }
            }
        }
        return root;
    }

    // Deletes the given node from the tree and fixes any double black violations.
    void delete_help(node* root) {
        if (root -> color == 'B') 
            fix_double_black(root);
        if (root == this -> root) {
            this -> root = nullptr;
        } else {
            if (root -> is_on_left())
                root -> parent -> left = nullptr;
            else 
                root -> parent -> right = nullptr;
        }
        m_size--;
        delete root;
    }

    // Finds and returns a deletable node containing the given data in the subtree rooted at the provided node.
    node* find_deletable_node(node* root, const_reference data) {
        node* node_To_delete = search_node(root, data);
        if (node_To_delete == nullptr)
            return nullptr;
        if (node_To_delete -> is_leaf()) 
            return node_To_delete;
        else {
            if (node_To_delete -> right != nullptr) {
                node* successor = node_To_delete -> in_order_successor();
                node_To_delete -> data = move(successor -> data);
                if (successor -> is_leaf())
                    return successor;
                else
                    return find_deletable_node(successor, data);
            } else {
                node* predecessor = node_To_delete -> in_order_predecessor();
                node_To_delete -> data = move(predecessor -> data);
                if (predecessor -> is_leaf())
                    return predecessor;
                else
                    return find_deletable_node(predecessor, data);
            }
        }
    }

    void populate_stack_with_leftmost_nodes(node* root, stack<node*>& current_stack) const {
        if (root == nullptr) {
            return;
        }
        node* temp = root;
        current_stack.push(root);
        while (temp -> left != nullptr) {
            temp = temp -> left;
            current_stack.push(temp);
        }
    }

    void populate_stack_with_rightmost_nodes(node* root, stack<node*>& current_stack) const {
        if (root == nullptr) {
            return;
        }
        node* temp = root;
        current_stack.push(root);
        while (temp -> right != nullptr) {
            temp = temp -> right;
            current_stack.push(temp);
        }
    }
};
} // namespace my_stl
