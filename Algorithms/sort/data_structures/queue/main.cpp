#include "queue.h"

int main() 
{
   Queue ob; 
   Queue obj{1, 3, 4, 6};
   Queue ob2(obj);

    std::cout << obj.front();
    obj.pop();
    std::cout << obj.front();

}