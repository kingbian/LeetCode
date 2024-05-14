#include <iostream>
#include <stack>

/*
 * Constraints: input size is at 2*10^4
 */

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
 * Recursive apporach
 * Time Complexity: O(n); N-> number of nodes
 * Space Complexity: O(H); H-> height of the tree
 *
 */
int rangeSumBST(TreeNode *root, int low, int high) {
  // check base case
  if (root == NULL)
    return 0;

  if (root->val < low)
    return rangeSumBST(root->right, low, high);

  else if (root->val > high)
    return rangeSumBST(root->left, low, high);

  return root->val + rangeSumBST(root->left, low, high) +
         rangeSumBST(root->right, low, high);
}

/*
 * Iterative apporach
 * Time Complexity: O(n); N-> number of nodes
 * Space Complexity: O(H); H-> height of the tree
 */

int fastRangeSumBST(TreeNode *root, int low, int high) {

  std::stack<TreeNode *> stack;
  stack.push(root);
  int sum = 0;

  while (!stack.empty()) {
    TreeNode *node = stack.top();
    stack.pop();

    std::cout << "node val: " << node->val << "\n";
    if (node->val >= low && node->val <= high) {
      sum += node->val;
    }
    if (node->left && node->val >= low) {
      stack.push(node->left);
    }

    if (node->right && node->val <= high) {
      stack.push(node->right);
    }
  }

  return sum;
}
