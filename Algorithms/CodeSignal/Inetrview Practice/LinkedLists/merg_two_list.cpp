// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l1, ListNode<int> * l2) 
{
    if(!l1)
    {
        return l2;
    }
    if(!l2)
    {
        return l1;
    }
    if(l1->value <= l2->value)
    {
        l1->next = solution(l1->next, l2);
        return l1;   
    }
    else
    {
        l2->next = solution(l1, l2->next);
        return l2;
    }
}
