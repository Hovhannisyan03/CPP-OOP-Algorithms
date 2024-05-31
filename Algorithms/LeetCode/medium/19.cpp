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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head->next)
        {
            return head->next;
        }
        ListNode* curr = head;
        int size = 0;
        while(curr)
        {
            curr = curr->next;
            ++size;
        }

        if(size - n == 0)
        {
            return head->next;
        }
        curr = head;
        while(size - 1 > n)
        {
            curr = curr->next;
            --size;
        }

        curr->next = curr->next->next;
        return head;
    }
};