#include "stack.h"

stack::stack() {}


stack::stack(const stack& other) : arr{other.arr}{}

stack::stack(stack&& other) noexcept : arr{std::move(other.arr)}{}

stack::stack(std::initializer_list<value_type> range)
{
    for(auto elem : range)
    {
        arr.push_back(elem);
    }
}

stack::~stack()
{
    arr.clear();
}

stack& stack::operator=(const stack& other) 
{
    if(this == &other)
    {
        return *this;
    }   
    arr = other.arr;
    return *this;
}

stack& stack::operator=(stack&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }   
    arr = std::move(other.arr);
    return *this;
}

bool stack::empty() const
{
    return arr.empty();
}

stack::reference stack::top()
{
    if(empty())
    {
        throw std::underflow_error("Stack is empty");
    } 
    return arr.back();
}

stack::const_reference stack::top()const
{
    if(empty())
    {
        throw std::underflow_error("Stack is empty");
    } 
    return arr.back();
}

stack::size_type stack::size() const
{
    return arr.size();
}

void stack::push(const value_type& value)
{
    arr.push_back(value);
}

void stack::push(value_type&& value)
{
    arr.push_back(value);
}

void stack::push_range(std::initializer_list<value_type> range)
{
    for(auto elem : range)
    {
        arr.push_back(elem);
    }
}

void stack::pop()
{
    arr.pop_back();
}

bool stack::operator==(const stack& other)
{
    return arr == other.arr;
}

bool stack::operator!=(const stack& other)
{
    return arr == other.arr;
}

bool stack::operator>(const stack& other)
{
    return arr > other.arr;
}

bool stack::operator<(const stack& other)
{
    return arr < other.arr;
}

bool stack::operator<=(const stack& other)
{
    return arr <= other.arr;
}

bool stack::operator>=(const stack& other)
{
    return arr >= other.arr;
}








