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
    void reorderList(ListNode* head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast)
        {
            ListNode* temp = slow->next;
            slow->next = nullptr;
            slow = temp;
        }
        slow = reverse(slow);
        bool flag = true;
        fast = head;
        while(fast && slow)
        {
            if(flag)
            {
                ListNode* temp = fast->next;
                fast->next = slow;
                fast = temp;
                flag = false;
            }
            else
            {
                ListNode* temp = slow->next;
                slow->next = fast;
                slow = temp;
                flag = true;
            }
        }
        fast->next = slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp)
        {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};
