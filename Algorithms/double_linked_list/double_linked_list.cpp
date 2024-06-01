#include "double_linked_list.h"

double_linked_list::Node::Node(value_type data) : m_data{data}, m_prev{nullptr}, m_next{nullptr} {}

double_linked_list::Node::Node() : m_data{0}, m_prev{nullptr}, m_next{nullptr} {}


double_linked_list::double_linked_list() : m_head{nullptr}, m_tail{nullptr} {}

double_linked_list::double_linked_list(double_linked_list&& rhv) noexcept : m_head{rhv.m_head}, m_tail{rhv.m_tail}
{
    rhv.m_head = nullptr;
    rhv.m_tail = nullptr;
}

double_linked_list::double_linked_list(const double_linked_list& rhv) : m_head{nullptr}, m_tail{nullptr}
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

double_linked_list::double_linked_list(size_type size, const_reference init) : m_head{nullptr}, m_tail{nullptr}
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

double_linked_list::double_linked_list(size_type size) : double_linked_list(size,0) {}

double_linked_list::double_linked_list(std::initializer_list<value_type> init) : m_head{nullptr}, m_tail{nullptr}
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

double_linked_list::double_linked_list(iterator f, iterator e) : m_head{nullptr}, m_tail{nullptr}
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

double_linked_list::~double_linked_list()
{
    clear();
}

const double_linked_list& double_linked_list::operator=(const double_linked_list& rhv)
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

const double_linked_list& double_linked_list::operator=(double_linked_list&& rhv)
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

const double_linked_list& double_linked_list::operator=(std::initializer_list<value_type> init)
{
    clear();
    for(auto& elem : init)
    {
        push_back(elem);
    }
    return *this;
}


bool double_linked_list::operator==(const double_linked_list& rhv) const
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

bool double_linked_list::operator!=(const double_linked_list& rhv) const
{
    return !(*this == rhv);
}

bool double_linked_list::operator<(const double_linked_list& rhv) const
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

bool double_linked_list::operator<=(const double_linked_list& rhv) const
{
   return (*this < rhv) || (*this == rhv);
}

bool double_linked_list::operator>(const double_linked_list& rhv) const
{
    return !(*this <= rhv);
}

bool double_linked_list::operator>=(const double_linked_list& rhv) const
{
    return !(*this < rhv);

}

void double_linked_list::swap(double_linked_list& rhv)
{
    Node* tmp_head = rhv.m_head;
    Node* tmp_tail = rhv.m_tail;
    rhv.m_head = m_head;
    rhv.m_tail = m_tail;
    m_head = tmp_head;
    m_tail = tmp_tail;
}

void double_linked_list::display(bool head)
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

bool double_linked_list::empty()
{
    return m_head == nullptr;
}

void double_linked_list::push_back(const_reference val)
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

void double_linked_list::push_front(const_reference val)
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

void double_linked_list::pop_back()
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

void double_linked_list::pop_front()
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

void double_linked_list::clear() noexcept
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

double_linked_list::const_reference double_linked_list::front() const
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");   

}

double_linked_list::reference double_linked_list::front()
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::logic_error("List is empty");    
}

double_linked_list::const_reference double_linked_list::back() const
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::logic_error("List is empty");   
}

double_linked_list::reference double_linked_list::back()
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::logic_error("List is empty");    
}

double_linked_list::const_reference double_linked_list::min() const
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

double_linked_list::reference double_linked_list::min() 
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

double_linked_list::const_reference double_linked_list::max() const
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


double_linked_list::reference double_linked_list::max()
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

double_linked_list::iterator double_linked_list::find(const_reference elem)
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

void double_linked_list::reverse()
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

double_linked_list::size_type double_linked_list::size() const
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

double_linked_list::iterator double_linked_list::rfind(const_reference elem)
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

double_linked_list::iterator double_linked_list::insert(iterator pos, value_type val)
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

double_linked_list::iterator double_linked_list::insert(iterator pos, size_type size, const_reference val)
{
    for (size_type i = 0; i < size; ++i) 
    {
        pos = insert(pos, val); 
    }
    return pos; 
} 

double_linked_list::iterator double_linked_list::insert(iterator pos, std::initializer_list<value_type> init)
{
    for(auto& elem : init)
    {
        pos = insert(pos,elem);
    }
    return pos;
}

double_linked_list::iterator double_linked_list::insert(iterator pos, iterator f, iterator l)
{
    while(f != l)
    {
        pos = insert(pos, *f);
        ++f;
    }
    return pos;
}

double_linked_list::iterator double_linked_list::insert_def(iterator pos, const_reference val)
{
    insert(pos,val);
    return pos;
}

double_linked_list::iterator double_linked_list::insert_rev(iterator pos, const_reference val)
{
    return insert(pos,val);
}

void double_linked_list::resize(size_type s, const_reference init)
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

double_linked_list::iterator double_linked_list::erase(iterator pos)
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

double_linked_list::iterator double_linked_list::erase(iterator f, iterator l)
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

double_linked_list::size_type double_linked_list::remove(const_reference val)
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

bool double_linked_list::is_valid_iterator(iterator pos)
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

double_linked_list::base_iterator::base_iterator(Node* ptr) : ptr(ptr){}

bool double_linked_list::base_iterator::operator==(const base_iterator& rhv) const
{
    return rhv.ptr == ptr;
}

bool double_linked_list::base_iterator::operator!=(const base_iterator& rhv) const
{
    return rhv.ptr != ptr;
}

// =================================================== Const Iterator ==============================================================

double_linked_list::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator{rhv.ptr} {}

double_linked_list::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator{rhv.ptr} {}

double_linked_list::const_iterator::const_iterator(Node* ptr) : base_iterator{ptr} {}

const double_linked_list::const_iterator& double_linked_list::const_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const double_linked_list::const_iterator& double_linked_list::const_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

double_linked_list::const_reference double_linked_list::const_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return ptr->m_data;
}

double_linked_list::const_pointer double_linked_list::const_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &ptr->m_data;
}

const double_linked_list::const_iterator& double_linked_list::const_iterator::operator++()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    ptr = ptr->m_next;
    return *this;
} 

const double_linked_list::const_iterator double_linked_list::const_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const double_linked_list::const_iterator& double_linked_list::const_iterator::operator--()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    ptr = ptr->m_prev;
    return *this;
} 

const double_linked_list::const_iterator double_linked_list::const_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    const_iterator tmp = *this;
    --(*this);
    return tmp;
} 

double_linked_list::const_iterator double_linked_list::cbegin() const
{
    return const_iterator(m_head);
}

double_linked_list::const_iterator double_linked_list::cend() const 
{
    return const_iterator(nullptr);
}
// =================================================== Iterator ==============================================================

double_linked_list::iterator::iterator(const base_iterator& rhv) : const_iterator{rhv.ptr} {}

double_linked_list::iterator::iterator(base_iterator&& rhv) : const_iterator{rhv.ptr} {}

double_linked_list::iterator::iterator(Node* ptr) : const_iterator{ptr} {}

const double_linked_list::iterator& double_linked_list::iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const double_linked_list::iterator& double_linked_list::iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

double_linked_list::reference double_linked_list::iterator::operator*()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return ptr->m_data;
}

double_linked_list::pointer double_linked_list::iterator::operator->()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &ptr->m_data;
}

double_linked_list::iterator double_linked_list::begin()
{
    return iterator(m_head);
}

double_linked_list::iterator double_linked_list::end()
{
    return iterator(nullptr);
}

// =================================================== Const Reverse Iterator ==============================================================

double_linked_list::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr){}

double_linked_list::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr){}

double_linked_list::const_reverse_iterator::const_reverse_iterator(Node* ptr) : base_iterator(ptr){}

const double_linked_list::const_reverse_iterator& double_linked_list::const_reverse_iterator::operator=(const base_iterator& rhv) 
{
    ptr = rhv.ptr;
    return *this;
}

const double_linked_list::const_reverse_iterator& double_linked_list::const_reverse_iterator::operator=(base_iterator&& rhv) 
{
    ptr = rhv.ptr;
    return *this;
}

double_linked_list::const_reference double_linked_list::const_reverse_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");

    }
    return ptr->m_data;
}

double_linked_list::const_pointer double_linked_list::const_reverse_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &(ptr->m_data);
}

const double_linked_list::const_reverse_iterator& double_linked_list::const_reverse_iterator::operator++()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");

    }
    ptr = ptr->m_prev;
    return *this;
}

const double_linked_list::const_reverse_iterator double_linked_list::const_reverse_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::logic_error("Trying to increment an invalid iterator");
    }
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const double_linked_list::const_reverse_iterator& double_linked_list::const_reverse_iterator::operator--()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");

    }
    ptr = ptr->m_next;
    return *this;
}

const double_linked_list::const_reverse_iterator double_linked_list::const_reverse_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::logic_error("Trying to decrement an invalid iterator");
    }
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

double_linked_list::const_reverse_iterator double_linked_list::crbegin() const
{
    return const_reverse_iterator(m_tail);
}

double_linked_list::const_reverse_iterator double_linked_list::crend() const
{
    return const_reverse_iterator(nullptr);
}

// =================================================== Reverse Iterator ==============================================================

double_linked_list::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv.ptr){}

double_linked_list::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(rhv.ptr){}

double_linked_list::reverse_iterator::reverse_iterator(Node* ptr) : const_reverse_iterator(ptr){}

const double_linked_list::reverse_iterator& double_linked_list::reverse_iterator::operator=(const base_iterator& rhv) 
{
    ptr = rhv.ptr;
    return *this;
}

const double_linked_list::reverse_iterator& double_linked_list::reverse_iterator::operator=(base_iterator&& rhv) 
{
    ptr = rhv.ptr;
    return *this;
}

double_linked_list::reference double_linked_list::reverse_iterator::operator*()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");

    }
    return ptr->m_data;
}

double_linked_list::pointer double_linked_list::reverse_iterator::operator->()
{
    if(!ptr)
    {
        throw std::logic_error("Trying to dereference an invalid iterator");
    }
    return &(ptr->m_data);
}

double_linked_list::reverse_iterator double_linked_list::rbegin()
{
    return reverse_iterator(m_tail);
}

double_linked_list::reverse_iterator double_linked_list::rend()
{
    return reverse_iterator(nullptr);
}
