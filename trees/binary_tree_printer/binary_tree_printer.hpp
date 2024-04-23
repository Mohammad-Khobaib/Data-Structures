#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*
Printer Utility to print a binary tree like a tree.

Can print a binary tree whose root node has at least the following properties.

node -> left    # left child
node -> right   # right child
node -> data     # value of the node
*/

// Class to hold data required for printing a node in the tree
class NodePrintData {
public:
    std::vector<std::string> lines;    // Lines representing the node and its subtree
    unsigned int root_position;         // Position of the root node in the line
    unsigned int root_len;              // Length of the root node's value
    unsigned int max_width;             // Maximum width of the subtree
    unsigned int height;                // Height of the subtree

    // Constructor to initialize NodePrintData object
    NodePrintData(const std::vector<std::string>& lines, unsigned int root_position, unsigned int root_len)
        : lines(lines), root_position(root_position), root_len(root_len) {
        // Calculate maximum width and height of the subtree
        max_width = 0;
        for (const auto& it : lines) {
            max_width = std::max(max_width, it.size());
        }
        height = lines.size();
    }
};

// Template class for printing binary trees
template<typename node>
class binary_tree_printer {
private:
    char branch_line;           // Character to represent branches
    char left_node_line;        // Character to represent left node connection
    char right_node_line;       // Character to represent right node connection
    unsigned int extra_padding; // Extra padding for better visualization

public:
    // Constructor to initialize default values
    binary_tree_printer() : branch_line('.'), left_node_line('/'), right_node_line('\\'), extra_padding(1) {}

    // Method to generate tree data for printing
    NodePrintData treeify(node* root) {
        // If the root is null, return empty data
        if (root == nullptr)
            return NodePrintData({""}, 0, 0);

        // Convert root value to string
        std::string val = std::to_string(root->data);
        // Recursively generate data for left and right subtrees
        NodePrintData left_node_data = treeify(root->left);
        NodePrintData right_node_data = treeify(root->right);

        // Initialize vector to hold lines representing the current node
        std::vector<std::string> lines;
        std::string first_line = "";
        std::string second_line = "";

        unsigned int len_before_val = 0;

        // If left subtree exists, generate lines for left connection
        if (left_node_data.max_width > 0) {
            unsigned int left_root_end = left_node_data.root_len + left_node_data.root_position;
            unsigned int branch_len = left_node_data.max_width - left_root_end;
            first_line.append(std::string(left_root_end + 1, ' '));
            first_line.append(std::string(branch_len + extra_padding, branch_line));
            len_before_val = first_line.size();
            second_line.append(std::string(left_root_end, ' '));
            second_line.push_back(left_node_line);
            unsigned int second_line_size = second_line.size();
            second_line.append(std::string(len_before_val - second_line_size, ' '));
        }

        // Append root value to the first line
        first_line.append(val);

        // Generate padding for right subtree
        std::string left_padding = "";

        // If right subtree exists, generate padding and lines for right connection
        if (right_node_data.max_width > 0) {
            left_padding = std::string(val.size() + 1 + extra_padding, ' ');
        }

        // If right subtree exists, generate lines for right connection
        if (right_node_data.max_width > 0) {
            first_line.append(std::string(right_node_data.root_position + extra_padding, branch_line));
            second_line.append(std::string(right_node_data.root_position + val.size() + extra_padding, ' '));
            second_line.push_back(right_node_line);
        }

        // Add first and second lines representing current node to lines vector
        lines.push_back(first_line);
        lines.push_back(second_line);

        // Merge lines from left and right subtrees
        for (int i = 0; i < std::max(left_node_data.height, right_node_data.height); i++) {
            std::string left_line;
            std::string right_line;
            // Get lines for left and right subtrees
            if (i < left_node_data.height && i < right_node_data.height) {
                left_line = left_node_data.lines[i];
                right_line = right_node_data.lines[i];
            } else if (i < left_node_data.height) {
                left_line = left_node_data.lines[i];
                right_line = "";
            } else {
                right_line = right_node_data.lines[i];
                left_line = "";
            }
            std::string line;
            // Merge lines with appropriate padding
            line.append(left_line);
            line.append(std::string(len_before_val - left_line.size(), ' '));
            line.append(left_padding);
            line.append(right_line);
            line.append(std::string(right_node_data.max_width, ' '));
            // Add merged line to lines vector
            lines.push_back(line);
        }
        // Return NodePrintData object containing generated lines and data
        return NodePrintData(lines, len_before_val, val.size());
    }

    // Method to print the tree to the console
    void print_tree(node* root) {
        // Generate tree data
        NodePrintData node_data = treeify(root);
        // Print each line of the tree
        for (const auto& it : node_data.lines) {
            std::cout << it << std::endl;
        }
    }

    // Method to get the tree representation as a vector of strings
    std::vector<std::string> get_tree_string(node* root) {
        // Generate tree data and return lines
        return treeify(root).lines;
    }
};
