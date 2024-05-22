#include <ios>
#include <iostream>
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

/*
 * Time Complexity: O(n); n-> the number of visited nodes
 * Space Complexity: O(n); n-> the max number of nodes stored in the queue at
 * each level
 *
 */

int deepestLeavesSum(TreeNode *root) {

  std::queue<TreeNode *> queue;
  queue.push(root);

  int sum = 0;

  while (!queue.empty()) {

    sum = 0;
    int size = queue.size();
    for (int i = 0; i < size; ++i) {
      TreeNode *node = queue.front();
      queue.pop();

      sum += node->val;
      if (node->left)
        queue.push(node->left);

      if (node->right)
        queue.push(node->right);
    }
  }

  return sum;
}

int main() {
  // Creating a BST:
  //       5
  //      / \
  //     3   6
  //    / \   \
  //   2   4   7
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(18);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(4);
  root->right->right->right = new TreeNode(18);
  root->right->right->right->right = new TreeNode(18);
  //
  std::cout << std::boolalpha;
  int k = 20;
  std::cout << "is the tree balanced: " << true << std::endl;
  return 0;
}
