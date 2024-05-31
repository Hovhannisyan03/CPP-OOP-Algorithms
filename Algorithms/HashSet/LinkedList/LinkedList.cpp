#include "LinkedList.h"

LinkedList::Node::Node(value_type data) : m_data{data}, m_next{nullptr}{}

LinkedList::Node::Node() : m_next{nullptr} {}

LinkedList::LinkedList() : m_head{nullptr} {}

LinkedList::~LinkedList()
{
    clear();
}
LinkedList::LinkedList(const LinkedList& rhv)
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

LinkedList::LinkedList(LinkedList&& rhv) : m_head{rhv.m_head}
{
    rhv.m_head = nullptr;
}

LinkedList::LinkedList(size_type size) : LinkedList(size,0) {}

LinkedList::LinkedList(size_type size, const_reference init)
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

LinkedList::LinkedList(std::initializer_list<value_type> init)
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

LinkedList::LinkedList(iterator f, iterator l)
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


const LinkedList& LinkedList::operator=(const LinkedList& rhv)
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

const LinkedList& LinkedList::operator=(LinkedList&& rhv)
{
    if(&rhv == this)
    {
        return *this;
    }

    m_head = rhv.m_head;
    rhv.m_head = nullptr;
    return *this;
}

const LinkedList& LinkedList::operator=(std::initializer_list<value_type> init)
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
        
bool LinkedList::operator==(const LinkedList& rhv) const
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

bool LinkedList::operator!=(const LinkedList& rhv) const
{
    return !(*this == rhv);
}

bool LinkedList::operator<(const LinkedList& rhv) const
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

bool LinkedList::operator<=(const LinkedList& rhv) const
{
    return ((*this < rhv) || (*this == rhv)); 
}

bool LinkedList::operator>(const LinkedList& rhv) const
{
    return !(*this <= rhv);
}

bool LinkedList::operator>=(const LinkedList& rhv) const
{
    return !(*this < rhv);
}

void LinkedList::swap(LinkedList& rhv)
{
    Node* temp = m_head;
    m_head = rhv.m_head;
    rhv.m_head = temp;
}

LinkedList::size_type LinkedList::size() const
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

bool LinkedList::empty() const
{
    return m_head == nullptr;
}

void LinkedList::resize(size_type s, const_reference init)
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

void LinkedList::clear() noexcept
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

void LinkedList::push_front(const_reference elem)
{
    Node* newNode = new Node(elem);
    newNode->m_next = m_head;
    m_head = newNode;
}

void LinkedList::pop_front()
{
    if(!m_head)
    {
        return;
    }
    Node* del = m_head;
    m_head = m_head->m_next;
    delete del;
}

void LinkedList::push_back(const_reference elem)
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

void LinkedList::pop_back() 
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

LinkedList::const_reference LinkedList::front() const
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");
}
LinkedList::reference LinkedList::front()
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");
}

LinkedList::const_reference LinkedList::back() const
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

LinkedList::reference LinkedList::back()
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

LinkedList::const_reference LinkedList::min() const
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

LinkedList::reference LinkedList::min()
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

LinkedList::const_reference LinkedList::max() const
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

LinkedList::reference LinkedList::max()
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

void LinkedList::reverse()
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

LinkedList::iterator LinkedList::insert(iterator pos, size_type size, const_reference val)
{
    while(size != 0)
    {
        pos = insert_def(pos,val);
        --size;
    }
    return pos;
}

LinkedList::iterator LinkedList::insert(iterator pos, std::initializer_list<value_type> init)
{
    for(auto& elem : init)
    {
        pos = insert_def(pos,elem);
    }

    return pos;
}

LinkedList::iterator LinkedList::insert(iterator pos, iterator f, iterator l)
{
    while (f != l)
    {
        pos = insert_def(pos,*f);
        ++f;
    }
    return pos;
}

LinkedList::iterator LinkedList::erase(iterator pos)
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

LinkedList::iterator LinkedList::erase(iterator f, iterator l)
{
    while(f != l)
    {
        f = erase(f);
    }

    return iterator(l);
}

void LinkedList::remove(const_reference val)
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

LinkedList::iterator LinkedList::insert_def(iterator pos, const_reference val)
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

LinkedList::iterator LinkedList::insert_rev(iterator pos, const_reference val)
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

LinkedList::base_iterator::base_iterator(Node* ptr) : ptr(ptr){}

bool LinkedList::base_iterator::operator==(const base_iterator& rhv) const
{
    return rhv.ptr == ptr;
}

bool LinkedList::base_iterator::operator!=(const base_iterator& rhv) const
{
    return rhv.ptr != ptr;
}

//====================================================Const Iterator====================================================

LinkedList::const_iterator::const_iterator(Node* ptr) : base_iterator(ptr) {}

LinkedList::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

LinkedList::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

const LinkedList::const_iterator& LinkedList::const_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
} 

const LinkedList::const_iterator& LinkedList::const_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
} 

LinkedList::const_reference LinkedList::const_iterator::operator*()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

LinkedList::const_pointer LinkedList::const_iterator::operator->()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const LinkedList::const_iterator& LinkedList::const_iterator::operator++()
{   
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_next;
    return *this;
}

const LinkedList::const_iterator LinkedList::const_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

LinkedList::const_iterator LinkedList::cbegin() const
{
    return const_iterator(m_head);
}

LinkedList::const_iterator LinkedList::cend() const
{
    return const_iterator(nullptr);
}

//====================================================Iterator====================================================

LinkedList::iterator::iterator(Node* ptr) : const_iterator(ptr) {}

LinkedList::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv.ptr) {}

LinkedList::iterator::iterator(base_iterator&& rhv) : const_iterator(rhv.ptr) {}

LinkedList::reference LinkedList::iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

LinkedList::pointer LinkedList::iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const LinkedList::iterator& LinkedList::iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;   
}

const LinkedList::iterator& LinkedList::iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

LinkedList::iterator LinkedList::begin()
{
    return iterator(m_head);
}

LinkedList::iterator LinkedList::end()
{
    return iterator(nullptr);
}



