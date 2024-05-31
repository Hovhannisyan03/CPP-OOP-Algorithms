class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        int size = s1.size();
        while(size -- > 0)
        {
            s2.push(s1.top());
            s1.pop();
        } 
        s1.push(x);

        size = s2.size();
        while(size -- > 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() 
    {
        int ret = s1.top();
        s1.pop();
        return ret;
    }
    
    int peek() 
    {
        return s1.top();
    }
    
    bool empty() 
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */