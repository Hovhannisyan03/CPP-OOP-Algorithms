#ifndef PRINTER_QUEUE_H
#define PRINTER_QUEUE_H

#include "../queue.h"

class printer_queue
{
    public:
        printer_queue();
        void enqueue(std::string file);
        void dequeue();
        std::string peek() const;
        bool empty() const;
        size_t size() const;
    private:
        my_std::queue<std::string> m_queue;
};
#endif