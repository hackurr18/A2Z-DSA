#include <iostream>
using namespace std;

// Create binary tree node structure
struct node {
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = nullptr; // nullptr is preferred in C++
    }
};

// Pre-order traversal: root -> left -> right
void pre_order(node *node) {    
    if (node == nullptr) return;

    cout << node->data << " "; 
    pre_order(node->left);
    pre_order(node->right);
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    cout << "Pre-order Traversal: ";
    pre_order(root);           
    cout << endl;

    return 0;
}