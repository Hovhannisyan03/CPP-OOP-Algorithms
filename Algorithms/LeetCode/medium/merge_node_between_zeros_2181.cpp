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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* newList = dummy; 
        int curr_sum = 0;

        ListNode* temp = head->next;
        
        while (temp) 
        {
            if (temp->val == 0) 
            {
                if (curr_sum > 0)
                {
                    newList->next = new ListNode(curr_sum);
                    newList = newList->next;
                }
                curr_sum = 0;
            } 
            else 
            {
                curr_sum += temp->val; 
            }
            temp = temp->next; 
        }
        
        newList = dummy->next;
        delete dummy;
        return newList;
    }
};
