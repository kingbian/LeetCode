// definition for a binary Tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *helper(TreeNode *node1, TreeNode *node2) {

  if (node1 == nullptr && node1 == nullptr)
    return nullptr;

  TreeNode *newNode;

  helper(node1->left, node2->left);
  int val1, val2;
  val1 = val2 = 0;
  if (node1 != nullptr)
    val1 = node1->val;

  if (node2 != nullptr)
    val1 = node2->val;

  newNode->left = new TreeNode(val1 + val2);

  // get all the right sub trees
  helper(node1->right, node2->right);

  return newNode;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  if (root1 == nullptr)
    return root2;
  if (root2 == nullptr)
    return root1;

  int val1, val2;
  val1 = val2 = 0;
  if (root1 != nullptr)
    val1 = root1->val;

  if (root2 != nullptr)
    val2 = root2->val;

  TreeNode *newNode = new TreeNode(val1 + val2);

  if (root1 == nullptr) {
    newNode->left = mergeTrees(nullptr, root2->left);
  } else if (root2 == nullptr) {
    newNode->left = mergeTrees(root1->left, nullptr);

  } else {
    newNode->left = mergeTrees(root1->left, root2->left);
  }

  // get all the right sub trees
  if (root1 == nullptr) {
    newNode->right = mergeTrees(nullptr, root2->right);
  } else if (root2 == nullptr) {
    newNode->right = mergeTrees(root1->right, nullptr);

  } else {
    newNode->right = mergeTrees(root1->right, root2->right);
  }

  return newNode;
}
