#ifndef __QUEUE__
#define __QUEUE__
#include <deque>
#include <initializer_list>
#include <iostream>
#include <vector>

class Queue
{
    public:
        using value_type = int;
        using size_type = size_t;
        using referance = value_type&;
        using const_referance = const value_type&;

    public:
        Queue();
        Queue(const Queue& rhv);
        Queue(Queue&& other);
        Queue(std::initializer_list<value_type> init);
        ~Queue();

        const Queue& operator=(const Queue& rhv);
        const Queue& operator=(Queue&& rhv);

    public:
        referance front();
        const_referance front() const;

        referance back();
        const_referance back() const;

    public:
        bool empty() const;
        size_type size() const;

    public:
        void push(const_referance val);
        void pop();

    public:
        bool operator==(const Queue& other);
        bool operator!=(const Queue& other);
        bool operator<(const Queue& other);
        bool operator<=(const Queue& other);
        bool operator>(const Queue& other);
        bool operator>=(const Queue& other);

    private:
        std::vector<value_type> m_arr;
};

  
#endif

    