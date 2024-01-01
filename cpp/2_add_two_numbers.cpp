#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;                  // ptr to the next node
    ListNode();                      // val =0 , next = nullptr
    ListNode(int x);                 // val = x, next = nullptr
    ListNode(int x, ListNode *next); // val = x. next = next node;
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    int carry = 0; // if the sum is > 10
    ListNode *ans = new ListNode(0);

    ListNode *current = ans;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int val1, val2, sum;
        val1 = val2 = sum = 0;

        if (l1->next != nullptr)
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2->next != nullptr)
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = val1 + val2 + carry;

        ans->next = new ListNode(sum % 10);

        carry = sum / 10;
    }

    return ans;
}

int main()
{

    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    std::string node1;
    std::cin >> node1;

    // std::string node2;
    // std::cin >> node2;

    std::cout << "Node 1 data: " << node1 << "\n";
    // std::cout << "Node 2 data: " << node2 << "\n";

    for (int i = 0; i < node1.size(); ++i)
    {

        int val = node1[i] - '0';

        if (l1->next == nullptr)
        {

            l1 = new ListNode(val);
        }
        else
        {
            l1->next = new ListNode(val);
            l1 = l1->next;
        }
    }
}