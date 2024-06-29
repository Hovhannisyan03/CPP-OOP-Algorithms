
#include "queue.h"

Queue::Queue(): m_arr(){}

Queue::Queue(const Queue& rhv) : m_arr(rhv.m_arr){}

Queue::Queue(Queue && other): m_arr(std::move(other.m_arr)){}

Queue::Queue(std::initializer_list<value_type> init): m_arr()
{
    for (auto &i : init) 
    {
        m_arr.push_back(i);
    }
}

Queue::~Queue()
{
    m_arr.clear();
}

const Queue& Queue::operator=(const Queue& rhv)
{   
    if (this != &rhv) 
    {
        m_arr = rhv.m_arr;
    }
    return *this;
}


const Queue& Queue::operator=(Queue&& other)
{
    if (this != &other) {        
        m_arr = std::move(other.m_arr);
    }

    return *this; 
}

Queue::referance Queue::front()
{
    return m_arr.front();
}

Queue::const_referance Queue::front() const
{
    return m_arr.front();
}

Queue::referance Queue::back()
{
    return m_arr.back();
}

Queue::const_referance Queue::back() const
{
    return m_arr.back();
}

bool Queue::empty() const
{
    return m_arr.empty();
}

Queue::size_type Queue::size() const
{
    return m_arr.size();
}

void Queue::push(const_referance val)
{
    m_arr.push_back(val);
}

void Queue::pop()
{
    if (m_arr.empty()) 
    {
        throw 1;
    }
    
    m_arr.erase(m_arr.begin());
}

bool Queue::operator==(const Queue& rhv)
{
    return m_arr == rhv.m_arr;
}

bool Queue::operator!=(const Queue& rhv)
{
    return m_arr != rhv.m_arr;
}

bool Queue::operator>(const Queue& rhv)
{
    return m_arr > rhv.m_arr;
}

bool Queue::operator<(const Queue& rhv)
{
    return m_arr < rhv.m_arr;
}

bool Queue::operator<=(const Queue& rhv)
{
    return m_arr <= rhv.m_arr;
}

bool Queue::operator>=(const Queue& rhv)
{
    return m_arr >= rhv.m_arr;
}