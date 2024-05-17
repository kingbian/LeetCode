#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Definition for a binary tree node.
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
 *
 * Naive Implemenation
 * Time Complexity: O(n); n -> number of nodes in the list
 * Space Complexity: (n); n -> size of vector
 * RunTime: 44ms (slow)
 */

TreeNode *insertNode(std::vector<int> &nums, int left, int right) {

  if (left > right)
    return nullptr;

  int mid = left + (right - left) / 2;
  TreeNode *ans = new TreeNode(nums[mid]);
  ans->left = insertNode(nums, left, mid - 1);
  ans->right = insertNode(nums, mid + 1, right);

  return ans;
}

TreeNode *sortedListToBST(ListNode *head) {
  TreeNode *res = nullptr;
  std::vector<int> vector;
  while (head != nullptr) {
    vector.push_back(head->val);
    head = head->next;
  }

  return res = insertNode(vector, 0, vector.size() - 1);
}

/*
 * Time Complexity: O(n); n -> number of nodes in the list
 * Space Complexity: O(1)
 * RunTime: 11ms
 *
 */

TreeNode *insertNode(ListNode *head, ListNode *tail) {
  if (head == tail)
    return nullptr;

  ListNode *slow = head;
  ListNode *fast = head;

  while (fast != tail && fast->next != tail) {
    slow = slow->next;
    fast = fast->next->next;
  }
  // mid point found
  TreeNode *rootNode = new TreeNode(slow->val);

  rootNode->left = insertNode(head, slow);
  rootNode->right = insertNode(slow->next, tail);

  return rootNode;
}
TreeNode *sortedListToBSTFast(ListNode *head) {

  if (head == nullptr)
    return nullptr;
  return insertNode(head, nullptr);
}
