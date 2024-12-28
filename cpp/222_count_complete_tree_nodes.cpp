#include <iostream>
using namespace std;
// definition of a tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/* void track(TreeNode* root, int* nodeCount) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        *nodeCount += 1;
        track(root->left, nodeCount);
    }
    if (root->right != nullptr) {
        *nodeCount += 1;
        track(root->right, nodeCount);
    }
    return;
} */

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->right) + countNodes(root->left);
}
