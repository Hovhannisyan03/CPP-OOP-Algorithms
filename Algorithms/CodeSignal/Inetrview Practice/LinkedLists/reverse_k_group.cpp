// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

ListNode<int>* reverse(ListNode<int>* head, ListNode<int>* tail_next)
{
    ListNode<int>* prev = tail_next;
    ListNode<int>* curr = head;
    while(curr)
    {
        ListNode<int>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode<int> * solution(ListNode<int> * l, int k) 
{
    if(k == 1 || !l || !l->next)
    {
        return l;
    }
    ListNode<int>* curr = l;
    ListNode<int>* first_head = nullptr;
    ListNode<int>* curr_head = nullptr;
    ListNode<int>* curr_tail_next = nullptr;
    bool flag = true;
    
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
        int tmp_k = k;
        while(curr && tmp_k - 1 != 0)
        {
            --tmp_k;
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
            l = reverse(first_head,curr_tail_next);
            flag = false;
        }
        else
        {
            first_head->next = reverse(curr_head, curr_tail_next);
            first_head = curr_head;
        }
        curr = curr_tail_next;
    }
    return l;
}
