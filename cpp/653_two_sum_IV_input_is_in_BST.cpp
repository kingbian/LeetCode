#include <unordered_set>
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
 * Run Time: 15ms
 *
 */

/*
 * This helper function recursively iterates over the Tree Node
 * adding it the vector


void bstToVectorInorder(TreeNode *root, std::vector<int> &nums) {
  // check for the base case
  if (root == nullptr)
    return;

  // traverse the left sub tree
  bstToVectorInorder(root->left, nums);

  // add the current node to the vector
  nums.push_back(root->val);

  // traverse the right sub tree
  bstToVectorInorder(root->right, nums);

  return;
}
*/
/*
 * This function uses a two pointer approach to find
 * 2 numbers that add up to the key

bool findTarget(TreeNode *root, int k) {

  std::vector<int> nums;
  bstToVectorInorder(root, nums);

  // create the two pointers
  int start = 0, end = nums.size() - 1;

  // iterate through until the pointers meet each other
  while (start < end) {
    int sum = nums[start] + nums[end];

    if (sum == k)
      return true; // found the 2 int's that make the key

    // move the pointers
    if (sum > k)
      end--;
    if (sum < k)
      start++;
  }
  return false;
}
 */

/*
 * implementing using unordered_set
 *
 * Time Complexity: O(n); n -> the number of nodes in the tree
 * Space Complexity: O(n); n-> the size of vector
 */

bool getTarget(TreeNode *node, std::unordered_set<int> &set, int key) {
  if (node == nullptr)
    return false;

  if (set.count(key - node->val))
    return true;

  set.insert(node->val);

  return getTarget(node->left, set, key) || getTarget(node->right, set, key);
}

bool findTarget(TreeNode *root, int k) {

  std::unordered_set<int> set;

  return getTarget(root, set, k);
}
