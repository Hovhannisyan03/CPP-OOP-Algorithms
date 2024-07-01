#include <iostream>
#include "max_heap.h"

int main()
{
    max_heap<int> heap({4,7,2,3,6,5,4,8,56,94,52,1});
    heap.print();

    heap.build_max_heap();
    heap.print();

    std::cout << heap.extract_max() << std::endl;
    heap.print();

    heap.increase_key(4,256);
    heap.print();

    std::cout << heap.extract_max() << std::endl;

    std::cout << heap.max();

    max_heap<int> heap2 = heap;
     heap.print();
    heap2.print();
    heap2.sort();

    heap.print();
    heap2.print();

    heap2.insert(45);
    heap2.print();

}