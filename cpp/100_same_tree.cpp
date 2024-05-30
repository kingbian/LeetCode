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
 * Time Complexity: O(n); due to the traversal of the Tree
 * Space Complexity: O(h) due to the recursion stack, worst case is the height of the tree
 */
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
        return true;
    else if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr))
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
