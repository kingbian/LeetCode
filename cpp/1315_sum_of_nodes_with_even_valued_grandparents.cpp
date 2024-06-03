struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
void helper(TreeNode *node, TreeNode *parent, TreeNode *grandparent, int &sum) {
    if (node == nullptr)
        return;

    // If the grandparent exists and its value is even, add the current node's value to sum
    if (grandparent != nullptr && grandparent->val % 2 == 0) {
        sum += node->val;
    }

    // Traverse to the left and right children
    helper(node->left, node, parent, sum);
    helper(node->right, node, parent, sum);
}

int sumEvenGrandparent(TreeNode *root) {
    int sum = 0;
    helper(root, nullptr, nullptr, sum);
    return sum;
}
