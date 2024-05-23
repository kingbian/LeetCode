#include <iostream>
#include <queue>
#include <utility>
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

TreeNode *reverseOddLevels(TreeNode *root) {

  std::queue<TreeNode *> queue;
  queue.push(root);
  TreeNode *result;
  int level = 0;
  while (!queue.empty()) {
    int size = queue.size();
    std::vector<TreeNode *> temp;

    for (int i = 0; i < size; ++i) {
      TreeNode *node = queue.front();
      queue.pop();

      if (level % 2 == 1)
        temp.push_back(node);
      if (node->left)
        queue.push(node->left);

      if (node->right)
        queue.push(node->right);
    }

    if (!temp.empty()) {
      int left = 0, right = temp.size() - 1;
      while (left < right) {
        std::swap(temp[left]->val, temp[right]->val);

        left++;
        right--;
      }
    }
    level++;
  }
  return result;
}
