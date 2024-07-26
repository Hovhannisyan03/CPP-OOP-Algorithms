#include "printer_queue.h"

int main()
{
    printer_queue queue;
    std::cout << queue.empty() << std::endl;
    queue.enqueue("picture1.jpg");
    queue.enqueue("picture2.jpg");

    queue.dequeue();

    queue.enqueue("code.cpp");
    std::cout << queue.size() << std::endl;

    queue.enqueue("file2.docs");
    queue.dequeue();

    std::cout << "Next is: " << queue.peek() << std::endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

}