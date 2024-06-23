#include <iostream>
#include "unique_ptr.hpp"

int main() {
    unique_ptr<int> ptr(new int(25));
    
    std::cout << *ptr << std::endl;
    
    ptr.reset(new int(10));
    std::cout << *ptr << std::endl;
    
    unique_ptr ptr2(std::move(ptr));
    std::cout << *ptr2 << std::endl;    

    unique_ptr<int> ptr3;
    ptr3 = std::move(ptr2);
    std::cout << *ptr3 << std::endl;  

    int* ptr4 = ptr3.release();
    std::cout << *ptr4 << std::endl;

    unique_ptr<int> ptr5(new int(34));
    unique_ptr<int> ptr6(new int(24));
    std::cout << "ptr5: " << *ptr5 << "\nptr6: " << *ptr6 << std::endl;
    
    ptr5.swap(ptr6);
    std::cout << "ptr5: " << *ptr5 << "\nptr6: " << *ptr6 << std::endl;


    return 0;
}