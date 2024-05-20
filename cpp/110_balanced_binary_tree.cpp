// Definition for a binary tree node.
#include <algorithm>
#include <cstdlib>
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
 * Time Complexity: O(n) visit every node
 * Space Complexity: O(h); h -> height of the binary tree due to the recursion
 * stack
 */
int helper(TreeNode *node) {
  if (node == nullptr)
    return 0;
  // int left = 0, right = 0;
  int left = helper(node->left);

  if (left == -1)
    return -1;
  int right = helper(node->right);

  if (right == -1)
    return -1;

  int balancefactor = std::abs(left - right);

  if (balancefactor > 1)
    return -1;

  return 1 + std::max(left, right);
}

bool isBalanced(TreeNode *root) {
  int res = helper(root);
  return (res == -1) ? false : true;
}
