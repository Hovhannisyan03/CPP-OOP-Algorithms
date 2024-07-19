// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l, int n) 
{
    if(!l || !l->next || n == 0)
    {
        return l;
    }
    ListNode<int>* curr = l;
    int size = 0;
    while(curr)
    {
        ++size;
        curr = curr->next;
    }
    if(size - n == 0)
    {
        return l;
    }
    curr = l;
    while(size - n - 1 > 0)
    {
        curr = curr->next;
        --size;
    }
    ListNode<int>* newHead = curr->next;
    ListNode<int>* temp_curr = curr->next;
    curr->next = nullptr;
    while(temp_curr->next)
    {
        temp_curr = temp_curr->next;
    }
    temp_curr->next = l;
    l = newHead;
    return l;
}
