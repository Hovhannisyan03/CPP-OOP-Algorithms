#include "queue.h"

template <typename T, int N>
my_std::queue<T,N>::queue() : m_arr(N), m_front(0), m_reArr(0), m_size(-1){}

template <typename T, int N>
my_std::queue<T,N>::queue(const queue& other) : m_arr(other.m_arr), m_front(other.m_front), m_reArr(other.m_reArr), m_size(other.m_size){}

template <typename T, int N>
my_std::queue<T,N>::queue(queue&& other) noexcept : m_arr(std::move(other.m_arr)), m_front(std::move(other.m_front)), m_reArr(std::move(other.m_reArr)), m_size(std::move(other.m_size))
{
    other.m_size = -1;
}

template <typename T, int N>
my_std::queue<T,N>::queue(std::initializer_list<value_type> range) : m_arr(N), m_front(0), m_reArr(0), m_size(-1)
{
    for(auto elem : range)
    {
        if(m_size <= N-1)
        {
            m_arr[m_reArr] = elem;
            m_reArr = (m_reArr + 1) % N;
            ++m_size;
        }
        else
        {
            std::cout << "Out of range" << std::endl;
            throw std::out_of_range("Out of range");
        }
    }
}

template <typename T, int N>
my_std::queue<T,N>::~queue()
{
    while(!empty())
    {
        dequeue();
    }
}

template <typename T, int N>
const typename my_std::queue<T,N>::queue& my_std::queue<T,N>::operator=(const queue& other)
{
    if(this != &other)
    {
        m_arr = other.m_arr;
        m_front = other.m_front;
        m_reArr = other.m_reArr;
        m_size = other.m_size;
    }

    return *this;
}

template <typename T, int N>
const typename my_std::queue<T,N>::queue& my_std::queue<T,N>::operator=(queue&& other) noexcept
{
    if(this != &other)
    {
        m_arr = std::move(other.m_arr);
        m_front = std::move(other.m_front);
        m_reArr = std::move(other.m_reArr);
        m_size = std::move(other.m_size);
        other.m_size = -1;
    }

    return *this;
}

template <typename T, int N>
bool my_std::queue<T,N>::empty() const
{
    if(m_size == -1)
    {
        return true;
    }
    return false;
}

template <typename T, int N>
typename my_std::queue<T,N>::size_type my_std::queue<T,N>::size() const
{
    return m_size + 1;
}

template <typename T, int N>
void my_std::queue<T,N>::enqueue(const_referance val)
{
    if(m_size >= N-1)
    {
        std::cout << "Queue is full" << std::endl;
        throw std::out_of_range("Queue is full");
    }
    m_arr[m_reArr] = val;
    m_reArr = (m_reArr + 1) % N;
    ++m_size;
}

template <typename T, int N>
void my_std::queue<T,N>::dequeue()
{
    if(empty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw std::logic_error("Queue is empty");
    }
    m_front = (m_front + 1) % N;
    --m_size;
}

template <typename T, int N>
typename my_std::queue<T,N>::referance my_std::queue<T,N>::front()
{
    if(empty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw std::logic_error("Queue is empty");
    }
    return m_arr[m_front];
}

template<typename T, int N>
typename my_std::queue<T,N>::const_referance my_std::queue<T,N>::front() const
{
    if(empty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw std::logic_error("Queue is empty");
    }
    return m_arr[m_front];
}


template<typename T, int N>
void my_std::queue<T,N>::print() const
{
    if(empty())
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    for(int i = 0; i <= m_size; ++i)
    {
        std::cout << m_arr[(m_front + i) % N] << " ";
    }
    std::cout << std::endl;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator==(const queue& other)
{
    return m_arr == other.m_arr;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator!=(const queue& other)
{
    return m_arr != other.m_arr;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator<(const queue& other)
{
    return m_arr < other.m_arr;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator<=(const queue& other)
{
    return m_arr <= other.m_arr;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator>(const queue& other)
{
    return m_arr > other.m_arr;
}

template <typename T, int N>
bool my_std::queue<T,N>::operator>=(const queue& other)
{
    return m_arr >= other.m_arr;
}
