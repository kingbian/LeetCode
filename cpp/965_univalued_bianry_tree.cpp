#include <iostream>
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
 * Time Complexity: O(n); n number of nodes in the tree
 * Space Complexity: O(n) n -> number nodes currently stored in the queue
 */

bool isUnivalTree(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);

    int rootVal = root->val;
    while (!queue.empty()) {
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = queue.front();
            queue.pop();

            if (node->val != rootVal)
                return false;

            if (node->left)
                queue.push(node->left);

            if (node->right)
                queue.push(node->right);
        }
    }

    return true;
}

/*
 * Time Complexity: O(n); n-> number of nodes in the tree
 * Space Complexity: O(h) h -> height of the binary tree
 */
bool preOrder(TreeNode *node, int val) {
    if (node == nullptr)
        return true;

    if (node->val != val)
        return false;

    return preOrder(node->left, val) && preOrder(node->right, val);
}

bool isUnivalTree(TreeNode *root) {
    if (root == nullptr)
        return true;

    return preOrder(root, root->val);
}
