#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <initializer_list>
#include "../vector/vector.h"

namespace my_std
{
    template <typename T,int N = 100>
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

        public:
            const queue& operator=(const queue& other);
            const queue& operator=(queue&& other) noexcept;

        public:
            referance front();
            const_referance front() const;

        public:
            bool empty() const;
            size_type size() const;
            void print() const;

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
            vector<T> m_arr;
            int m_front;
            int m_reArr;
            int m_size;
    };
}
#include "queue.hpp"
#endif
