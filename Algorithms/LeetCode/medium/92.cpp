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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head || !head->next || left == right)
        {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* rev_node = nullptr;
        ListNode* rev_prev = nullptr;
        int count = 1;
        while(right >= count)
        {
            if(count < left)
            {
                rev_prev = curr;
            }
            if(count >= left)
            {
                rev_node = curr;
                curr = curr->next;
                rev_node->next = prev;
                prev = rev_node;
            }
            else
            {
                curr = curr->next;
            }
            ++count;
        }

        if(left == 1)
        {
            head->next = curr;
            head = prev;

        }
        else
        {
            rev_prev->next->next = curr;
            rev_prev->next = prev;
        }

        return head;
    }
};