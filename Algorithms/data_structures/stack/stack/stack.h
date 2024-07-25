#ifndef STACK_H
#define STACK_H

#include <initializer_list>
#include "../vector/vector.h"
#include <iostream>

namespace my_std
{
    template <typename T, int N = 100>
    class stack
    {
        public:
            using value_type = T;
            using size_type = int;
            using reference = value_type&;
            using const_reference = const reference;
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
            void push(const_reference value);
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
            vector<T> m_arr;
            int m_size;
    };
}
#include "stack.hpp"
#endif