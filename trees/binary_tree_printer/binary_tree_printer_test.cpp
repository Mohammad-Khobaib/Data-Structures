#include "binary_tree_printer.hpp"
#include "node.hpp" // Assuming you have defined the node class

// Test method for print_tree
void test_print_tree() {
    // Create a sample binary tree
    node<int>* root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);

    // Create an instance of the binary_tree_printer class
    binary_tree_printer<node<int>> printer;

    // Test the print_tree method
    std::cout << "Printing the tree:" << std::endl;
    printer.print_tree(root);

    // Clean up memory
    // Implement your own logic to delete nodes
    // Here, we assume a simple recursive deletion
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
}

// Test method for get_tree_string
void test_get_tree_string() {
    // Create a sample binary tree
    node<int>* root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);

    // Create an instance of the binary_tree_printer class
    binary_tree_printer<node<int>> printer;

    // Test the get_tree_string method
    std::cout << "\nGetting tree representation as strings:" << std::endl;
    std::vector<std::string> tree_strings = printer.get_tree_string(root);
    for (const auto& str : tree_strings) {
        std::cout << str << std::endl;
    }

    // Clean up memory
    // Implement your own logic to delete nodes
    // Here, we assume a simple recursive deletion
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
}

int main() {
    // Test the print_tree method
    test_print_tree();

    // Test the get_tree_string method
    test_get_tree_string();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
