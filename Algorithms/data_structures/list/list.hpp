#include "list.h"

template <typename T>
list<T>::Node::Node(value_type data) : m_data{data}, m_prev{nullptr}, m_next{nullptr} {}

template <typename T>
list<T>::Node::Node() : m_data{0}, m_prev{nullptr}, m_next{nullptr} {}

template <typename T>
list<T>::list() : m_head{nullptr}, m_tail{nullptr} {}

template <typename T>
list<T>::list(list&& rhv) noexcept : m_head{rhv.m_head}, m_tail{rhv.m_tail}
{
    rhv.m_head = nullptr;
    rhv.m_tail = nullptr;
}

template <typename T>
list<T>::list(const list& rhv) : m_head{nullptr}, m_tail{nullptr}
{
    if(!rhv.m_head || !rhv.m_head->m_next)
    {
        m_head = rhv.m_head;
        m_tail = rhv.m_tail;
        return;
    }

    m_head = new Node(rhv.m_head->m_data);
    Node* curr = rhv.m_head->m_next;
    Node* this_curr = m_head;
    while (curr) 
    {
        this_curr->m_next = new Node(curr->m_data);
        this_curr->m_next->m_prev = this_curr;
        this_curr = this_curr->m_next;
        curr = curr->m_next;
    }
    m_tail = this_curr;
}

template <typename T>
list<T>::list(size_type size, const_reference init) : m_head{nullptr}, m_tail{nullptr}
{
    if(size != 0)
    {
        m_head = new Node(init);
        Node* this_curr = m_head;
        for(size_type i = 1; i < size; ++i)
        {
            this_curr->m_next = new Node(init);
            this_curr->m_next->m_prev = this_curr;
            this_curr= this_curr->m_next;    
        }
        m_tail = this_curr;
    }
}

template <typename T>
list<T>::list(size_type size) : list(size,0) {}

template <typename T>
list<T>::list(std::initializer_list<value_type> init) : m_head{nullptr}, m_tail{nullptr}
{
    if(init.size() != 0)
    {
        Node* this_curr = nullptr;
        bool first = true;
        for(auto &elem : init)
        {
            if(first)
            {
                m_head = new Node(elem);
                this_curr = m_head;
                first = false;
            }
            else
            {
                this_curr->m_next = new Node(elem);
                this_curr->m_next->m_prev = this_curr;
                this_curr = this_curr->m_next;    
            } 
        }
        m_tail = this_curr;
    }
}

template <typename T>
list<T>::list(iterator f, iterator e) : m_head{nullptr}, m_tail{nullptr}
{
    if (f == e) 
    {
        return; 
    }

    m_head = new Node(*f); 
    Node* curr = m_head;   
    ++f;
    while(f != e) 
    {
        curr->m_next = new Node(*f); 
        curr->m_next->m_prev = curr; 
        curr = curr->m_next;    
        ++f;     
    }

    m_tail = curr;
}

template <typename T>
list<T>::~list()
{
    clear();
}

template <typename T>
const list<T>& list<T>::operator=(const list& rhv)
{
    if(this == &rhv)
    {
        return *this;
    }

    clear();
    for(const_iterator it = rhv.cbegin(); it != rhv.cend(); ++it)
    {
        push_back(*it);
    }
    return *this;
} 

template <typename T>
const list<T>& list<T>::operator=(list&& rhv)
{
    if(this == &rhv)
    {
        return *this;
    }

    m_head = rhv.m_head;
    m_tail = rhv.m_tail;
    rhv.m_head = nullptr;
    rhv.m_tail = nullptr;
    return *this;
}

template <typename T>
const list<T>& list<T>::operator=(std::initializer_list<value_type> init)
{
    clear();
    for(auto& elem : init)
    {
        push_back(elem);
    }
    return *this;
}

template <typename T>
bool list<T>::operator==(const list& rhv) const
{
    if(size() != rhv.size())
    {
        return false;
    }

    Node* curr1 = m_head;
    Node* curr2 = rhv.m_head;

    while(curr1 && curr2)
    {
        if(curr1->m_data != curr2->m_data)
        {   
            return false;
        }
        curr1 = curr1->m_next;
        curr2 = curr2->m_next;
    }
    return true;
}

template <typename T>
bool list<T>::operator!=(const list& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool list<T>::operator<(const list& rhv) const
{
    Node* curr1 = m_head;
    Node* curr2 = rhv.m_head;
    while(curr1 && curr2)
    {                                        
        if(curr1->m_data < curr2->m_data)
        {
            return true;
        }
        else if(curr1->m_data > curr2->m_data)
        {
            return false;
        }
        curr1 = curr1->m_next;
        curr2 = curr2->m_next;
    }  

    return (curr1 == nullptr && curr2 != nullptr);
}

template <typename T>
bool list<T>::operator<=(const list& rhv) const
{
   return (*this < rhv) || (*this == rhv);
}

template <typename T>
bool list<T>::operator>(const list& rhv) const
{
    return !(*this <= rhv);
}

template <typename T>
bool list<T>::operator>=(const list& rhv) const
{
    return !(*this < rhv);

}

template <typename T>
void list<T>::swap(list& rhv)
{
    Node* tmp_head = rhv.m_head;
    Node* tmp_tail = rhv.m_tail;
    rhv.m_head = m_head;
    rhv.m_tail = m_tail;
    m_head = tmp_head;
    m_tail = tmp_tail;
}

template <typename T>
void list<T>::display(bool head)
{
    if(head)
    {
        for(const_iterator it = cbegin(); it != cend(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    else 
    {
        for(const_reverse_iterator it = crbegin(); it != crend(); ++it)
        {
            std::cout << *it << " ";
        }
    }
}

template <typename T>
bool list<T>::empty()
{
    return m_head == nullptr;
}

template <typename T>
void list<T>::push_back(const_reference val)
{
    Node* newNode = new Node(val);
    if(!m_head)
    {   
        m_head = newNode;
        m_tail = newNode;
        return;
    }
    
    newNode->m_prev = m_tail;
    m_tail->m_next = newNode;
    m_tail = newNode;
}

template <typename T>
void list<T>::push_front(const_reference val)
{
    Node* newNode = new Node(val);
    if(!m_head)
    {   
        m_head = newNode;
        m_tail = newNode;
        return;
    }
    
    newNode->m_next = m_head;
    m_head->m_prev = newNode;
    m_head = newNode;
}

template <typename T>
void list<T>::pop_back()
{
    if(!m_tail)
    {
        return;
    }
    Node* del = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = nullptr;
    delete del;
}

template <typename T>
void list<T>::pop_front()
{
    if(!m_head)
    {
        return;
    }
    Node* del = m_head;
    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
    delete del;
}

template <typename T>
void list<T>::clear() noexcept
{
    if(!m_head)
    {
        return;
    }
    if(!m_head->m_next)
    {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        return;
    }
    Node* curr = m_head;
    while(curr)
    {   
        Node* del = curr;
        curr =  curr->m_next;
        delete del;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

template <typename T>
typename list<T>::const_reference list<T>::front() const
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");   

}

template <typename T>
typename list<T>::reference list<T>::front()
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");    
}

template <typename T>
typename list<T>::const_reference list<T>::back() const
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::logic_error("List is empty");   
}

template <typename T>
typename list<T>::reference list<T>::back()
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::logic_error("List is empty");    
}

template <typename T>
typename list<T>::const_reference list<T>::min() const
{
    if(m_head)
    {
        Node* max = m_head;
        Node* curr = m_head->m_next;
        while(curr)
        {
            if(curr->m_data > max->m_data)
            {
                max = curr;
            }
        }
        return max->m_data;
    }
    throw std::logic_error("List is empty");   
}

template <typename T>
typename list<T>::reference list<T>::min() 
{
    if(m_head)
    {
        Node* max = m_head;
        Node* curr = m_head->m_next;
        while(curr)
        {
            if(curr->m_data > max->m_data)
            {
                max = curr;
            }
        }
        return max->m_data;
    }
    throw std::logic_error("List is empty");   
}

template <typename T>
typename list<T>::const_reference list<T>::max() const
{
    if(m_head)
    {
        Node* min = m_head;
        Node* curr = m_head->m_next;
        while(curr)
        {
            if(curr->m_data < min->m_data)
            {
                min = curr;
            }
        }
        return min->m_data;
    }
    throw std::logic_error("List is empty");   
}

template <typename T>
typename list<T>::reference list<T>::max()
{
    if(m_head)
    {
        Node* min = m_head;
        Node* curr = m_head->m_next;
        while(curr)
        {
            if(curr->m_data < min->m_data)
            {
                min = curr;
            }
        }
        return min->m_data;
    }
    throw std::logic_error("List is empty");   
}

template <typename T>
typename list<T>::iterator list<T>::find(const_reference elem)
{
    for(iterator it = begin(); it != end(); ++it)
    {
        if(*it == elem)
        {
            return it;
        }
    }
    return iterator(nullptr);
}

template <typename T>
void list<T>::reverse()
{
    if (!m_head || !m_head->m_next) 
    {
        return;
    }

    Node* curr = m_head;
    Node* prev = nullptr;

    while (curr) 
    {
        Node* next = curr->m_next;
        curr->m_next = prev;       
        curr->m_prev = next;       
        prev = curr;               
        curr = next;               
    }

    m_tail = m_head;
    m_head = prev;
}

template <typename T>
void list<T>::sort()
{
    if (!m_head || !m_head->m_next) 
    {
        return;
    }
    Node* sorted_head = nullptr;
    Node* sorted_tail = nullptr;
    Node* temp = m_head;
    while(temp)
    {   
        Node* next = temp->m_next;
        if(!sorted_head || sorted_head->m_data >= temp->m_data)
        {
            temp->m_next = sorted_head;
            if (sorted_head) 
            {
                sorted_head->m_prev = temp;
            }
            sorted_head = temp;
            temp->m_prev = nullptr;
            if (!sorted_tail) 
            {
                sorted_tail = temp; 
            }
        }
        else if(sorted_tail->m_data <= temp->m_data)
        {
            temp->m_next = nullptr;
            temp->m_prev = sorted_tail;
            sorted_tail->m_next = temp;
            sorted_tail = temp;
        }
        else
        {
            Node* temp2 = sorted_head;
            while(temp2->m_next && temp2->m_next->m_data < temp->m_data)
            {
                temp2 = temp2->m_next;
            }
            temp->m_next = temp2->m_next;
            temp->m_prev = temp2;
            if (temp2->m_next) 
            {
                temp2->m_next->m_prev = temp;
            }
            temp2->m_next = temp;
        }
        temp = next;
    }
    m_head = sorted_head;
    m_tail = sorted_tail;
}

template <typename T>
void list<T>::unique()
{
    if(!m_head)
    {
        return;
    }
    Node* curr = m_head;
    while(curr)
    {
        if(curr == m_head)
        {
            curr = curr->m_next;
            continue;
        }
        Node* unique_temp = m_head;
        size_type flag = false;
        while(unique_temp != curr)
        {
            if(curr->m_data == unique_temp->m_data)
            {
                Node* del = curr;
                curr->m_prev->m_next = curr->m_next;
                if(curr->m_next)
                {
                    curr->m_next->m_prev = curr->m_prev;
                    m_tail = curr->m_prev;
                }
                curr = curr->m_next;
                flag  = true;
                delete del;
                break;
            }
            unique_temp = unique_temp->m_next;
        }
        if(!flag)
        {
            curr = curr->m_next;
        }
    }
    if(m_tail)
    {
        m_tail->m_next = nullptr;
    }
}

template <typename T>
void list<T>::print(bool reverse ) const
{
    if(!reverse)
    {   
        Node* curr = m_head;
        while(curr)
        {
            std::cout << curr->m_data << " ";
            curr = curr->m_next;
        }
    }
    else
    {
        Node* curr = m_tail;
        while(curr)
        {
            std::cout << curr->m_data << " ";
            curr = curr->m_prev;
        }
    }
    
    std::cout << std::endl;
}

template <typename T>
void list<T>::merge(list& other)
{
    if (this == &other) 
    {
        return;
    }

    if (!other.m_head) 
    {
        return;
    }

    if (!m_head) 
    {
        m_head = other.m_head;
        m_tail = other.m_tail; 
    }
    else
    {
        m_tail->m_next = other.m_head;
        other.m_head->m_prev = m_tail;
        m_tail = other.m_tail;
    }        
    other.m_head = nullptr;
    other.m_tail = nullptr;
}


template <typename T>
typename list<T>::size_type list<T>::size() const
{
    size_type size_ = 0;
    const_iterator it = cbegin();
    while(it != cend())
    {
        ++size_;
        ++it;
    }
    return size_;
}

template <typename T>
typename list<T>::iterator list<T>::rfind(const_reference elem)
{
    for(reverse_iterator it = rbegin(); it != rend(); ++it)
    {
        if(*it == elem)
        {
            return it;
        }
    }
    return reverse_iterator(nullptr);
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos, value_type val)
{
    if(!is_valid_iterator(pos))
    {
        throw std::logic_error("Invalid iterator");
    }
    Node* new_node = new Node(val);

    if (pos == begin()) 
    {
        new_node->m_next = m_head;
        if (m_head != nullptr) 
        {
            m_head->m_prev = new_node;
        }
        m_head = new_node;
    } 
    else if (pos == end()) 
    {
        new_node->m_prev = m_tail;
        if (m_tail != nullptr) 
        {
            m_tail->m_next = new_node;
        }
        m_tail = new_node;
    } 
    else 
    {
        Node* before_pos = pos.ptr->m_prev;
        new_node->m_next = pos.ptr;
        new_node->m_prev = before_pos;
        before_pos->m_next = new_node;
        pos.ptr->m_prev = new_node;
    }

    return iterator(new_node);
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos, size_type size, const_reference val)
{
    for (size_type i = 0; i < size; ++i) 
    {
        pos = insert(pos, val); 
    }
    return pos; 
} 

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos, std::initializer_list<value_type> init)
{
    for(auto& elem : init)
    {
        pos = insert(pos,elem);
    }
    return pos;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos, iterator f, iterator l)
{
    while(f != l)
    {
        pos = insert(pos, *f);
        ++f;
    }
    return pos;
}

template <typename T>
typename list<T>::iterator list<T>::insert_def(iterator pos, const_reference val)
{
    insert(pos,val);
    return pos;
}

template <typename T>
typename list<T>::iterator list<T>::insert_rev(iterator pos, const_reference val)
{
    return insert(pos,val);
}

template <typename T>
void list<T>::resize(size_type s, const_reference init)
{
    size_type s1 = size(); 
    if(s1 >= s)
    {
        return;
    }  
    else 
    {
        while(s1 < s)
        {
            push_back(init);
            --s;
        }
    }
}

template <typename T>
typename list<T>::iterator list<T>::erase(iterator pos)
{
    if(!is_valid_iterator(pos))
    {
        throw std::logic_error("Invalid iterator");
    }
    if (pos == end()) 
    {
        return end();
    }

    Node* del = pos.ptr;

    if (del == m_head) 
    {
        m_head = del->m_next;
    } 
    else 
    {
        del->m_prev->m_next = del->m_next;
    }

    if (del == m_tail) 
    {
        m_tail = del->m_prev;
    } else 
    {
        del->m_next->m_prev = del->m_prev;
    }

    iterator next_pos(del->m_next);
    delete del;
    return next_pos;
}

template <typename T>
typename list<T>::iterator list<T>::erase(iterator f, iterator l)
{
    if(!is_valid_iterator(f) || !is_valid_iterator(l))
    {
        throw std::logic_error("Invalid iterator");
    }
    
    while(f != l)
    {
        f = erase(f);
    }
    return iterator(l.ptr);
}

template <typename T>
typename list<T>::size_type list<T>::remove(const_reference val)
{
    Node* curr = m_head;
    size_type index = 0;

    while (curr) {
        if (curr->m_data == val) 
        {
            if (curr == m_head) 
            {
                pop_front();
            } 
            else if (curr == m_tail) 
            {
                pop_back();
                return size(); 
            } 
            else 
            {
                curr->m_prev->m_next = curr->m_next;
                curr->m_next->m_prev = curr->m_prev;
                delete curr;
            }
            return index; 
        }
        curr = curr->m_next;
        ++index;
    }
    return -1;
}

template <typename T>
bool list<T>::is_valid_iterator(iterator pos)
{
    Node* current = m_head;
    while (current != nullptr) 
    {
        if (current == pos.ptr) 
        {
            return true; 
        }
        current = current->m_next;
    }
    return false; 
}
// =================================================== Base Iterator ==============================================================

template <typename T>
list<T>::base_iterator::base_iterator(Node* ptr) : ptr(ptr){}

template <typename T>
bool list<T>::base_iterator::operator==(const base_iterator& rhv) const
{
    return rhv.ptr == this->ptr;
}

template <typename T>
bool list<T>::base_iterator::operator!=(const base_iterator& rhv) const
{
    return rhv.ptr != this->ptr;
}

// =================================================== Const Iterator ==============================================================

template <typename T>
list<T>::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator{rhv.ptr} {}

template <typename T>
list<T>::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator{rhv.ptr} {}

template <typename T>
list<T>::const_iterator::const_iterator(Node* ptr) : base_iterator{ptr} {}

template <typename T>
const typename list<T>::const_iterator& list<T>::const_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename list<T>::const_iterator& list<T>::const_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::const_iterator::operator*() const
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return this->ptr->m_data;
}

template <typename T>
typename list<T>::const_pointer list<T>::const_iterator::operator->() const
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &this->ptr->m_data;
}

template <typename T>
const typename list<T>::const_iterator& list<T>::const_iterator::operator++()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    this->ptr = this->ptr->m_next;
    return *this;
} 


template <typename T>
const typename list<T>::const_iterator list<T>::const_iterator::operator++(value_type)
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename list<T>::const_iterator& list<T>::const_iterator::operator--()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    this->ptr = this->ptr->m_prev;
    return *this;
} 

template <typename T>
const typename list<T>::const_iterator list<T>::const_iterator::operator--(value_type)
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    const_iterator tmp = *this;
    --(*this);
    return tmp;
} 

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{
    return const_iterator(m_head);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const 
{
    return const_iterator(nullptr);
}
// =================================================== Iterator ==============================================================

template <typename T>
list<T>::iterator::iterator(const base_iterator& rhv) : const_iterator{rhv.ptr} {}

template <typename T>
list<T>::iterator::iterator(base_iterator&& rhv) : const_iterator{rhv.ptr} {}

template <typename T>
list<T>::iterator::iterator(Node* ptr) : const_iterator{ptr} {}

template <typename T>
const typename list<T>::iterator& list<T>::iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename list<T>::iterator& list<T>::iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
typename list<T>::reference list<T>::iterator::operator*()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return this->ptr->m_data;
}

template <typename T>
typename list<T>::pointer list<T>::iterator::operator->()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &this->ptr->m_data;
}

template <typename T>
typename list<T>::iterator list<T>::begin()
{
    return iterator(m_head);
}

template <typename T>
typename list<T>::iterator list<T>::end()
{
    return iterator(nullptr);
}

// =================================================== Const Reverse Iterator ==============================================================

template <typename T>
list<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr){}

template <typename T>
list<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr){}

template <typename T>
list<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr) : base_iterator(ptr){}

template <typename T>
const typename list<T>::const_reverse_iterator& list<T>::const_reverse_iterator::operator=(const base_iterator& rhv) 
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename list<T>::const_reverse_iterator& list<T>::const_reverse_iterator::operator=(base_iterator&& rhv) 
{
    this->ptr = this->rhv.ptr;
    return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::const_reverse_iterator::operator*() const
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");

    }
    return this->ptr->m_data;
}

template <typename T>
typename list<T>::const_pointer list<T>::const_reverse_iterator::operator->() const
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &(this->ptr->m_data);
}

template <typename T>
const typename list<T>::const_reverse_iterator& list<T>::const_reverse_iterator::operator++()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");

    }
    this->ptr = this->ptr->m_prev;
    return *this;
}

template <typename T>
const typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator++(value_type)
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename list<T>::const_reverse_iterator& list<T>::const_reverse_iterator::operator--()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");

    }
    this->ptr = this->ptr->m_next;
    return *this;
}

template <typename T>
const typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator--(value_type)
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
typename list<T>::const_reverse_iterator list<T>::crbegin() const
{
    return const_reverse_iterator(m_tail);
}

template <typename T>
typename list<T>::const_reverse_iterator list<T>::crend() const
{
    return const_reverse_iterator(nullptr);
}

// =================================================== Reverse Iterator ==============================================================

template <typename T>
list<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv.ptr){}

template <typename T>
list<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(rhv.ptr){}

template <typename T>
list<T>::reverse_iterator::reverse_iterator(Node* ptr) : const_reverse_iterator(ptr){}

template <typename T>
const typename list<T>::reverse_iterator& list<T>::reverse_iterator::operator=(const base_iterator& rhv) 
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename list<T>::reverse_iterator& list<T>::reverse_iterator::operator=(base_iterator&& rhv) 
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
typename list<T>::reference list<T>::reverse_iterator::operator*()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");

    }
    return this->ptr->m_data;
}

template <typename T>
typename list<T>::pointer list<T>::reverse_iterator::operator->()
{
    if(!this->ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &(this->ptr->m_data);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rbegin()
{
    return reverse_iterator(m_tail);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rend()
{
    return reverse_iterator(nullptr);
}
