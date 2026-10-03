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
private:
    // Checks whether a node
    // has no children.
    bool isLeaf(TreeNode* node) {
        return node != nullptr
            && node->left == nullptr
            && node->right == nullptr;
    }

    // Adds non-leaf nodes from the
    // left boundary in top-down order.
    void addLeftBoundary(
        TreeNode* root,
        vector<int>& boundary
    ) {
        TreeNode* current = root->left;

        // The outermost available child
        // continues the left boundary.
        while (current != nullptr) {
            // Leaves are collected separately,
            // so they are skipped here.
            if (!isLeaf(current)) {
                boundary.push_back(current->val);
            }

            if (current->left != nullptr) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    // Collects all leaf nodes
    // from left to right.
    void addLeaves(
        TreeNode* node,
        vector<int>& boundary
    ) {
        if (node == nullptr) {
            return;
        }

        // A leaf belongs directly
        // to the leaf section.
        if (isLeaf(node)) {
            boundary.push_back(node->val);
            return;
        }

        addLeaves(node->left, boundary);
        addLeaves(node->right, boundary);
    }

    // Adds the right boundary
    // in required bottom-up order.
    void addRightBoundary(
        TreeNode* root,
        vector<int>& boundary
    ) {
        TreeNode* current = root->right;
        vector<int> rightBoundary;

        // rightBoundary stores nodes top-down.
        // They are reversed for bottom-up order.
        while (current != nullptr) {
            // Leaves are collected separately,
            // so they are skipped here.
            if (!isLeaf(current)) {
                rightBoundary.push_back(current->val);
            }

            if (current->right != nullptr) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        // Reverse traversal places the
        // right boundary from bottom to top.
        for (
            int i = rightBoundary.size() - 1;
            i >= 0;
            i--
        ) {
            boundary.push_back(rightBoundary[i]);
        }
    }

public:
    // Returns the anti-clockwise
    // boundary traversal of the tree.
    vector<int> boundaryTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> boundary;

        // A non-leaf root is added here.
        // A single-node root is added as a leaf.
        if (!isLeaf(root)) {
            boundary.push_back(root->val);
        }

        addLeftBoundary(root, boundary);
        addLeaves(root, boundary);
        addRightBoundary(root, boundary);

        return boundary;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    vector<int> answer =
        solution.boundaryTraversal(root);

    for (int value : answer) {
        cout << value << " ";
    }

    return 0;
}