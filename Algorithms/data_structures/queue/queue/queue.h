#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <initializer_list>
#include "../forward_list/forward_list.h"  

template <typename T>
class queue
{
 public:
        using value_type = T;
        using size_type = size_t;
        using referance = value_type&;
        using const_referance = const value_type&;

    public:
        queue();
        queue(const queue& other);
        queue(queue&& other) noexcept;
        queue(std::initializer_list<value_type> range);
        ~queue();

        const queue& operator=(const queue& other);
        const queue& operator=(queue&& other) noexcept;

    public:
        referance front();
        const_referance front() const;

        referance back();
        const_referance back() const;

    public:
        bool empty() const;
        size_type size() const;

    public:
        void enqueue(const_referance val);
        void dequeue();

    public:
        bool operator==(const queue& other);
        bool operator!=(const queue& other);
        bool operator<(const queue& other);
        bool operator<=(const queue& other);
        bool operator>(const queue& other);
        bool operator>=(const queue& other);

    private:
        forward_list<T> m_arr;
};

#include "queue.hpp"
#endif