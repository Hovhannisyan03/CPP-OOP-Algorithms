// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) 
{
    stack<int> a_stack;
    stack<int> b_stack;
    ListNode<int>* a_curr = a;
    ListNode<int>* b_curr = b;
    while(a_curr)
    {
        a_stack.push(a_curr->value);
        a_curr = a_curr->next;
    }
    while(b_curr)
    {
        b_stack.push(b_curr->value);
        b_curr = b_curr->next;
    }
    
    ListNode<int>* dummy = new ListNode<int>;
    ListNode<int>* temp = dummy;
    int carry = 0;
    while(!a_stack.empty() || !b_stack.empty() || carry)
    {   
        int a_val = a_stack.empty() ? 0 : a_stack.top();
        int b_val = b_stack.empty() ? 0 : b_stack.top();
        ListNode<int>* newNode = new ListNode((a_val + b_val + carry) % 10000);
        carry = (a_val + b_val + carry) / 10000;
        newNode->next = temp->next;
        temp->next = newNode;
        if (!a_stack.empty())
        { 
            a_stack.pop();
        }
        if (!b_stack.empty()) 
        {
            b_stack.pop();
        }
    }   
    
    temp = dummy->next;
    delete dummy;
    return temp;
}
