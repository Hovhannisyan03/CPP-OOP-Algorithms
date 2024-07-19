// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l, int k) 
{
    ListNode<int>* dummy = new ListNode<int>;
    ListNode<int>* temp = dummy;
    temp->next = l;
    while(temp && temp->next)
    {
        if(temp->next->value == k)
        {
            ListNode<int>* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            continue;
        }
        temp = temp->next;
    }
    l = dummy->next;
    delete dummy;
    return l;
}
