// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int>* reverse(ListNode<int>* head)
{
    ListNode<int>* prev = nullptr;
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

bool solution(ListNode<int> * l) 
{
    ListNode<int>* slow = l;
    ListNode<int>* fast = l;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }   
    if(fast)
    {
        slow = slow->next;
    } 
    slow = reverse(slow); 
    fast = l;
    while(fast && slow)
    {
        if(fast->value != slow->value)
        {
            return false;
        }     
        fast = fast->next;
        slow = slow->next;   
    }
    return true;
}
