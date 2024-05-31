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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* curr = head;
        ListNode* h1 = new ListNode;
        ListNode* h2 = new ListNode;
        ListNode *h1_curr = h1;
        ListNode *h2_curr = h2;
        while(curr)
        {
            if(curr->val < x)
            {
                h1_curr->next = curr;
                h1_curr = h1_curr->next;
            }
            else
            {
                h2_curr->next = curr;
                h2_curr = h2_curr->next;  
            }
            curr = curr->next;
        }
        h1_curr->next = h2->next;    
        h2_curr->next = nullptr;

        return h1->next;
    }
};