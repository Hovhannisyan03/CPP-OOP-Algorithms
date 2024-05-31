#include "stack.h"

int main()
{
    stack s;
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(4);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.push_range({4,5,7,3,2});
    std::cout << s.size() << std::endl;

    stack s2{7,4,2,6,4,3,1,1};
    s2.push(2);
    std::cout << s2.top() << std::endl;
    s2.pop();
    s2.pop();
    s2.pop();


    stack s3(s2);
    stack s4(std::move(s)); 

    std::cout << s2.top();
    std::cout << s3.top();
    std::cout << s4.top();

    std::cout << "end";

}