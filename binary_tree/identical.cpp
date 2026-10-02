#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Compares corresponding nodes
    // of both trees recursively.
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both trees are empty
        // at this position.
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Only one node exists,
        // so the structures differ.
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Different values make
        // the trees non-identical.
        if (p->val != q->val) {
            return false;
        }

        // Both corresponding subtrees
        // must also be identical.
        return isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;

    cout << (
        solution.isSameTree(p, q)
        ? "true"
        : "false"
    ) << endl;

    return 0;
}