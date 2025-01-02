struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
/**
 * Time Complexity: O(n); n ---> the number of nodes being visited
 * Space Complexity: O(h); h ---> the hight of the Tree
 */
bool runDFS(TreeNode *left, TreeNode *right) {
    if (!left && !right)
        return true;

    if (!left || !right || left->val != right->val)
        return false;

    return runDFS(left->left, right->right) &&
           runDFS(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root)
        return false;
    return runDFS(root->left, root->right);
}
