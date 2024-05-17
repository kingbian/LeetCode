// Definition for a binary tree node.
#include <climits>
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
 * Time Complexity: O(n); n -> Time to populate vector
 * Space Complexity: O(n); n -> size of vector
 * Run Time: 5ms
 */
void bstToVector(TreeNode *node, std::vector<int> &nums) {

  if (node == nullptr) {
    return;
  }

  if (node->left)
    bstToVector(node->left, nums);
  nums.push_back(node->val);

  if (node->right)
    bstToVector(node->right, nums);
}
int minDiffInBSTSlow(TreeNode *root) {
  std::vector<int> nums;
  bstToVector(root, nums);
  int min = INT_MAX;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] - nums[i - 1] < min)
      min = nums[i] - nums[i - 1];
  }

  return min;
}

/*
 * Optimized to use O(1) extra space
 * Time Complexity: O(n); n -> number of nodes
 * Space Complexity: O(1)
 * Run Time: 0ms
 */
void getMinDiff(TreeNode *node, int &prev, int &minDiff) {
  if (node == nullptr)
    return;

  getMinDiff(node->left, prev, minDiff);

  if (prev != -1) {
    if ((node->val - prev) < minDiff)
      minDiff = node->val - prev;
  }
  prev = node->val;
  getMinDiff(node->right, prev, minDiff);
}

int minDiffInBSTFast(TreeNode *root) {
  int prev = -1, min = INT_MAX;
  getMinDiff(root, prev, min);

  return min;
}
