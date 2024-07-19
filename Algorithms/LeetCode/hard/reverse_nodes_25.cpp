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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k == 1 || !head || !head->next)
        {
            return head;
        }
        int temp_k = 0;
        bool flag = true;
        ListNode* curr = head;
        ListNode* first_head = nullptr;
        ListNode* curr_head = nullptr;
        ListNode* curr_tail_next = nullptr;
        while(curr)
        {   
            if(flag)
            {
                first_head = curr;
            }
            else
            {
                curr_head = curr;
            }
            temp_k = k;
            while(temp_k - 1 != 0 && curr)
            {
                --temp_k;
                curr = curr->next;
            }
            if(!curr)
            {
                break;
            }

            curr_tail_next = curr->next;
            curr->next = nullptr;
            if(flag)
            {
                head = reverse(first_head,curr_tail_next);
                flag = false;
            }
            else
            {
                first_head->next = reverse(curr_head,curr_tail_next);
                first_head = curr_head;
            }
            curr = curr_tail_next;

        }
        return head;
    }

private:
    ListNode* reverse(ListNode* head, ListNode* tail_next)
    {
        ListNode* prev = tail_next;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;//reverse head
    }
};
