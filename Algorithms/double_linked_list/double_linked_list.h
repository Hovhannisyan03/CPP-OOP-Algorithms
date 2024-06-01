#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>

    
class double_linked_list
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
            Node* m_prev;
            Node* m_next;
            value_type m_data;
            Node(value_type data);
            Node();
        };  

    private:
        class base_iterator
        {
            friend double_linked_list;
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
            friend double_linked_list;
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

    public:
        class iterator : public const_iterator
        {
            friend double_linked_list;
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
        class const_reverse_iterator : public base_iterator
        {
            friend double_linked_list;
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

    public:
        class reverse_iterator : public const_reverse_iterator
        {
            friend double_linked_list;
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

    public:
        double_linked_list();
        double_linked_list(const double_linked_list& rhv);
        double_linked_list(double_linked_list&& rhv)noexcept;
        double_linked_list(size_type size);
        double_linked_list(size_type size, const_reference init);
        double_linked_list(std::initializer_list<value_type> init); 
        double_linked_list(iterator f, iterator l); 
        ~double_linked_list();

    public:
        void swap(double_linked_list& rhv);
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

        const double_linked_list& operator=(const double_linked_list& rhv); 
        const double_linked_list& operator=(double_linked_list&& rhv); 
        const double_linked_list& operator=(std::initializer_list<value_type> init);

        bool operator==(const double_linked_list& rhv) const; 
        bool operator!=(const double_linked_list& rhv) const; 
        bool operator<(const double_linked_list& rhv) const; 
        bool operator<=(const double_linked_list& rhv) const;
        bool operator>(const double_linked_list& rhv) const; 
        bool operator>=(const double_linked_list& rhv) const; 

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

        iterator find(const_reference elem);
        iterator rfind(const_reference elem);

    private:
        bool is_valid_iterator(iterator pos);
        Node* m_head;
        Node* m_tail;
};

#endif