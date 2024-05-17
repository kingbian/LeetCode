#include <iostream>
#include <vector>
// Definition for a binary tree node.
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
 * Time Complexity: O(n); n -> the number of nodes in the tree
 * Space Complexity: O(n); n-> the size of vector
 * RunTime: 15ms
 *
 */
void bstToVector(TreeNode *root, std::vector<int> &nums) {
  if (root == nullptr)
    return;

  bstToVector(root->left, nums);

  nums.push_back(root->val);
  bstToVector(root->right, nums);

  return;
}

bool findTarget(TreeNode *root, int k) {

  std::vector<int> nums;
  bstToVector(root, nums);
  int left = 0, right = nums.size() - 1;

  while (left < right) {

    if (nums[left] + nums[right] == k)
      return true;

    if (nums[left] + nums[right] > k) {
      right--;
    } else
      left++;
  }

  return false;
}

int main() {
  // Creating a BST:
  //       5
  //      / \
  //     3   6
  //    / \   \
  //   2   4   7
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  int k = 20;

  bool result = findTarget(root, k);
  std::cout << (result ? "True" : "False") << std::endl;

  return 0;
}
