#include "printer_queue.h"

printer_queue::printer_queue() : m_queue() {}

void printer_queue::enqueue(std::string file)
{
    m_queue.enqueue(file);
}

void printer_queue::dequeue()
{
    if(m_queue.empty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw std::logic_error("Queue is empty");
    }
    std::cout << m_queue.front() << " was printed" << std::endl;
    m_queue.dequeue();
}

std::string printer_queue::peek() const
{
    if(m_queue.empty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw std::logic_error("Queue is empty");
    }
    return m_queue.front();
}

bool printer_queue::empty() const
{
    return m_queue.empty();
}

size_t printer_queue::size() const
{
    return m_queue.size();  
}