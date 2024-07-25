#include "stack.h"

int main()
{
    my_std::stack<int> s;
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(4);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.push_range({4,5,7,3,2});
    std::cout << s.size() << std::endl;

    my_std::stack<int,20> s2{7,4,2,6,4,3,1,1};
    s2.push(2);
    std::cout << s2.top() << std::endl;
    s2.pop();
    s2.pop();
    s2.pop();


    my_std::stack<int,20> s3(s2);
    my_std::stack<int> s4(std::move(s)); 

    std::cout << s2.top();
    std::cout << s3.top();
    std::cout << s4.top();
}