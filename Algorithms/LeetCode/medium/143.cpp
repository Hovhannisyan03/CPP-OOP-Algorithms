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
        if (!head || !head->next)
        {   
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }    
        fast = reverseList(slow->next);
        slow->next = nullptr;
        slow = head;
        
        ListNode* tmp = nullptr;
        while (fast) 
        {
            tmp = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = tmp;
        }
    }
private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};