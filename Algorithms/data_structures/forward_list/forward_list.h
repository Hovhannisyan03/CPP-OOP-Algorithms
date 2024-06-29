#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include <initializer_list>

template <typename T>
class forward_list
{   
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    private:
        class base_iterator;

    public:
        class const_iterator;
        class iterator;

    private:
        struct Node
        {   
            Node(value_type data);
            Node();
            value_type m_data;
            Node *m_next;
        };

    public:
        forward_list();
        forward_list(const forward_list& obj);
        forward_list(forward_list&& rhv); 
        forward_list(size_type size); 
        forward_list(size_type size, const_reference init); 
        forward_list(std::initializer_list<value_type> init); 
        template <typename U>
        forward_list(U f, U l); 
        ~forward_list();

    public:
        const forward_list& operator=(const forward_list& rhv); 
        const forward_list& operator=(forward_list&& rhv); 
        const forward_list& operator=(std::initializer_list<value_type> init);

        bool operator==(const forward_list& rhv) const; 
        bool operator!=(const forward_list& rhv) const; 
        bool operator<(const forward_list& rhv) const; 
        bool operator<=(const forward_list& rhv) const;
        bool operator>(const forward_list& rhv) const; 
        bool operator>=(const forward_list& rhv) const;

        void swap(forward_list& rhv);
        size_t size() const;
        bool empty() const;
        void resize(size_type s, const_reference init = value_type());
        void clear() noexcept;
        void reverse();

        void push_front(const_reference elem); 
        void pop_front(); 
        void push_back(const_reference elem); 
        void pop_back();

        const_reference front() const;
        reference front(); 
        const_reference back() const; 
        reference back(); 
        const_reference min() const; 
        reference min(); 
        const_reference max() const; 
        reference max(); 


        iterator insert(iterator pos, size_type size, const_reference val);
        iterator insert(iterator pos, std::initializer_list<value_type> init); 
        iterator insert(iterator pos, iterator f, iterator l); 
        iterator insert_def(iterator pos, const_reference val);
        iterator insert_rev(iterator pos, const_reference val); 

        iterator erase(iterator pos); 
        iterator erase(iterator f, iterator l);
        void remove(const_reference val);
    public:
        const_iterator cbegin() const;
        const_iterator cend() const;
        iterator begin();
        iterator end();

    private:
        Node *m_head = nullptr;
};

template <typename T>
class forward_list<T>::base_iterator
{
        friend class forward_list<T>;
    public:
        ~base_iterator(){};
        bool operator==(const base_iterator& rhv) const; 
        bool operator!=(const base_iterator& rhv) const; 
    protected:
        explicit base_iterator(Node* ptr); 
    protected:
        Node* ptr = nullptr;
};

template <typename T>
class forward_list<T>::const_iterator : public forward_list<T>::base_iterator
{
        friend class forward_list<T>;
    public:
        const_iterator(const base_iterator& rhv); 
        const_iterator(base_iterator&& rhv); 
        
        const const_iterator& operator=(const base_iterator& rhv);
        const const_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const;

        const const_iterator& operator++();
        const const_iterator operator++(value_type);

    protected:
        explicit const_iterator(Node* ptr);
};

template <typename T>
class forward_list<T>::iterator : public forward_list<T>::const_iterator
{
        friend class forward_list<T>;
    public:
        iterator(const base_iterator& rhv); 
        iterator(base_iterator&& rhv);

        reference operator*(); 
        pointer operator->(); 

        const iterator& operator=(const base_iterator& rhv); 
        const iterator& operator=(base_iterator&& rhv); 
    protected:
        explicit iterator(Node* ptr);
};

#include "forward_list.hpp"
#endif