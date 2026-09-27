#include <iostream>
#include<queue>
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
//level order traversal BFS
vector<vector<int>>levelOrder(node *root){
    vector<vector<int>>ans;
    if(root==nullptr) return ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* current = q.front();
            q.pop();

            if(current->left != nullptr)
                q.push(current->left);

            if(current->right != nullptr)
                q.push(current->right);

            level.push_back(current->data);
        }
        ans.push_back(level);
    }
    return ans;

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
    cout << "post order Traversal: ";
    post_order(root);
    cout<<endl;
    cout << "level order Traversal: ";
    vector<vector<int>>ans=levelOrder(root);
    cout<<endl;
    for(const auto &i:ans){
        for(auto x:i){
            cout<<x<<' ';
        }
    }
    return 0;
}