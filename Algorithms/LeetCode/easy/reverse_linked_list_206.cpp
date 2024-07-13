class Solution {
public:
    ListNode* reverseList(ListNode* m_head) 
    {
        if(!m_head || !m_head->next)
        {
            return m_head;
        }
        
        ListNode *tmp = reverseList(m_head->next);
        m_head->next->next = m_head;
        m_head->next = nullptr;
        return tmp;
    }
};
