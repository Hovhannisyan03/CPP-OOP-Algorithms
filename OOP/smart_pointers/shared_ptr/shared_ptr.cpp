#include "shared_ptr.hpp"

int main()
{
    shared_ptr<int> ptr(new int(25));
    
    std::cout << *ptr << std::endl;
    
    ptr.reset(new int(10));
    std::cout << *ptr << std::endl;
    
    shared_ptr ptr2(std::move(ptr));
    std::cout << *ptr2 << std::endl;    


    shared_ptr ptr3(ptr2);
    std::cout << *ptr3 << std::endl; 

    std::cout << ptr3.use_count() << " " << ptr2.use_count() << std::endl;

    std::cout << ptr.owner_before(ptr3) << std::endl;

    shared_ptr<int> ptr4(new int(34));
    shared_ptr<int> ptr5(new int(24));
    std::cout << "ptr5: " << *ptr4 << "\nptr6: " << *ptr5 << std::endl;
    
    ptr4.swap(ptr5);
    std::cout << "ptr5: " << *ptr4 << "\nptr6: " << *ptr5 << std::endl;


    return 0;
}