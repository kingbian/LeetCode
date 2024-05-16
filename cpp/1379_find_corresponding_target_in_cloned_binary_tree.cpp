struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * Time Complexity: O(n); n -> the number of nodes
 * space Complexity: O(n);  n -> the height of the tree
 *
 */
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                        TreeNode *target) {
  if (original == nullptr)
    return nullptr;
  if (original == target) {
    return cloned;
  }
  TreeNode *leftNode = getTargetCopy(original->left, cloned->left, target);
  if (leftNode != nullptr)
    return leftNode;

  return getTargetCopy(original->right, cloned->right, target);
}
