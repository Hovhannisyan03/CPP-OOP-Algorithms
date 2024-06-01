#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

#include <iostream>

namespace vhuk 
{
class FrankList
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
        value_type m_data;
        Node* m_next;
        Node* m_prev;
        Node* m_greater;
        Node* m_lesser;
        Node();
        Node(value_type val);
    };
    private:
        class base_iterator
        {
            friend FrankList;
        public:
            ~base_iterator(){};
            bool operator==(const base_iterator& rhv) const; //O(1)
            bool operator!=(const base_iterator& rhv) const; //O(1)
        protected:
            explicit base_iterator(Node* ptr); //O(1)
        protected:
            Node* ptr = nullptr;
        };
    public:
        class const_iterator : public base_iterator
        {
            friend FrankList;
        public:
            const_iterator(const base_iterator& rhv); //O(1)
            const_iterator(base_iterator&& rhv); //O(1)
            
            const const_iterator& operator=(const base_iterator& rhv); //O(1)
            const const_iterator& operator=(base_iterator&& rhv); //O(1)
            const_reference operator*() const; //O(1)
            const_pointer operator->() const; //O(1)

            const const_iterator& operator++(); //O(1)
            const const_iterator operator++(value_type); //O(1)
            const const_iterator& operator--(); //O(1)
            const const_iterator operator--(value_type); //O(1)

        protected:
            explicit const_iterator(Node* ptr); //O(1)
        };

    public:
        class iterator : public const_iterator
        {
            friend FrankList;
        public:
            iterator(const base_iterator& rhv); //O(1)
            iterator(base_iterator&& rhv); //O(1)

            reference operator*(); //O(1)
            pointer operator->(); //O(1)

            const iterator& operator=(const base_iterator& rhv); //O(1)
            const iterator& operator=(base_iterator&& rhv); //O(1)
        protected:
            explicit iterator(Node* ptr); //O(1)
        };

public:
    class const_reverse_iterator : public base_iterator
    {
        friend FrankList;
    public:
        const_reverse_iterator(const base_iterator& rhv); //O(1)
        const_reverse_iterator(base_iterator&& rhv); //O(1)
        
        const const_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        const_reference operator*() const; //O(1)
        const_pointer operator->() const; //O(1)

        const const_reverse_iterator& operator++(); //O(1)
        const const_reverse_iterator operator++(value_type); //O(1)
        const const_reverse_iterator& operator--(); //O(1)
        const const_reverse_iterator operator--(value_type); //O(1)

    protected:
        explicit const_reverse_iterator(Node* ptr); //O(1)
    };
public:
    class reverse_iterator : public const_reverse_iterator
    {
        friend FrankList;
    public:
        reverse_iterator(const base_iterator& rhv); //O(1)
        reverse_iterator(base_iterator&& rhv); //O(1)

        reference operator*(); //O(1)
        pointer operator->(); //O(1)

        const reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit reverse_iterator(Node* ptr); //O(1)
    };
public:
    class const_asc_iterator :public base_iterator
    {
        friend FrankList;
    public:
        const_asc_iterator(const base_iterator& rhv); //O(1)
        const_asc_iterator(base_iterator&& rhv); //O(1)
        
        const const_asc_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_asc_iterator& operator=(base_iterator&& rhv); //O(1)
        const_reference operator*() const; //O(1)
        const_pointer operator->() const; //O(1)

        const const_asc_iterator& operator++(); //O(1)
        const const_asc_iterator operator++(value_type); //O(1)
        const const_asc_iterator& operator--(); //O(1)
        const const_asc_iterator operator--(value_type); //O(1)

    protected:
        explicit const_asc_iterator(Node* ptr); //O(1)
    };
public:
    class asc_iterator : public const_asc_iterator
    {
        friend FrankList;
    public:
        asc_iterator(const base_iterator& rhv); //O(1)
        asc_iterator(base_iterator&& rhv); //O(1)

        reference operator*(); //O(1)
        pointer operator->(); //O(1)

        const asc_iterator& operator=(const base_iterator& rhv); //O(1)
        const asc_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit asc_iterator(Node* ptr); //O(1)
    };
public:
    class const_desc_iterator : public base_iterator
    {
        friend FrankList;
    public:
        const_desc_iterator(const base_iterator& rhv); //O(1)
        const_desc_iterator(base_iterator&& rhv); //O(1)
        
        const const_desc_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_desc_iterator& operator=(base_iterator&& rhv); //O(1)
        const_reference operator*() const; //O(1)
        const_pointer operator->() const; //O(1)

        const const_desc_iterator& operator++(); //O(1)
        const const_desc_iterator operator++(value_type); //O(1)
        const const_desc_iterator& operator--(); //O(1)
        const const_desc_iterator operator--(value_type); //O(1)

    protected:
        explicit const_desc_iterator(Node* ptr); //O(1)
    };
public:
    class desc_iterator : public const_desc_iterator
    {
        friend FrankList;
    public:
        desc_iterator(const base_iterator& rhv); //O(1)
        desc_iterator(base_iterator&& rhv); //O(1)

        reference operator*(); //O(1)
        pointer operator->(); //O(1)

        const desc_iterator& operator=(const base_iterator& rhv); //O(1)
        const desc_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit desc_iterator(Node* ptr); //O(1)
    };
public:
    class const_multi_iterator : public base_iterator
    {
        friend FrankList;
    public:
        const_multi_iterator(const base_iterator& rhv); //O(1)
        const_multi_iterator(base_iterator&& rhv); //O(1)
        
        const const_multi_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_multi_iterator& operator=(base_iterator&& rhv); //O(1)
        const_reference operator*() const; //O(1)
        const_pointer operator->() const; //O(1)

        const const_multi_iterator& operator++(); //O(1)
        const const_multi_iterator operator++(value_type); //O(1)
        const const_multi_iterator& operator--(); //O(1)
        const const_multi_iterator operator--(value_type); //O(1)
        void chmod(); //O(1)
    protected:
        explicit const_multi_iterator(Node* ptr); //O(1)
        bool mode = true;
    };
public:
    class multi_iterator : public const_multi_iterator
    {
        friend FrankList;
    public:
        multi_iterator(const base_iterator& rhv); //O(1)
        multi_iterator(base_iterator&& rhv); //O(1)

        reference operator*(); //O(1)
        pointer operator->(); //O(1)

        const multi_iterator& operator=(const base_iterator& rhv); //O(1)
        const multi_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit multi_iterator(Node* ptr); //O(1)
    };
public:
    class const_multi_reverse_iterator : public base_iterator
    {
        friend FrankList;
    public:
        const_multi_reverse_iterator(const base_iterator& rhv); //O(1)
        const_multi_reverse_iterator(base_iterator&& rhv); //O(1)
        
        const const_multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        const_reference operator*() const; //O(1)
        const_pointer operator->() const; //O(1)

        const const_multi_reverse_iterator& operator++(); //O(1)
        const const_multi_reverse_iterator operator++(value_type); //O(1)
        const const_multi_reverse_iterator& operator--(); //O(1)
        const const_multi_reverse_iterator operator--(value_type); //O(1)

        void chmod(); //O(1)
    protected:
        explicit const_multi_reverse_iterator(Node* ptr); //O(1)
        bool mode = true;
    };
public:
    class multi_reverse_iterator : public const_multi_reverse_iterator
    {
        friend FrankList;
    public:
        multi_reverse_iterator(const base_iterator& rhv); //O(1)
        multi_reverse_iterator(base_iterator&& rhv); //O(1)

        reference operator*(); //O(1)
        pointer operator->(); //O(1)

        const multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
    protected:
        explicit multi_reverse_iterator(Node* ptr); //O(1)
    };

public:
    FrankList(); //O(1)
    FrankList(size_type size); //O(n)
    FrankList(size_type size, const_reference init); //O(n)
    FrankList(const FrankList& rhv); //O(n)
    FrankList(FrankList&& rhv); //O(1)
    FrankList(std::initializer_list<value_type> init); //O(n)
    FrankList(iterator f, iterator l); //O(n)
    ~FrankList();

public:
    void swap(FrankList& rhv); //O(1)

    size_t size() const; //O(n)
    void display(bool sorted = false, bool reversed = false);
    bool empty() const; //O(1)
    void resize(size_type s, const_reference init = value_type()); //O(n)
    void clear() noexcept; //O(n)

    void push_front(const_reference elem); //~O(1)
    void pop_front(); //O(1)
    void push_back(const_reference elem); //~O(1)
    void pop_back(); //O(1)

    const_reference front() const; //O(1)
    reference front(); //O(1)
    const_reference back() const; //O(1)
    reference back(); //O(1)
    const_reference min() const; //O(1)
    reference min(); //O(1)
    const_reference max() const; //O(1)
    reference max(); //O(1)

    const FrankList& operator=(const FrankList& rhv); //O(n)
    const FrankList& operator=(FrankList&& rhv); //O(n)
    const FrankList& operator=(std::initializer_list<value_type> init); //O(n)

    bool operator==(const FrankList& rhv) const; //O(n)
    bool operator!=(const FrankList& rhv) const; //O(n)
    bool operator<(const FrankList& rhv) const; //O(n)
    bool operator<=(const FrankList& rhv) const; //O(n)
    bool operator>(const FrankList& rhv) const; //O(n)
    bool operator>=(const FrankList& rhv) const; //O(n)

public:
    const_iterator cbegin() const; //O(1)
    const_iterator cend() const; //O(1)
    const_reverse_iterator crbegin() const; //O(1)
    const_reverse_iterator crend() const; //O(1)
    const_asc_iterator cabegin() const; //O(1)
    const_asc_iterator caend() const; //O(1)
    const_desc_iterator cdbegin() const; //O(1)
    const_desc_iterator cdend() const; //O(1)
    const_multi_iterator cmbegin() const; //O(1)
    const_multi_iterator cmend() const; //O(1)
    const_multi_iterator cmabegin() const; //O(1)
    const_multi_iterator cmaend() const; //O(1)
    const_multi_reverse_iterator cmrbegin() const; //O(1)
    const_multi_reverse_iterator cmrend() const; //O(1)
    const_multi_reverse_iterator cmrdbegin() const; //O(1)
    const_multi_reverse_iterator cmrdend() const; //O(1)

    iterator begin(); //O(1)
    iterator end(); //O(1)
    reverse_iterator rbegin(); //O(1)
    reverse_iterator rend(); //O(1)
    asc_iterator abegin(); //O(1)
    asc_iterator aend(); //O(1)
    desc_iterator dbegin(); //O(1)
    desc_iterator dend(); //O(1)
    multi_iterator mbegin(); //O(1)
    multi_iterator mend(); //O(1)
    multi_iterator mabegin(); //O(1)
    multi_iterator maend(); //O(1)
    multi_reverse_iterator mrbegin(); //O(1)
    multi_reverse_iterator mrend(); //O(1)
    multi_reverse_iterator mrdbegin(); //O(1)
    multi_reverse_iterator mrdend(); //O(1)

public:
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_iterator, iter>::value ||
                              std::is_base_of<const_asc_iterator, iter>::value ||
                              std::is_base_of<const_multi_iterator, iter>::value, 
             iter>::type
    insert(iter pos, const_reference val) { //O(1)
        return insert_def(pos, val);
    }
    
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_reverse_iterator, iter>::value ||
                              std::is_base_of<const_desc_iterator, iter>::value ||
                              std::is_base_of<const_multi_reverse_iterator, iter>::value,
             iter>::type
    insert(iter pos, const_reference val) { //O(1)
        return insert_rev(pos, val);
    } 
    iterator insert(iterator pos, size_type size, const_reference val); //O(n)
    iterator insert(iterator pos, std::initializer_list<value_type> init); //O(n)
    iterator insert(iterator pos, iterator f, iterator l); //O(n)

    iterator erase(iterator pos); //O(1)
    iterator erase(iterator f, iterator l); //O(n)
    class isOdd
    {
        public:
            bool operator()(const_reference val);
    };
    size_type remove(const_reference val); //O(n)
    size_type remove_if(isOdd func); //O(n)
    void reverse(); //O(n)
    void sort(bool reversed = false); //O(n)

    iterator find(const_reference elem); //O(n)
    iterator rfind(const_reference elem); //O(n)
    void traverse(void (*addPtr)(pointer val), bool sorted = false, bool reversed = false); //O(n)
    void addOne(pointer val);
protected:
    void put_in_sorted_order(Node* ptr);
    void re_sort(Node* del);
    void organize_left(Node* ptr); //O(1)
    void organize_right(Node* ptr); //O(1)
public:
    iterator insert_def(iterator pos, const_reference val); //O(1)
    
    iterator insert_rev(iterator pos, const_reference val); //O(1)

private:
    Node* m_head;
    Node* m_tail;
    Node* m_asc;
    Node* m_desc;
};

}

#endif // _FRANKLIST_HPP__