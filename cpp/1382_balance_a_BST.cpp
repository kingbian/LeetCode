// Definition for a binary tree node.
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
 * Time Complexity: O(n); n -> traversal of the entire tree
 * Space Complexity: O(n); size of the sorted vector
 *
 * Intuition:
 * since we are given a binary search Tree, we know that if we traverse it
 * in-order we will have a sorted output which we can save into a vector
 *
 * we will use 2 pointers, low and high to calculate the mid-point, which helps
 * in determining the root node and the boundaries of the left and right
 * subtrees
 *
 *
 * using the sorted vector, we can recursively populate the new balanced tree by
 * first calculating the mid of the vector, which will be our root node since
 * mid point of the vector holds the root value. Using the mid point we can get
 * the left and right sub trees using the low and high pointers
 */

void binaryTreeTOVectorInorder(TreeNode *node, std::vector<int> &nums) {

  if (node == nullptr)
    return;

  // traverse the whole left subtree
  binaryTreeTOVectorInorder(node->left, nums);
  nums.push_back(node->val);

  // traverse the whole right subtree
  binaryTreeTOVectorInorder(node->right, nums);
}

TreeNode *populateTree(const std::vector<int> &nums, int low, int high) {

  if (low > high)
    return nullptr;

  int mid = low + (high - low) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = populateTree(nums, low, mid - 1);

  root->right = populateTree(nums, mid + 1, high);

  return root;
}

/*
 *  convert binary tree to a vector
 *  use the binary search algorithm  to recursively populate the new binary
 * tree
 *
 */
TreeNode *balanceBST(TreeNode *root) {
  std::vector<int> nums;
  TreeNode *result = nullptr;

  binaryTreeTOVectorInorder(root, nums);

  result = populateTree(nums, 0, nums.size() - 1);

  return result;
}
