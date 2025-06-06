
// define a singly-linked list

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* lastSorted = head;  // already sorted
    ListNode* currentNode = head->next;

    while (currentNode != nullptr) {
        if (currentNode->val >= lastSorted->val) {
            lastSorted = lastSorted->next;
        } else {
            ListNode* previous = dummy;
            while (previous->next->val < currentNode->val) {
                previous = previous->next;
            }

            // link the nodes together
            lastSorted->next = currentNode->next;
            currentNode->next = previous->next;
            previous->next = currentNode;
        }

        // use the sorted list
        currentNode = lastSorted->next;
    }

    return dummy->next;
}
