#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <initializer_list>
#include <vector>

class stack
{
    public:
        using value_type = int;
        using size_type = int;
        using reference = int&;
        using const_reference = const int&;
    public:
        stack();
        stack(const stack& other);
        stack(stack&& other) noexcept;
        stack(std::initializer_list<value_type> range);
        ~stack();
    public:
        stack& operator=(const stack& other);
        stack& operator=(stack&& other) noexcept;
    public:
        reference top();
        const_reference top() const;
        bool empty() const;
        size_type size() const;
        void push(const value_type& value);
        void push(value_type&& value);
        void push_range(std::initializer_list<value_type> range);
        void pop();
    public:
        bool operator==(const stack& other);
        bool operator!=(const stack& other);
        bool operator<(const stack& other);
        bool operator<=(const stack& other);
        bool operator>(const stack& other);
        bool operator>=(const stack& other);
    private:
        std::vector<value_type> arr;
};

#endif