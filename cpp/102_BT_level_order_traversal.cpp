#include <iostream>
#include <queue>
#include <vector>
//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root) {

  if (root == nullptr)
    return {};
  std::vector<std::vector<int>> result;
  std::queue<TreeNode *> queue;
  queue.push(root);

  while (!queue.empty()) {
    std::vector<int> children;
    int len = queue.size();

    for (int i = 0; i < len; ++i) {
      TreeNode *node = queue.front();
      queue.pop();
      children.push_back(node->val);

      if (node->left != nullptr)
        queue.push(node->left);

      if (node->right != nullptr)
        queue.push(node->right);
    }

    result.push_back(children);
  }
  return result;
}

int main() {

  TreeNode *tree = new TreeNode(3);
  tree->left = new TreeNode(9);

  tree->right = new TreeNode(20);
  tree->right->right = new TreeNode(7);
  tree->right->left = new TreeNode(15);

  for (auto i : levelOrder(tree)) {

    for (auto val : i) {
      std::cout << val << std::endl;
    }
  }
}
