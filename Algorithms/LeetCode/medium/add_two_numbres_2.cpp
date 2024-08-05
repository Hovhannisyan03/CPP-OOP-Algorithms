/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 && l2)
        {
            int sum = (l1->val + l2->val + carry) % 10;
            temp->next = new ListNode(sum);
            carry = (l1->val + l2->val + carry) / 10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *temp2 = l1 ? l1 : l2;
        while(temp2)
        {
            int sum = (temp2->val + carry) % 10;
            temp->next = new ListNode(sum);
            carry = (temp2->val + carry) / 10;
            temp = temp->next;
            temp2 = temp2->next;
        }

        if(carry)
        {
            temp->next = new ListNode(1);
        }
        return dummy->next;
    }
};
