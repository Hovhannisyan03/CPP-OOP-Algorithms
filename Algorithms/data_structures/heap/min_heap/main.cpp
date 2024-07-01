#include <iostream>
#include "min_heap.h"

int main()
{
    min_heap<int> heap({4,7,2,3,6,5,4,8,56,94,52,1});
    heap.print();

    heap.build_min_heap();
    heap.print();

    std::cout << heap.extract_min() << std::endl;
    heap.print();

    heap.decrease_key(4,2);
    heap.print();

    std::cout << heap.extract_min() << std::endl;

    std::cout << heap.min() << std::endl;

    min_heap<int> heap2 = heap;
    heap.print();
    heap2.print();
    heap2.sort();

    heap.print();
    heap2.print();

    heap2.insert(45);
    heap2.print();

    std::cout << heap.min() << std::endl;
    heap2.extract_min();
    std::cout << heap2.min() << std::endl;
    
    heap2.extract_min();
    std::cout << heap2.min() << std::endl;

}