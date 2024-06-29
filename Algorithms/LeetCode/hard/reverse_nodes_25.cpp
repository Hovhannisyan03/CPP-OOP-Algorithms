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
        ListNode* rev_head = nullptr;
        ListNode* rev_tail = nullptr;
        ListNode* organized = nullptr;
        int count = 0;
        ListNode* curr = head;
        while(curr)
        {
            rev_head = curr;
            rev_tail = curr;
            curr = curr->next;
            int k_cpy = k;
            while(k_cpy - 1 > 0 && curr)
            {
                rev_tail = rev_tail->next;
                curr = curr->next;
                --k_cpy;
            }
            if(count != 0 && k_cpy - 1 == 0)
            {
                while(organized->next != rev_head)
                {
                    organized = organized->next;
                }
                organized->next = rev_tail;
            }
            if(rev_tail && k_cpy - 1 == 0)
            {
                if(count == 0)
                {
                    head = reverseList(rev_head, rev_tail, curr);
                    organized = head;
                    ++count;
                }
                else
                {
                    organized = reverseList(rev_head, rev_tail, curr);
                }
            }
            else
            {
                break;
            }
        }
        return head;
    }

private:
    ListNode* reverseList(ListNode* head, ListNode* tail, ListNode* tail_next)
    {
        ListNode* end = tail_next;
        ListNode* prev = tail_next;
        while(head != end)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;//reverse head
    }
};
