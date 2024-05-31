class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0) 
        {
            return head;
        }

        int size = 1;
        ListNode* curr = head;
        while (curr->next) 
        {
            curr = curr->next;
            ++size;
        }
        curr->next = head;

        k %= size;
        int stepsToNewHead = size - k;
        curr = head;
        for (int i = 0; i < stepsToNewHead - 1; ++i)
        {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;

        head = newHead;
        return head;
    }
};
