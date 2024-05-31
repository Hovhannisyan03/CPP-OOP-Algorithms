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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int size = 0;
        ListNode* curr = list1;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(size < b)
        {
            if(size == a - 1)
            {
                prev = curr;
            }
            if(size == b - 1)
            {
                next = curr;
            }
            ++size;
            curr = curr->next;
        }    

        prev->next = list2; 
        while(prev->next)
        {
            prev = prev->next;
        }
        prev->next = curr->next;

        return list1;
    }
};