#include "stack.h"

template <typename T, int N>
my_std::stack<T,N>::stack() : m_arr(N), m_size(-1){}

template <typename T, int N>
my_std::stack<T,N>::stack(const stack& other) : m_arr(other.m_arr), m_size(other.m_size){}

template <typename T, int N>
my_std::stack<T,N>::stack(stack&& other) noexcept : m_arr(std::move(other.m_arr)), m_size(std::move(other.m_size))
{
    other.m_size = -1;
}

template <typename T, int N>
my_std::stack<T,N>::stack(std::initializer_list<value_type> range) : m_arr(N), m_size(-1)
{
    for(auto elem : range)
    {
        if(m_size <= N-1)
        {
            m_arr[++m_size] = elem;
        }
        else
        {
            std::cout << "Out of range" << std::endl;
            throw std::out_of_range("Out of range");
        }
    }
}

template <typename T, int N>
my_std::stack<T,N>::~stack()
{
    while(!empty())
    {
        pop();
    }
}


template <typename T, int N>
my_std::stack<T,N>& my_std::stack<T,N>::operator=(const stack& other)
{
    if(this != &other)
    {
        m_arr = other.m_arr;
        m_size = other.m_size;
    }

    return *this;
}

template <typename T, int N>
my_std::stack<T,N>& my_std::stack<T,N>::operator=(stack&& other) noexcept
{
    if(this != &other)
    {
        m_arr = std::move(other.m_arr);
        m_size = std::move(other.m_size());
        other.m_size = -1;
    }
    return *this;
}

template <typename T, int N>
void my_std::stack<T,N>::push(const_reference value)
{
    if(m_size >= N - 1)
    {
        std::cout << "Stack is full" << std::endl;
        return;
    }
    m_arr[++m_size] = value;
}

template <typename T, int N>
void my_std::stack<T,N>::push(value_type&& value)
{
    if(m_size >= N - 1)
    {
        std::cout << "Stack is full" << std::endl;
        return;
    }
    m_arr[++m_size] = value;
}

template <typename T, int N>
void my_std::stack<T,N>::push_range(std::initializer_list<value_type> range) 
{
    for(auto elem : range)
    {
        if(m_size <= N-1)
        {
            m_arr[++m_size] = elem;
        }
        else
        {
            std::cout << "Out of range" << std::endl;
            throw std::out_of_range("Out of range");
        }
    }
}


template <typename T, int N>
bool my_std::stack<T,N>::empty() const
{
    if(m_size == -1)
    {
        return true;
    }
    return false;
}


template <typename T, int N>
typename my_std::stack<T,N>::reference my_std::stack<T,N>::top() 
{
    if(empty())
    {
        std::cout << "Stack is empty" << std::endl;
        throw std::out_of_range("Stack is empty");
    }
    return m_arr[m_size];
}

template <typename T, int N>
typename my_std::stack<T,N>::const_reference my_std::stack<T,N>::top() const
{
    if(empty())
    {
        std::cout << "Stack is empty" << std::endl;
        throw std::out_of_range("Stack is empty");
    }
    return m_arr[m_size];
}

template <typename T, int N>
void my_std::stack<T,N>::pop()
{
    if(empty())
    {
        std::cout << "Stack is empty" << std::endl;
        throw std::out_of_range("Stack is empty");
    }
    --m_size;
}

template <typename T, int N>
typename my_std::stack<T,N>::size_type my_std::stack<T,N>::size() const
{
    return m_size + 1;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator==(const stack& other)
{
    return m_arr == other.m_arr;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator!=(const stack& other)
{
    return m_arr == other.m_arr;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator>(const stack& other)
{
    return m_arr > other.m_arr;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator<(const stack& other)
{
    return m_arr < other.m_arr;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator<=(const stack& other)
{
    return m_arr <= other.m_arr;
}

template <typename T, int N>
bool my_std::stack<T,N>::operator>=(const stack& other)
{
    return m_arr >= other.m_arr;
}


