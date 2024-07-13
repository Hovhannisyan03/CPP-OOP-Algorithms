#ifndef LIST_H
#define LIST_H

#include <iostream>  
template <typename T>  
class list
{
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    private:
        struct Node
        {
            Node* m_prev;
            Node* m_next;
            value_type m_data;
            Node(value_type data);
            Node();
        };  

    private:
        class base_iterator;
    public:
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;

    public:
        list();
        list(const list& rhv);
        list(list&& rhv)noexcept;
        list(size_type size);
        list(size_type size, const_reference init);
        list(std::initializer_list<value_type> init); 
        list(iterator f, iterator l); 
        ~list();

    public:
        void swap(list& rhv);
        void display(bool head = true);
        bool empty();
        void resize(size_type s, const_reference init = value_type());
        void clear() noexcept; 
        void push_back(const_reference val);
        void push_front(const_reference val);
        void pop_back();
        void pop_front();
        size_type size() const;

        const_reference front() const; 
        reference front();
        const_reference back() const; 
        reference back(); 
        const_reference min() const; 
        reference min(); 
        const_reference max() const;
        reference max(); 

        const list& operator=(const list& rhv); 
        const list& operator=(list&& rhv); 
        const list& operator=(std::initializer_list<value_type> init);

        bool operator==(const list& rhv) const; 
        bool operator!=(const list& rhv) const; 
        bool operator<(const list& rhv) const; 
        bool operator<=(const list& rhv) const;
        bool operator>(const list& rhv) const; 
        bool operator>=(const list& rhv) const; 

        iterator begin();
        const_iterator cbegin() const;
        reverse_iterator rbegin();
        const_reverse_iterator crbegin() const;

        iterator end();
        const_iterator cend() const;
        reverse_iterator rend();
        const_reverse_iterator crend() const;

        iterator insert(iterator pos, value_type val);
        iterator insert(iterator pos, size_type size, const_reference val); 
        iterator insert(iterator pos, std::initializer_list<value_type> init);
        iterator insert(iterator pos, iterator f, iterator l);
        iterator insert_def(iterator pos, const_reference val); 
        iterator insert_rev(iterator pos, const_reference val); 

        iterator erase(iterator pos); 
        iterator erase(iterator f, iterator l); 

        size_type remove(const_reference val); 
        void reverse(); 
        void print()const;
        void merge(const list& other);

        iterator find(const_reference elem);
        iterator rfind(const_reference elem);

    private:
        bool is_valid_iterator(iterator pos);
        Node* m_head;
        Node* m_tail;
};

template<typename T>
class list<T>::base_iterator
{
        friend class list<T>;
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
class list<T>::const_iterator : public list<T>::base_iterator
{
        friend class list<T>;
    public:
        const_iterator(const base_iterator& rhv); 
        const_iterator(base_iterator&& rhv); 
        
        const const_iterator& operator=(const base_iterator& rhv); 
        const const_iterator& operator=(base_iterator&& rhv);
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_iterator& operator++(); 
        const const_iterator operator++(value_type); 
        const const_iterator& operator--(); 
        const const_iterator operator--(value_type);

    protected:
        explicit const_iterator(Node* ptr); 
};

template <typename T>
class list<T>::iterator : public list<T>::const_iterator
{
        friend class list<T>;
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

template <typename T>
class list<T>::const_reverse_iterator : public list<T>::base_iterator
{
        friend class list<T>;
    public:
        const_reverse_iterator(const base_iterator& rhv); 
        const_reverse_iterator(base_iterator&& rhv);
        
        const const_reverse_iterator& operator=(const base_iterator& rhv); 
        const const_reverse_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_reverse_iterator& operator++(); 
        const const_reverse_iterator operator++(value_type); 
        const const_reverse_iterator& operator--(); 
        const const_reverse_iterator operator--(value_type); 

    protected:
        explicit const_reverse_iterator(Node* ptr);
};

template <typename T>
class list<T>::reverse_iterator : public list<T>::const_reverse_iterator
{
        friend class list<T>;
    public:
        reverse_iterator(const base_iterator& rhv); 
        reverse_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const reverse_iterator& operator=(const base_iterator& rhv); 
        const reverse_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit reverse_iterator(Node* ptr);
};


#include "list.hpp"
#endif
