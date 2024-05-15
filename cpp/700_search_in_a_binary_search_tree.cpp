//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode()
      : val(0), left(nullptr), right(nullptr){} * TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x),
        left(left), right(right) {}
};

/*
 * Recursive approach
 * Time Complexity: O(n); n -> number of  nodes
 * Space Complexity: O(H); H-> height of the tree due to the call stack
 * RunTime: 34ms beats 29% of c++
 */
TreeNode *searchBST(TreeNode *root, int val) {

  if (root == nullptr || root->val == val)
    return root;

  if (root->val > val) {
    return searchBST(root->left, val);
  }

  return searchBST(root->right, val);
}

/*
 * Iterative approach
 * Time Complexity: O(n); n -> height of tree
 * Space Complexity: O(1)
 * RunTime: 27ms beats 78.73% of c++
 */
TreeNode *iterativeSearchBST(TreeNode *root, int val) {

  while (root != nullptr && root->val != val)
    root = (root->val > val) ? root->left : root->right;
  return root;
}
