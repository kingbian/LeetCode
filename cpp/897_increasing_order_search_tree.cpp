#include <iostream>
// Definition for a binary tree node.

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *dummy = nullptr;

void inOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  cout << "The val is: " << root->val << " \n";
  // go through left subtree
  inOrder(root->left);
  // make left node nullptr
  root->left = nullptr;
  dummy->right = root;
  dummy = root;

  inOrder(root->right);
}

TreeNode *increasingBST(TreeNode *root) {

  TreeNode *current = dummy;
  inOrder(root);

  return current->right;
}

int main() {
  dummy = new TreeNode(0);
  TreeNode *tree = new TreeNode(5);
  tree->left = new TreeNode(3);
  tree->left->left = new TreeNode(2);
  tree->left->right = new TreeNode(4);
  tree->left->left->left = new TreeNode(1);

  tree->right = new TreeNode(6);
  tree->right->right = new TreeNode(8);
  tree->right->right->left = new TreeNode(7);
  tree->right->right->right = new TreeNode(9);

  cout << "Calling increasingBST\n";
  TreeNode *result = increasingBST(tree);

  while (result != nullptr) {
    cout << "Val is: " << result->val << " \n";
    result = result->right;
  }

  delete dummy;
  delete tree;

  return 0;
}
