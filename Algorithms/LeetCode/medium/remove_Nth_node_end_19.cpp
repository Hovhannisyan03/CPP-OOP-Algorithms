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
            delete head;
            return nullptr;
        }

        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            ++size;
            temp = temp->next;
        }
        
        if(size - n == 0)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        temp = head;
        while(size - 1 > n)
        {
            temp = temp->next;
            --size;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};
