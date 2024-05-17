#include <iostream>
#include <vector>

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
 * Time Complexity: O(n); n -> is the size of the array
 * Space Complexity: O(log n) because array elements are ordered
 */
TreeNode *insertNode(std::vector<int> &nums, int left, int right) {

  if (left > right)
    return nullptr;

  int mid = left + (right - left) / 2;
  TreeNode *node = new TreeNode(nums[mid]);
  node->left = insertNode(nums, left, mid - 1);
  node->right = insertNode(nums, mid + 1, right);

  return node;
}

void printInorder(TreeNode *node) {

  if (node == nullptr) {
    std::cout << "null\n";
    return;
  }

  std::cout << node->val << "\n";
  printInorder(node->left);
  printInorder(node->right);
}

TreeNode *sortedArrayToBST(std::vector<int> &nums) {
  TreeNode *res = nullptr;

  res = insertNode(nums, 0, nums.size() - 1);

  printInorder(res);
  return res;
}

int main() {

  std::vector<int> nums{-10, -3, 0, 5, 9};

  TreeNode *ans = sortedArrayToBST(nums);

  return 0;
}
