#include <iostream>
#include "auto_ptr.hpp"

int main() {
    auto_ptr<int> ptr(new int(25));
    
    std::cout << *ptr << std::endl;
    
    ptr.reset(new int(10));
    std::cout << *ptr << std::endl;
    
    auto_ptr ptr2(std::move(ptr));
    std::cout << *ptr2 << std::endl;    

    auto_ptr<int> ptr3;
    ptr3 = std::move(ptr2);
    std::cout << *ptr3 << std::endl;  

    int* ptr4 = ptr3.release();
    std::cout << *ptr4 << std::endl;

    return 0;
}