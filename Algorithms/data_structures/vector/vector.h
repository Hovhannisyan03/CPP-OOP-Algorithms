#ifndef __VECTOR__HPP__
#define __VECTOR__HPP__

#include <iostream>
#include <exception>

template <typename T>
class vector
{
    public:
        using value_type = T;
        using size_type = std::size_t;  
        using difference_type = std::size_t;      
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    public:
        class const_iterator;
        class iterator;
        class const_reverse_iterator;
        class reverse_iterator;

    public:

        vector();
        vector(const vector& rhv);
        vector(vector&& rhv) noexcept;
        vector(std::initializer_list<value_type> init);
        vector(size_type size, const_reference val);
        template <typename InputIt>
        vector(InputIt first, InputIt last);
        ~vector();

    public:

        const vector& operator=(const vector& rhv);
        const vector& operator=(vector&& rhv) noexcept;
        const vector& operator=(std::initializer_list<value_type> init);
    public:
        reference at(size_type pos);
        const_reference at(size_type pos) const;

        reference operator[](size_type pos);
        const_reference operator[](size_type pos) const;

        reference front();
        const_reference front() const;

        reference back();
        const_reference back() const;

        pointer data();
        const_pointer data() const;

    public:
        void push_back(const_reference val);
        void pop_back();
        void push_front(const_reference value);
        void pop_front();

    public:
        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const noexcept;
        
        iterator end() noexcept;
        const_iterator end() const noexcept;
        const_iterator cend() const noexcept;
        
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator crbegin() const noexcept;
        
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        const_reverse_iterator crend() const noexcept;
        
    public:
        bool empty() const;
        size_type size() const;
        size_type capacity() const;
        void reserve(size_type new_cap);
        void clear();
        void shrink_to_fit();
        value_type find(value_type value) const;
        void reverse();
        void sort();

    public:
        iterator insert(const_iterator pos, const_reference val);
        iterator insert(const_iterator pos, size_type count, const_reference val);
        iterator insert(const_iterator pos, std::initializer_list<value_type> init);
        template <typename InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);

        void insert(size_type index, value_type value);
        void assign(std::initializer_list<value_type> ilist);
        void assign(const_iterator first, const_iterator last);
        void assign(size_type count, const vector& rhv); 

        iterator erase(const_iterator pos);
        iterator erase(const_iterator first, const_iterator last);

        void resize(size_type count,const_reference val = 0);
    
    public:
        bool operator==(const vector& other) const;
        bool operator!=(const vector& other) const;
        bool operator<(const vector& other) const;
        bool operator<=(const vector& other) const;
        bool operator>(const vector& other) const;
        bool operator>=(const vector& other) const;
        
    private:
        size_type m_size;
        size_type m_capacity;
        pointer m_arr;
};

template <typename T>
class vector<T>::const_iterator
{
        friend class vector<T>;
    protected:
        pointer m_ptr;
    private:
        const_iterator(pointer ptr);
    public:
        const_iterator() = default;
        const_iterator(const const_iterator&) = default;      
        const_iterator(const_iterator&&) = default;

        const_iterator& operator=(const const_iterator&) = default;      
        const_iterator& operator=(const_iterator&&) = default;

        const_iterator operator+(size_type n) const;      
        const_iterator operator-(size_type n) const;

        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);

        const_reference operator*() const;
        const_pointer operator->() const;

        const_reference operator[](size_type pos) const;

        bool operator==(const const_iterator& other) const;      
        bool operator!=(const const_iterator& other) const;      
        bool operator<(const const_iterator& other) const;      
        bool operator<=(const const_iterator& other) const;      
        bool operator>(const const_iterator& other) const;      
        bool operator>=(const const_iterator& other) const;      
};

template <typename T>
class vector<T>::iterator : public vector<T>::const_iterator
{
        friend class vector<T>;
    private:
        iterator(pointer ptr);
    public:
        iterator() = default;
        iterator(const iterator&) = default;      
        iterator(iterator&&) = default;

        iterator& operator=(const iterator&) = default;      
        iterator& operator=(iterator&&) = default;

        iterator operator+(size_type n) const;      
        iterator operator-(size_type n) const;

        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);

        reference operator*();
        pointer operator->();

        reference operator[](size_type pos) const;
};


template <typename T>
class vector<T>::const_reverse_iterator
{
        friend class vector<T>;
    protected:
        pointer m_ptr;
    private:
        const_reverse_iterator(pointer ptr);
    public:
        const_reverse_iterator() = default;
        const_reverse_iterator(const const_reverse_iterator&) = default;      
        const_reverse_iterator(const_reverse_iterator&&) = default;

        const_reverse_iterator& operator=(const const_reverse_iterator&) = default;      
        const_reverse_iterator& operator=(const_reverse_iterator&&) = default;

        const_reverse_iterator operator+(size_type n) const;      
        const_reverse_iterator operator-(size_type n) const;

        const_reverse_iterator& operator++();
        const_reverse_iterator operator++(int);
        const_reverse_iterator& operator--();
        const_reverse_iterator operator--(int);

        const_reference operator*() const;
        const_pointer operator->() const;

        const_reference operator[](size_type pos) const;

        bool operator==(const const_reverse_iterator& other) const;      
        bool operator!=(const const_reverse_iterator& other) const;      
        bool operator<(const const_reverse_iterator& other) const;      
        bool operator<=(const const_reverse_iterator& other) const;      
        bool operator>(const const_reverse_iterator& other) const;      
        bool operator>=(const const_reverse_iterator& other) const;      
};

template <typename T>
class vector<T>::reverse_iterator : public vector<T>::const_reverse_iterator
{
        friend class vector<T>;
    private:
        reverse_iterator(pointer ptr);
    public:
        reverse_iterator() = default;
        reverse_iterator(const reverse_iterator&) = default;      
        reverse_iterator(reverse_iterator&&) = default;

        const reverse_iterator& operator=(const reverse_iterator& rhv);      
        const reverse_iterator& operator=(reverse_iterator&& rhv);

        reverse_iterator operator+(size_type n) const;      
        reverse_iterator operator-(size_type n) const;

        reverse_iterator& operator++();
        reverse_iterator operator++(int);
        reverse_iterator& operator--();
        reverse_iterator operator--(int);

        reference operator*();
        pointer operator->();

        reference operator[](size_type pos) const;
};


#include "vector.hpp"
#endif 