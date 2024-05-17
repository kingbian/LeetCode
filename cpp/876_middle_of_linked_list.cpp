/* Definition for singly-linked list.
 * The number of nodes in the list is in the range [1, 100].
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 *
 * Time Complexity: O(n); n -> the number of nodes in the list
 * Space Complexity: O(1);
 *
 *
    ListNode *middleNode(ListNode *head) {
      int i = 0;
      int length = 0;
      ListNode *temp = head;
      ListNode *middleNode = nullptr;
      while (temp != nullptr) {
        length++;
        temp = temp->next;
      }

      while (i <= length / 2) {
        middleNode = head;
        head = head->next;
        i++;
      }

      return middleNode;
    }
*/

ListNode *middleNodePointers(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
    if (fast->next == nullptr)
      return slow;

    fast = fast->next;
  }
  return slow;
}
