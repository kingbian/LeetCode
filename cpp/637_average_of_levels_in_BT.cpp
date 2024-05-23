#include <iostream>
#include <queue>
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
 * Time Complexity: O(n); n -> number of nodes in the TreeNode
 * Space Complexity: O(n); n-> the number of nodes to store per level
 */

std::vector<double> averageOfLevels(TreeNode *root) {
  std::queue<TreeNode *> queue;
  std::vector<double> result;
  queue.push(root);
  double sum = 0.0f;
  while (!queue.empty()) {

    int size = queue.size();
    sum = 0;
    for (int i = 0; i < size; ++i) {

      TreeNode *node = queue.front();
      queue.pop();
      sum += node->val;
      if (node->left)
        queue.push(node->left);

      if (node->right)
        queue.push(node->right);
    }
    result.push_back(sum / size);
  }

  return result;
}
