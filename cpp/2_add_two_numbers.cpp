#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;                  // ptr to the next node
    ListNode();                      // val =0 , next = nullptr
    ListNode(int x);                 // val = x, next = nullptr
    ListNode(int x, ListNode *next); // val = x. next = next node;
};

/**
 * Run time 61ms very slow needs to be updated
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    int carry = 0; // if the sum is > 10
    ListNode *ans = new ListNode();

    ListNode *current = ans;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int val1, val2, sum;
        val1 = val2 = sum = 0;

        if (l1->next != NULL)
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2->next != NULL)
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = val1 + val2 + carry;

        ListNode *tempNode = new ListNode(sum % 10);

        current->next = tempNode;
        current = current->next;
        carry = sum / 10;
    }

    return ans->next;
}
