#include "forward_list.h"

template <typename T>
forward_list<T>::Node::Node(value_type data) : m_data{data}, m_next{nullptr}{}

template <typename T>
forward_list<T>::Node::Node() : m_next{nullptr} {}

template <typename T>
forward_list<T>::forward_list() : m_head{nullptr} {}

template <typename T>
forward_list<T>::~forward_list()
{
    clear();
}

template <typename T>
forward_list<T>::forward_list(const forward_list& rhv)
{
    if(!rhv.m_head)
    {
        m_head = nullptr;
        return;
    }

    m_head = new Node(rhv.m_head->m_data);
    Node* curr = rhv.m_head->m_next;
    Node* this_curr = m_head;
    while (curr) 
    {
        Node* newNode = new Node(curr->m_data);    
        this_curr->m_next = newNode;
        this_curr = this_curr->m_next;
        curr = curr->m_next;
    }
}

template <typename T>
forward_list<T>::forward_list(forward_list&& rhv) : m_head{rhv.m_head}
{
    rhv.m_head = nullptr;
}

template <typename T>
forward_list<T>::forward_list(size_type size) : forward_list(size,0) {}

template <typename T>
forward_list<T>::forward_list(size_type size, const_reference init)
{   
    if(size == 0)
    {
        return;
    }
    m_head = new Node(init);
    Node* curr = m_head;
    while(--size)
    {
        curr->m_next = new Node(init);
        curr = curr->m_next;
    }
}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<value_type> init)
{
    if(init.size() == 0)
    {
        return;
    }

    Node* curr = m_head;
    bool first = true;
    for(auto& elem : init)
    {
        if(first)
        {
            m_head = new Node(elem);
            curr = m_head;
            first = false;
        }
        else
        {
            curr->m_next = new Node(elem);
            curr = curr->m_next;
        }
    }
} 

template <typename T>
template <typename U>
forward_list<T>::forward_list(U f, U l)
{
    m_head = new Node(*f);
    ++f;
    Node* curr = m_head;
    while(f != l)
    {   
        curr->m_next = new Node(*f);
        curr = curr->m_next;
        ++f;
    }
} 

template <typename T>
const forward_list<T>& forward_list<T>::operator=(const forward_list& rhv)
{
    if(&rhv == this)
    {
        return *this;
    }
    clear();

    Node* curr = rhv.m_head;
    Node* this_curr = nullptr;
    while(curr)
    {
        if(!m_head)
        {
            m_head = new Node(curr->m_data);
            this_curr = m_head;
        }
        else
        {
            this_curr->m_next = new Node(curr->m_data);
            this_curr = this_curr->m_next;
        }
        curr = curr->m_next;
    }
    return *this;
}

template <typename T>
const forward_list<T>& forward_list<T>::operator=(forward_list&& rhv)
{
    if(&rhv == this)
    {
        return *this;
    }

    m_head = rhv.m_head;
    rhv.m_head = nullptr;
    return *this;
}

template <typename T>
const forward_list<T>& forward_list<T>::operator=(std::initializer_list<value_type> init)
{
    clear();
    
    Node* curr = m_head;
    bool first = true;
    for(auto& elem : init)
    {
        if(first)
        {
            m_head = new Node(elem);
            curr = m_head;
            first = false;
        }
        else
        {
            curr->m_next = new Node(elem);
            curr = curr->m_next;
        }
    }
    return *this;
}

template <typename T>
bool forward_list<T>::operator==(const forward_list& rhv) const
{
    if(size() != rhv.size())
    {
        return false;
    }

    Node* this_curr = m_head;
    Node* curr = rhv.m_head;

    while(this_curr && curr)
    {
        if(this_curr->m_data != curr->m_data)
        {   
            return false;
        }
        this_curr = this_curr->m_next;
        curr = curr->m_next;
    }
    return true;
}

template <typename T>
bool forward_list<T>::operator!=(const forward_list& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool forward_list<T>::operator<(const forward_list& rhv) const
{
    Node* this_curr = this->m_head;
    Node *curr = rhv.m_head;
    while(this_curr && curr)
    {                                        
        if(this_curr->m_data < curr->m_data)
        {
            return true;
        }
        else if(this_curr->m_data > curr->m_data)
        {
            return false;
        }
        this_curr = this_curr->m_next;
        curr = curr->m_next;
    }  

    return (this_curr == nullptr && curr != nullptr);
}

template <typename T>
bool forward_list<T>::operator<=(const forward_list& rhv) const
{
    return ((*this < rhv) || (*this == rhv)); 
}

template <typename T>
bool forward_list<T>::operator>(const forward_list& rhv) const
{
    return !(*this <= rhv);
}

template <typename T>
bool forward_list<T>::operator>=(const forward_list& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
typename forward_list<T>::size_type forward_list<T>::size() const
{
    size_type size = 0;
    Node* curr = m_head;
    while(curr)
    {
        ++size;
        curr = curr->m_next;
    }
    return size;
}

template <typename T>
bool forward_list<T>::empty() const
{
    return m_head == nullptr;
}

template <typename T>
void forward_list<T>::resize(size_type s, const_reference init)
{
    if(size() >= s)
    {
        return;
    }  
    
    Node* curr = m_head;
    while(curr->m_next)
    {
        curr = curr->m_next;
    }

    size_type current_size = size();
    while (current_size < s) 
    {
        if (!curr) 
        {
            m_head = new Node(init);
            curr = m_head;
        } 
        else 
        {
            curr->m_next = new Node(init);
            curr = curr->m_next;
        }
        ++current_size;
    }
}

template <typename T>
void forward_list<T>::clear() noexcept
{
    Node* curr = m_head;
    while (curr != nullptr) 
    {
        Node* temp = curr;
        curr = curr->m_next;
        delete temp;
    }
    m_head = nullptr;
}

template <typename T>
void forward_list<T>::push_front(const_reference elem)
{
    Node* newNode = new Node(elem);
    newNode->m_next = m_head;
    m_head = newNode;
}

template <typename T>
void forward_list<T>::pop_front()
{
    if(!m_head)
    {
        return;
    }
    Node* del = m_head;
    m_head = m_head->m_next;
    delete del;
}

template <typename T>
void forward_list<T>::push_back(const_reference elem)
{
    if(!m_head)
    {
        m_head = new Node(elem);
        return;
    }
    Node* curr = m_head;
    while(curr->m_next)
    {
        curr = curr->m_next;
    }
    curr->m_next = new Node(elem);
}

template <typename T>
void forward_list<T>::pop_back() 
{
    if(!m_head || !m_head->m_next) 
    {
        delete m_head;
        m_head = nullptr;
        return;
    }
    
    Node* curr = m_head;
    while (curr->m_next->m_next) 
    {
        curr = curr->m_next;
    }

    delete curr->m_next;
    curr->m_next = nullptr;
}

template <typename T>
typename forward_list<T>::const_reference forward_list<T>::front() const
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");
}

template <typename T>
typename forward_list<T>::reference forward_list<T>::front()
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");
}

template <typename T>
typename forward_list<T>::const_reference forward_list<T>::back() const
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* curr = m_head;
    while(curr->m_next)
    {
        curr = curr->m_next;
    }
    return curr->m_data;
} 

template <typename T>
typename forward_list<T>::reference forward_list<T>::back()
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* curr = m_head;
    while(curr->m_next)
    {
        curr = curr->m_next;
    }
    return curr->m_data;
}


template <typename T>
typename forward_list<T>::const_reference forward_list<T>::min() const
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* min = m_head;
    Node* curr = m_head->m_next;
    while(curr)
    {
        if(curr->m_data < min->m_data)
        {
            min = curr;
        }
        curr = curr->m_next;
    }
    return min->m_data;
}

template <typename T>
typename forward_list<T>::reference forward_list<T>::min()
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* min = m_head;
    Node* curr = m_head->m_next;
    while(curr)
    {
        if(curr->m_data < min->m_data)
        {
            min = curr;
        }
        curr = curr->m_next;
    }
    return min->m_data;
}

template <typename T>
typename forward_list<T>::const_reference forward_list<T>::max() const
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* max = m_head;
    Node* curr = m_head->m_next;
    while(curr)
    {
        if(curr->m_data > max->m_data)
        {
            max = curr;
        }
        curr = curr->m_next;
    }
    return max->m_data;
}

template <typename T>
typename forward_list<T>::reference forward_list<T>::max()
{
    if(!m_head)
    {
        throw std::logic_error("List is empty");   
    }
    Node* max = m_head;
    Node* curr = m_head->m_next;
    while(curr)
    {
        if(curr->m_data > max->m_data)
        {
            max = curr;
        }
        curr = curr->m_next;
    }
    return max->m_data;
}

template <typename T>
void forward_list<T>::reverse()
{   
    if(m_head == nullptr)
    {
        return;
    }
    Node* prev = nullptr;
    Node* current = m_head;
    Node* next;
    while(current)
    {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}

template <typename T>
void forward_list<T>::merge(forward_list& other)
{   
    if(this == &other)
    {
        return;
    }
    if(!m_head)
    {
        m_head = other.m_head;
        other.m_head = nullptr;
        return;
    }
    Node* current = m_head;
    while(current->m_next)
    {
        current = current->m_next;
    }
    current->m_next = other.m_head;
    other.m_head = nullptr;
}

template <typename T>
void forward_list<T>::print() const
{
    Node* temp = m_head;
    while(temp)
    {
        std::cout << temp->m_data << " ";
        temp = temp->m_next; 
    }
    std::cout << std::endl;
}

template <typename T>
void forward_list<T>::sort()
{
    if(!m_head || !m_head->m_next)
    {
        return;
    }
    Node* current = m_head;
    Node* sorted = nullptr;
    while(current)
    {
        Node* next = current->m_next;
        if (!sorted || sorted->m_data >= current->m_data) 
        {
            current->m_next = sorted;
            sorted = current;
        }
        else 
        {
            Node* temp = sorted;
            while (temp->m_next && temp->m_next->m_data < current->m_data) 
            {
                temp = temp->m_next;
            }
            current->m_next = temp->m_next;
            temp->m_next = current;
        }
        current = next;
    }  
    m_head = sorted;
}

template <typename T>
void forward_list<T>::unique()
{
    if(!m_head || !m_head->m_next)
    {
        return;
    }
    Node* temp = m_head->m_next;
    Node* unique_tmp = m_head;
    unique_tmp->m_next = nullptr;
    Node* prev = nullptr;
    while(temp)
    {
        bool flag = false;
        while(unique_tmp)
        {
            if(temp->m_data == unique_tmp->m_data)
            {
                Node* del = temp;
                temp = temp->m_next;
                flag = true;
                delete del;
                break;
            }
            prev = unique_tmp;
            unique_tmp = unique_tmp->m_next;
        }
        if(!flag)
        {   
            prev->m_next = temp;
            prev = prev->m_next;
            temp = temp->m_next;
            prev->m_next = nullptr;
        }
        unique_tmp = m_head;
    }
}
template <typename T>
typename forward_list<T>::iterator forward_list<T>::insert(iterator pos, size_type size, const_reference val)
{
    while(size != 0)
    {
        pos = insert_def(pos,val);
        --size;
    }
    return pos;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::insert(iterator pos, std::initializer_list<value_type> init)
{
    for(auto& elem : init)
    {
        pos = insert_def(pos,elem);
    }

    return pos;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::insert(iterator pos, iterator f, iterator l)
{
    while (f != l)
    {
        pos = insert_def(pos,*f);
        ++f;
    }
    return pos;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::erase(iterator pos)
{
    if(!m_head || pos == end())
    {
        throw std::logic_error("List is Empty");
    }
    if(pos == begin())
    {
        pop_front();
        return iterator(m_head);
    }

    Node* prev = nullptr;
    for (iterator it = begin(); it != end(); ++it) 
    {
        if (it.ptr == pos.ptr) 
        {
            Node* del = pos.ptr;
            if(prev)
            {
                prev->m_next = it.ptr->m_next;
            }
            delete del; 
            return iterator(prev->m_next); 
        }
        prev = it.ptr;
    }
    throw std::logic_error("Iterator pos is not valid");
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::erase(iterator f, iterator l)
{
    while(f != l)
    {
        f = erase(f);
    }

    return iterator(l);
}

template <typename T>
void forward_list<T>::remove(const_reference val)
{
    if(!m_head)
    {
        return;
    }
    if(m_head->m_data == val)
    {
        pop_front();
        return;
    }
    Node* curr = m_head;
    Node* prev = nullptr;
    while(curr)
    {
        if(curr->m_data == val)
        {
            prev->m_next = curr->m_next;
            delete curr; 
            return;
        }
        prev = curr;
        curr = curr->m_next;
    }
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::insert_def(iterator pos, const_reference val)
{
    if(!m_head)
    {
        throw std::logic_error("List is Empty");
    }
    if(m_head == pos.ptr)
    {
        push_front(val);
        return iterator(m_head->m_next);
    }

    Node* prev = nullptr;
    for (iterator it = begin(); it != end(); ++it) 
    {
        if (it.ptr == pos.ptr) 
        {
            Node* newNode = new Node(val);
            newNode->m_next = pos.ptr; 
            prev->m_next = newNode;
            return iterator(newNode->m_next);
        }
        prev = it.ptr;
    }
    throw std::logic_error("Iterator pos is not valid");
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::insert_rev(iterator pos, const_reference val)
{
    if(!m_head)
    {
        throw std::logic_error("List is Empty");
    }
    if(m_head == pos.ptr)
    {
        push_front(val);
        return iterator(m_head);
    }

    Node* prev = nullptr;
    for (iterator it = begin(); it != end(); ++it) 
    {
        if (it.ptr == pos.ptr) 
        {
            Node* newNode = new Node(val);
            newNode->m_next = pos.ptr; 
            prev->m_next = newNode;
            return iterator(newNode);
        }
        prev = it.ptr;
    }
    throw std::logic_error("Iterator pos is not valid");
}

//===================================================Base Iterator ====================================================

template <typename T>
forward_list<T>::base_iterator::base_iterator(Node* ptr) : ptr(ptr){}

template <typename T>
bool forward_list<T>::base_iterator::operator==(const base_iterator& rhv) const
{
    return rhv.ptr == ptr;
}

template <typename T>
bool forward_list<T>::base_iterator::operator!=(const base_iterator& rhv) const
{
    return rhv.ptr != ptr;
}

//====================================================Const Iterator====================================================

template <typename T>
forward_list<T>::const_iterator::const_iterator(Node* ptr) : base_iterator(ptr) {}

template <typename T>
forward_list<T>::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
forward_list<T>::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
const typename forward_list<T>::const_iterator& forward_list<T>::const_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
} 

template <typename T>
const typename forward_list<T>::const_iterator& forward_list<T>::const_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
} 

template <typename T>
typename  forward_list<T>::const_reference forward_list<T>::const_iterator::operator*()const
{
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    return this->ptr->m_data;
}

template <typename T>
typename forward_list<T>::const_pointer forward_list<T>::const_iterator::operator->()const
{
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    return &(this->ptr->m_data);
}

template <typename T>
const typename forward_list<T>::const_iterator& forward_list<T>::const_iterator::operator++()
{   
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    this->ptr = this->ptr->m_next;
    return *this;
}

template <typename T>
const typename forward_list<T>::const_iterator forward_list<T>::const_iterator::operator++(value_type)
{
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cbegin() const
{
    return const_iterator(m_head);
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cend() const
{
    return const_iterator(nullptr);
}

//====================================================Iterator====================================================

template <typename T>
forward_list<T>::iterator::iterator(Node* ptr) : const_iterator(ptr) {}

template <typename T>
forward_list<T>::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv.ptr) {}

template <typename T>
forward_list<T>::iterator::iterator(base_iterator&& rhv) : const_iterator(rhv.ptr) {}

template <typename T>
typename forward_list<T>::reference forward_list<T>::iterator::operator*()
{
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    return this->ptr->m_data;
}

template <typename T>
typename forward_list<T>::pointer forward_list<T>::iterator::operator->()
{
    if(!this->ptr)
    {
        throw std::out_of_range("");
    }
    return &(this->ptr->m_data);
}

template <typename T>
const typename forward_list<T>::iterator& forward_list<T>::iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;   
}

template <typename T>
const typename forward_list<T>::iterator& forward_list<T>::iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin()
{
    return iterator(m_head);
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end()
{
    return iterator(nullptr);
}



