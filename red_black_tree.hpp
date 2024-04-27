#pragma once

#include "node.hpp"

template<typename T>
class red_black_tree {
private:
    node<T>* root;

    bool ll;
    bool rr;
    bool rl;
    bool lr;

    node<T>* left_rotate(node<T>* root) {
        node<T>* right_child = root -> right;
        node<T>* left_child = right_child -> left;
        node<T>* parent = root -> parent;

        if (parent != nullptr) {
            if (root -> is_on_left())
                parent -> left = right_child;
            else
                parent -> right = right_child;
        } else {
            this -> root = right_child;
        }
        
        right_child -> left = root;
        root -> parent = right_child;

        root -> right = left_child;
        if (left_child != nullptr) 
            left_child -> parent = root;

        right_child -> parent = parent;

        return right_child;
    }

    node<T>* right_rotate(node<T>* root) {
        node<T>* left_child = root -> left;
        node<T>* right_child = left_child -> right;
        node<T>* parent = root -> parent;

        if (parent != nullptr) {
            if (root -> is_on_left())
                parent -> left = left_child;
            else
                parent -> right = left_child;
        } else {
            this -> root = right_child;
        }

        left_child -> right = root;
        root -> parent = left_child;
        left_child -> parent = parent;

        root -> left = right_child;
        if (right_child != nullptr) 
            right_child -> parent = root;
        
        return left_child;
    }

    node<T>* fix_red_red_conflict(node<T>* root) {
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

    node<T>* insert_help(node<T>* root, const T& data) {
        bool flag = false; // flag to check RED-RED conflict
        if (root == nullptr) {
            return new node<T>(data);
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
            if (root -> parent -> right == root) {
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
            } else {
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
            }
        }
        return root;
    }

    node<T>* _search_node(node<T>* root, const T& data) {
        if (root == nullptr)
            return nullptr;
        if (root -> data == data)
            return root;
        else if (data < root -> data)
            return _search_node(root -> left, data);
        else 
            return _search_node(root -> right, data);
    }

    void _delete_node(node<T>* root, const T& data) {
        node<T>* node_To_delete = _search_node(root, data);
        if (node_To_delete == nullptr)
            return;
        if (node_To_delete -> is_leaf()) 
            remove_node(node_To_delete);
        else {
            if (node_To_delete -> right != nullptr) {
                node<T>* successor = node_To_delete -> successor();
                node_To_delete -> data = successor -> data;
                if (successor -> is_leaf())
                    remove_node(successor);
                else
                    _delete_node(successor, data);
            } else {
                node<T>* predecessor = node_To_delete -> predecessor();
                node_To_delete -> data = predecessor -> data;
                if (predecessor -> is_leaf())
                    remove_node(predecessor);
                else
                    _delete_node(predecessor, data);
            }
        }
    }

    void fix_double_black(node<T>* double_black_node) {
        if (double_black_node == this -> root)
            return;
        node<T>* parent = double_black_node -> parent;
        node<T>* sibling = double_black_node -> sibling();
        if (sibling == nullptr) {
            // No sibling, double black pushed up
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

    void remove_node(node<T>* root) {
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
        root -> parent = nullptr;
        delete root;
    }

public:
    red_black_tree() : root(nullptr), ll(false), rr(false), rl(false), lr(false) {}

    ~red_black_tree() {
        destroy_tree(root);
    }

    void destroy_tree(node<T>* root) {
        if (root != nullptr) {
            destroy_tree(root->left);
            destroy_tree(root->right);
            delete root;
        }
    }
    
    void insert_node(const T& data) {
        if (root == nullptr) {
            root = new node<T>(data);
            root -> color = 'B';
        } else {
            root = insert_help(root, data);
        }
    }

    void delete_node(const T& data) {
        _delete_node(root, data);
    }

    T search_node(const T& data) {
        node<T>* result = _search_node(root, data);
        if (result == nullptr)
            return T();
        else 
            return result -> data;
    }

    const node<T>* get_root() {
        return root;
    }
};
