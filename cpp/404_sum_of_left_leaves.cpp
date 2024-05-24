#include <queue>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode *root) {

  std::queue<std::pair<TreeNode *, bool>> queue;
  int leftSum = 0;

  queue.push({root, false});
  while (!queue.empty()) {

    auto [node, isLeft] = queue.front();
    queue.pop();

    if (isLeft && node->left == nullptr && node->right == nullptr)
      leftSum += node->val;

    if (node->left)
      queue.push({node->left, true});

    if (node->right)
      queue.push({node->right, false});
  }

  return leftSum;
}
