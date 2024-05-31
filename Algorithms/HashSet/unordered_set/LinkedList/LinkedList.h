#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <initializer_list>

class LinkedList
{   
    public:
        using value_type = int;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    private:
        struct Node
        {   
            Node(value_type data);
            Node();
            value_type m_data;
            Node *m_next;
        };

    private:
        class base_iterator
        {
            friend LinkedList;
        public:
            ~base_iterator(){};
            bool operator==(const base_iterator& rhv) const; 
            bool operator!=(const base_iterator& rhv) const; 
        protected:
            explicit base_iterator(Node* ptr); 
        protected:
            Node* ptr = nullptr;
        };

    public:
        class const_iterator : public base_iterator
        {
            friend LinkedList;
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

    public:
        class iterator : public const_iterator
        {
            friend LinkedList;
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

    public:
        LinkedList();
        LinkedList(const LinkedList& obj);
        LinkedList(LinkedList&& rhv); 
        LinkedList(size_type size); 
        LinkedList(size_type size, const_reference init); 
        LinkedList(std::initializer_list<value_type> init); 
        LinkedList(iterator f, iterator l); 
        ~LinkedList();

    public:
        const LinkedList& operator=(const LinkedList& rhv); 
        const LinkedList& operator=(LinkedList&& rhv); 
        const LinkedList& operator=(std::initializer_list<value_type> init);

        bool operator==(const LinkedList& rhv) const; 
        bool operator!=(const LinkedList& rhv) const; 
        bool operator<(const LinkedList& rhv) const; 
        bool operator<=(const LinkedList& rhv) const;
        bool operator>(const LinkedList& rhv) const; 
        bool operator>=(const LinkedList& rhv) const;

        void swap(LinkedList& rhv);
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
#endif
