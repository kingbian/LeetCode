#include <iostream>
// Definition for a binary tree node.
#include <ostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**

check the root->val verse the key
if root->val greater traverse the left sub tree root->left
    if root->left == nullptr
    than create the node and insert the val
if not
traverse the right subtree
    if root->right == nullptr
    than create the node and insert the val
*/

/*
 * Iterative approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
TreeNode *insertIntoBST(TreeNode *root, int val) {
  if (root == nullptr)
    return new TreeNode(val);
  TreeNode *temp = root;

  while (root != nullptr) {

    if (root->val < val) {
      if (root->right != nullptr) {
        root = root->right;
      } else {
        root->right = new TreeNode(val);
        break;
      }
    }

    if (root->val > val) {
      if (root->left != nullptr) {
        root = root->left;
      } else {
        root->left = new TreeNode(val);
        break;
      }
    }
  }
  return temp;
}

/*
 * Recursive approach
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
TreeNode *insertRecursive(TreeNode *root, int val) {
  if (root == nullptr)
    return new TreeNode(val);

  TreeNode *node = root;
  if (root->val > val) {
    node->left = insertRecursive(root->left, val);
  } else {
    node->right = insertRecursive(root->right, val);
  }

  return node;
}

void print(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  std::cout << root->val << std::endl;
  print(root->left);
  print(root->right);
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(7);

  TreeNode *res = insertIntoBST(root, 5);
  print(res);
}
