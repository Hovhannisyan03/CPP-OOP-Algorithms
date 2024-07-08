#include "stack.h"

template <typename T>
stack<T>::stack() : m_arr() {}

template <typename T>
stack<T>::stack(const stack& other) : m_arr(other.m_arr) {}

template <typename T>
stack<T>::stack(stack&& other) noexcept : m_arr(std::move(other.m_arr)) {}


template <typename T>
stack<T>::stack(std::initializer_list<value_type> range) : m_arr{range} {}


template <typename T>
stack<T>::~stack()
{
    m_arr.clear();
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& other)
{
    if(this != &other)
    {
        m_arr = other.m_arr;
    }

    return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) noexcept
{
    if(this != &other)
    {
        m_arr = std::move(other.m_arr);
    }

    return *this;
}

template <typename T>
typename stack<T>::reference stack<T>::top()
{
    return m_arr.back();
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() const
{
    return m_arr.back();
}

template <typename T>
bool stack<T>::empty() const
{
    return m_arr.empty();    
}

template <typename T>
typename stack<T>::size_type stack<T>::size() const
{
    return m_arr.size();
}

template <typename T>
void stack<T>::push(const_reference value)
{
    m_arr.push_back(value);
}

template <typename T>
void stack<T>::push(value_type&& value)
{
    m_arr.push_back(value);
}

template <typename T>
void stack<T>::push_range(std::initializer_list<value_type> range)
{
    for(auto& elem : range)
    {
        m_arr.push_back(elem);
    }
}

template <typename T>
void stack<T>::pop()
{
    m_arr.pop_back();
}

template <typename T>
bool stack<T>::operator==(const stack& other)
{
    return m_arr == other.m_arr;
}

template <typename T>
bool stack<T>::operator!=(const stack& other)
{
    return m_arr == other.m_arr;
}

template <typename T>
bool stack<T>::operator>(const stack& other)
{
    return m_arr > other.m_arr;
}

template <typename T>
bool stack<T>::operator<(const stack& other)
{
    return m_arr < other.m_arr;
}

template <typename T>
bool stack<T>::operator<=(const stack& other)
{
    return m_arr <= other.m_arr;
}

template <typename T>
bool stack<T>::operator>=(const stack& other)
{
    return m_arr >= other.m_arr;
}