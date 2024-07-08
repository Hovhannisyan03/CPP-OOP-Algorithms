#include "queue.h"

int main() 
{
    queue obj({4,5,2,23,6,64});
    std::cout << obj.front() << std::endl;
    obj.dequeue();
    std::cout << obj.front() << std::endl;

    queue obj2(obj);

    bool b = obj == obj2;
    std::cout << b << std::endl;
    obj2.dequeue();
    std::cout << obj.front() << std::endl;
    std::cout << obj2.front() << std::endl;

    b = obj == obj2;
    std::cout << b << std::endl;

    std::cout << obj2.size() << std::endl;

    obj = std::move(obj2);
    std::cout << obj.front() << std::endl;

}