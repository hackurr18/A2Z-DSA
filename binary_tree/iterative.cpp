#include<iostream>
using namespace std;
//tc O(N)
struct Treenode{
    int data;
    Treenode *left;
    Treenode *right;

    Treenode(int val){
        data=val;
        left=right= nullptr ;
    }
};
//preporder root left right
vector<int>preoderTraversal(Treenode *root){
    vector<int>pre;
    if(root == nullptr) return pre;

    stack<Treenode*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        pre.push_back(root -> data);
        if(root ->right != nullptr) st.push(root ->right);
        if(root ->left != nullptr) st.push(root ->left);
    }
    return pre;
}
int main(){
    struct Treenode *root = new Treenode(1);
    root->left = new Treenode(2);
    root->right = new Treenode(7);
    root->left->left = new Treenode(3);
    root->left->right = new Treenode(4);
    root->left->right->left = new Treenode(5);
    root->left->right->right = new Treenode(6);

    cout << "Pre-order Traversal: ";
    vector<int>ans=preoderTraversal(root); 
    for(auto i:ans){
        cout<<i<< " ";
    }
    return 0;          
}