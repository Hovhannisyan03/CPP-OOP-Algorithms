#include "queue.h"

template <typename T>
queue<T>::queue() : m_arr() {}

template <typename T>
queue<T>::queue(const queue& other) : m_arr(other.m_arr){}

template <typename T>
queue<T>::queue(queue&& other) noexcept : m_arr(std::move(other.m_arr)) {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> init) : m_arr(init){}

template <typename T>
queue<T>::~queue()
{
    m_arr.clear();
}

template <typename T>
const queue<T>& queue<T>::operator=(const queue& other) 
{
    if(this != &other)
    {
        m_arr = other.m_arr;
    }

    return *this;
}

template <typename T>
const queue<T>& queue<T>::operator=(queue&& other) noexcept
{
    if(this != &other)
    {
        m_arr = std::move(other.m_arr);
    }

    return *this;
}


template <typename T>
typename queue<T>::referance queue<T>::front()
{
    return m_arr.front();
}

template <typename T>
typename queue<T>::const_referance queue<T>::front() const
{
    return m_arr.front();
}


template <typename T>
typename queue<T>::referance queue<T>::back()
{
    return m_arr.back();
}

template <typename T>
typename queue<T>::const_referance queue<T>::back() const
{
    return m_arr.back();
}

template <typename T>
bool queue<T>::empty() const
{
    return m_arr.empty();
}

template <typename T>
void queue<T>::enqueue(const_referance val)
{
    m_arr.push_back(val);
}

template <typename T>
void queue<T>::dequeue()
{
    m_arr.pop_front();
}

template <typename T>
typename queue<T>::size_type queue<T>::size() const
{
    return m_arr.size();
}


template <typename T>
bool queue<T>::operator==(const queue& other)
{
    return m_arr == other.m_arr;
}

template <typename T>
bool queue<T>::operator!=(const queue& other)
{
    return m_arr != other.m_arr;
}

template <typename T>
bool queue<T>::operator<(const queue& other)
{
    return m_arr < other.m_arr;
}

template <typename T>
bool queue<T>::operator<=(const queue& other)
{
    return m_arr <= other.m_arr;
}

template <typename T>
bool queue<T>::operator>(const queue& other)
{
    return m_arr > other.m_arr;
}

template <typename T>
bool queue<T>::operator>=(const queue& other)
{
    return m_arr >= other.m_arr;
}



