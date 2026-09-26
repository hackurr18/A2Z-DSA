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
void pre_order(node *root) {    
    if (root == nullptr) return;

    cout << root->data << " "; 
    pre_order(root->left);
    pre_order(root->right);
}
//in order traversal : left root right
void in_order(node *root){
    if(root == nullptr) return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}
// post order traversal : left right root
void post_order(node *root){
    if(root == nullptr) return;
    post_order(root->left);
    post_order(root ->right);
    cout<< root->data <<" ";
}
int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    cout << "Pre-order Traversal: ";
    pre_order(root);           
    cout << endl;
    cout << "in-order Traversal: ";
    in_order(root);
    cout<<endl;
    cout << "pst order Traversal: ";
    post_order(root);
    cout<<endl;
    return 0;
}