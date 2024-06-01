#include "franklist.h"

//====================================== Node ========================================
vhuk::FrankList::Node::Node() : m_next(nullptr), m_prev(nullptr), m_greater(nullptr), m_lesser(nullptr){}
    
vhuk::FrankList::Node::Node(value_type val) : m_data(val),  m_next(nullptr), m_prev(nullptr), m_greater(nullptr), m_lesser(nullptr) {}

//====================================== FrankList ====================================

vhuk::FrankList::FrankList() : m_head(nullptr), m_tail(nullptr), m_asc(nullptr), m_desc(nullptr){}

vhuk::FrankList::~FrankList() 
{
    clear();
}

vhuk::FrankList::FrankList(size_type size, const_reference init) : m_head(nullptr), m_tail(nullptr), m_asc(nullptr), m_desc(nullptr)
{
    for(size_type i = 0; i < size; ++i)
    {
        push_back(init);
    }
}

vhuk::FrankList::FrankList(size_type size) : m_head(nullptr), m_tail(nullptr), m_asc(nullptr), m_desc(nullptr)
{
    while(size != -1)
    {   
        push_back(0);
        --size;
    }
}
vhuk::FrankList::FrankList(const FrankList& rhv)
{
    if(rhv.m_head == nullptr)
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_asc = nullptr;
        m_desc = nullptr;
    }
    else
    {
        Node* tmp = rhv.m_head;
        int count = 0;
        while(tmp != nullptr)
        {
            if(count == 0)
            {
                Node* newNode = new Node(tmp->m_data);
                m_head = newNode;
                m_tail = newNode;
                m_desc = newNode;
                m_asc = newNode;
                tmp = tmp->m_next;
                ++count;
                continue;
            }

            push_back(tmp->m_data);
            tmp = tmp->m_next;
        }
    }
}

vhuk::FrankList::FrankList(FrankList&& rhv)
{
    m_head = rhv.m_head;
    m_tail = rhv.m_tail;
    m_asc = rhv.m_asc;
    m_desc = rhv.m_desc;

    rhv.m_head = nullptr;
    rhv.m_tail = nullptr;
    rhv.m_asc = nullptr;
    rhv.m_desc = nullptr;
}

const vhuk::FrankList& vhuk::FrankList::operator=(const FrankList& rhv)
{
    if(this == &rhv)
    {
        return *this;
    }

    clear();
   
    Node* tmp = rhv.m_head;
        int count = 0;
        while(tmp != nullptr)
        {
            if(count == 0)
            {
                Node* newNode = new Node(tmp->m_data);
                m_head = newNode;
                m_tail = newNode;
                m_desc = newNode;
                m_asc = newNode;
                tmp = tmp->m_next;
                ++count;
                continue;
            }
        push_back(tmp->m_data);
        tmp = tmp->m_next;
    }
    return *this;
}

const vhuk::FrankList& vhuk::FrankList::operator=(FrankList&& rhv)
{
    if(this == &rhv)
    {
        return *this;
    }

    clear();

    m_head = rhv.m_head;
    m_tail = rhv.m_tail;
    m_asc = rhv.m_asc;
    m_desc = rhv.m_desc;

    rhv.m_head = nullptr;
    rhv.m_tail = nullptr;
    rhv.m_desc = nullptr;
    rhv.m_asc = nullptr;
    return *this;
}

vhuk::FrankList::FrankList(std::initializer_list<value_type> init) : m_head(nullptr), m_tail(nullptr), m_asc(nullptr), m_desc(nullptr)
{
    for(value_type elem : init)
    {
        push_back(elem);
    }
}

vhuk::FrankList::FrankList(iterator f, iterator l) : m_head(nullptr), m_tail(nullptr), m_asc(nullptr), m_desc(nullptr)
{
    while(f != l)
    {
        push_back(*f);
        ++f;
    }
}

vhuk::FrankList::size_type vhuk::FrankList::remove(const_reference val)
{      
    size_type size = 0;
    if(!m_head)
    {
        return size;
    }
    Node* ptr = m_head;
    while(ptr)
    {
        if(val == m_head->m_data)
        {
            ptr = ptr -> m_next;
            pop_front();
            ++size;
            continue;
        }
        if(val == m_tail->m_data)
        {
            pop_back();
            ++size;
            continue;
        }
        if(ptr->m_data == val)
        {
            
            Node* del = ptr;
            ptr->m_prev->m_next = del->m_next;
            ptr->m_next->m_prev = del->m_prev;
            re_sort(del);
            ptr = del->m_next;
            delete del;
            del = nullptr;
            ++size;
            continue;
        }
        ptr = ptr->m_next;
    }
    return size;
}

bool vhuk::FrankList::isOdd::operator()(const_reference val)
{
    return val % 2 == 1;
}

vhuk::FrankList::size_type vhuk::FrankList::remove_if(isOdd func)
{
    size_type count = 0;
    if (!m_head)
    {
        return count;
    }
    
    Node* tmp = m_head;
    while (tmp)
    {
        if(func(tmp->m_data))
        {
            if(tmp == m_head)
            {
                tmp = tmp->m_next;
                pop_front();
            }
            else if (tmp == m_tail)
            {
                tmp = tmp->m_next;
                pop_back();
            }
            else
            {
                Node* del = tmp;
                tmp->m_prev->m_next = del->m_next;
                tmp->m_next->m_prev = del->m_prev;
                re_sort(del);
                tmp = del->m_next;
                delete del;
                del = nullptr;
            }
            ++count;
            continue;
        }
        tmp = tmp->m_next;
    }
    return count;
}
void vhuk::FrankList::traverse(void (*addPtr)(pointer val), bool sorted, bool reversed)
{
    if(!m_head)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if(sorted == 0 && reversed == 0)
    {
        Node* tmp1 = m_head;
        while(tmp1)
        {
            addPtr(&(tmp1->m_data));
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_next;
        }
        std::cout << std::endl;
        return;
    }
    
    if(sorted == 0 && reversed == 1)
    {
        Node* tmp1 = m_tail;
        while(tmp1)
        {
            addPtr(&(tmp1->m_data));
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_prev;
        }
        std::cout << std::endl;
        return;
    }

    if(sorted == 1 && reversed == 0)
    {
        Node* tmp1 = m_asc;
        while(tmp1)
        {
            addPtr(&(tmp1->m_data));
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_greater;
        }
        std::cout << std::endl;
        return;
    }

    if(sorted == 1 && reversed == 1)
    {
        Node* tmp1 = m_desc;
        while(tmp1)
        {
            addPtr(&(tmp1->m_data));
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_lesser;
        }
        std::cout << std::endl;
        return;
    }
}

vhuk::FrankList::iterator vhuk::FrankList::insert_rev(iterator pos, const_reference val)
{
    if(!m_head)
    {
        throw std::out_of_range("");
    }
    if(m_head && m_head == pos.ptr)
    {
        push_front(val);
        return iterator(m_head);
    }

    Node* newNode = new Node(val);
    newNode->m_next = pos.ptr;
    newNode->m_prev = pos.ptr->m_prev;
    pos.ptr->m_prev->m_next = newNode;
    pos.ptr->m_prev = newNode;
    put_in_sorted_order(newNode);
    return iterator(newNode);

}

vhuk::FrankList::iterator vhuk::FrankList::insert_def(iterator pos, const_reference val)
{
    if(!m_head)
    {
        throw std::out_of_range("");
    }
    if(m_head && m_head == pos.ptr)
    {
        push_front(val);
        return iterator(m_head->m_next);
    }

    Node* newNode = new Node(val);
    newNode->m_next = pos.ptr;
    newNode->m_prev = pos.ptr->m_prev;
    pos.ptr->m_prev->m_next = newNode;
    pos.ptr->m_prev = newNode;
    put_in_sorted_order(newNode);
    return iterator(newNode->m_next);
}

vhuk::FrankList::iterator vhuk::FrankList::insert(iterator pos, std::initializer_list<value_type> init)
{
    for(auto elem : init)
    {
        pos = insert_def(pos,elem);
    }
}

vhuk::FrankList::iterator vhuk::FrankList::insert(iterator pos, iterator f, iterator l)
{
    while (f != l)
    {
        pos = insert_def(pos,*f);
        ++f;
    }
    return pos;
}
vhuk::FrankList::iterator vhuk::FrankList::insert(iterator pos, size_type size, const_reference val)
{
    while(size != 0)
    {
        pos = insert_def(pos,val);
        --size;
    }
    return pos;
}

void vhuk::FrankList::addOne(pointer val)
{
    (*val)++;
}
void vhuk::FrankList::reverse()
{
    if(m_head == nullptr) 
    {
        std::cout <<"FranksList is empty" << std::endl;
    } 
    else 
    {
        Node* tmp1 = m_head;
        Node* current = m_head->m_next;
        Node* tmp2 = m_head->m_next->m_next;
        while(current) 
        {
            if(!tmp1->m_prev) 
            {
                tmp1->m_prev = current;
                tmp1->m_next = nullptr;
                m_tail = tmp1;
            }
            current->m_next = tmp1;
            current->m_prev = tmp2;
            tmp1 = current;
            current = tmp2;
            if(tmp2) 
            {
                tmp2 = tmp2->m_next;
            }
        }
        m_head = tmp1;
    }
}
vhuk::FrankList::iterator vhuk::FrankList::erase(iterator pos)
{
    Node* del = pos.ptr;
    if (!del)
    {
        throw std::invalid_argument("");
    }

    Node* tmp1 = del->m_prev;
    Node* tmp2 = del->m_next;

    if (tmp1)
    {
        tmp1->m_next = tmp2;
    }
    else
    {
        m_head = tmp2;
    }

    if (tmp2)
    {
        tmp2->m_prev = tmp1;
    }
    else
    {
        m_tail = tmp1;
    }
    re_sort(del);
    delete del;
    
    return iterator(tmp2);
} 

vhuk::FrankList::iterator vhuk::FrankList::erase(iterator f, iterator l)
{
    while(f != l)
    {
        f = erase(f);
    }
    return iterator(l.ptr);
}

void vhuk::FrankList::sort(bool reversed)
{
    if(!m_head || !m_head->m_next)
    {
        return;
    }
    
    if(!reversed)
    {
        Node *tmp2 = m_asc;
        Node* tmp1 = nullptr;
        int count = 0;
        while (tmp2)
        {
            if(count == 0)
            {
                m_head = tmp2;
                m_head->m_prev = tmp2->m_lesser;
                m_head->m_next = tmp2->m_greater;
                m_tail = m_desc;
                m_tail->m_prev = m_desc->m_lesser;
                m_tail->m_next = m_desc->m_greater;
                tmp2 = tmp2->m_greater;
                tmp1 = m_head->m_next;
                ++count;
                continue;
            }
            tmp1->m_prev = tmp2->m_lesser;
            tmp1->m_next = tmp2->m_greater;
            tmp2 = tmp2->m_greater;
            tmp1 = tmp1->m_next;
        }
    }
    else
    {
        Node *tmp2 = m_desc;
        Node* tmp1 = nullptr;
        int count = 0;
        while (tmp2)
        {
            if(count == 0)
            {
                m_head = tmp2;
                m_head->m_prev = tmp2->m_greater;
                m_head->m_next = tmp2->m_lesser;
                m_tail = m_asc;
                m_tail->m_prev = m_asc->m_greater;
                m_tail->m_next = m_asc->m_lesser;
                tmp2 = tmp2->m_lesser;
                tmp1 = m_head->m_next;
                ++count;
                continue;
            }
            tmp1->m_prev = tmp2->m_greater;
            tmp1->m_next = tmp2->m_lesser;
            tmp2 = tmp2->m_lesser;
            tmp1 = tmp1->m_next;
        }  
    }
}

vhuk::FrankList::iterator vhuk::FrankList::find(const_reference elem)
{
    if(!m_head)
    {
        throw std::invalid_argument("");
    }
    if(m_head -> m_data == elem)
    {
        return iterator(m_head);
    }

    Node* tmp = m_head;
    while(tmp)
    {
        if(tmp->m_data == elem)
        {   
            organize_left(tmp);
            return iterator(tmp);
        }
        tmp = tmp->m_next;
    }
    throw std::invalid_argument("");
}

vhuk::FrankList::iterator vhuk::FrankList::rfind(const_reference elem)
{
    if(!m_tail)
    {
        throw std::invalid_argument("");
    }
    if(m_tail -> m_data == elem)
    {
        return iterator(m_tail);
    }

    Node* tmp = m_tail;
    while(tmp)
    {
        if(tmp->m_data == elem)
        {   
            organize_right(tmp);
            return iterator(tmp);
        }
        tmp = tmp->m_prev;
    }
    throw std::invalid_argument("");
}

void vhuk::FrankList::organize_right(Node* ptr)
{
     if(m_tail->m_prev == ptr)
    {
        Node* tmp = m_tail;
        tmp->m_prev = ptr->m_prev;
        ptr->m_prev = tmp;
        m_tail = ptr;
        return;
    }
    Node* tmp1 = ptr->m_next;
    ptr->m_next->m_next->m_prev = ptr;
    ptr->m_next->m_prev = ptr->m_prev;
    ptr->m_prev = tmp1;
}

void vhuk::FrankList::organize_left(Node* ptr)
{
    if(m_head->m_next == ptr)
    {
        Node* tmp = m_head;
        tmp->m_next = ptr->m_next;
        ptr->m_next = tmp;
        m_head = ptr;
        return;
    }
    Node* tmp1 = ptr->m_prev;
    ptr->m_prev->m_prev->m_next = ptr;
    ptr->m_prev->m_next = ptr->m_next;
    ptr->m_next = tmp1;
}

const vhuk::FrankList& vhuk::FrankList::operator=(std::initializer_list<value_type> init)
{
    clear();
    for(value_type elem : init)
    {
        push_back(elem);
    }

    return *this;
}

bool vhuk::FrankList::operator==(const FrankList& rhv) const
{
    if(size() != rhv.size())
    {
        return false;
    }

    Node* tmp1 = m_head;
    Node* tmp2 = rhv.m_head;

    while(tmp1 && tmp2)
    {
        if(tmp1->m_data != tmp2->m_data)
        {   
            return false;
        }
        tmp1 = tmp1->m_next;
        tmp2 = tmp2->m_next;
    }
    return true;

}

bool vhuk::FrankList::operator!=(const FrankList& rhv)const
{
    return !(*this == rhv);
}

bool vhuk::FrankList::operator<(const FrankList& rhv) const
{
    Node* tmp1 = this->m_head;
    Node *tmp2 = rhv.m_head;
    while(tmp1 && tmp2)
    {                                        
        if(tmp1->m_data < tmp2->m_data)
        {
            return true;
        }
        else if(tmp1->m_data > tmp2->m_data)
        {
            return false;
        }
        tmp1 = tmp1->m_next;
        tmp2 = tmp2->m_next;
    }  

    return (tmp1 == nullptr && tmp2 != nullptr);
}

bool vhuk::FrankList::operator<=(const FrankList& rhv) const
{
   return ((*this < rhv) || (*this == rhv)); 
}

bool vhuk::FrankList::operator>(const FrankList& rhv) const
{
    return !(*this <= rhv);
}

bool vhuk::FrankList::operator>=(const FrankList& rhv) const
{
    return !(*this < rhv);
}

void vhuk::FrankList::clear() noexcept
{
    if(!m_head->m_next)
    {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_asc = nullptr;
        m_desc = nullptr;
        return;
    }

    while(m_head)
    {
        Node* ptr = m_head;
        m_head = m_head->m_next;
        delete ptr;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_asc = nullptr;
    m_desc = nullptr;  
}

void vhuk::FrankList::push_back(const_reference elem)
{
    Node* newNode = new Node(elem);
    if(!m_head)
    {   
        m_head = newNode;
        m_tail = newNode;
        m_desc = newNode;
        m_asc = newNode;
        return;
    }
    
    newNode->m_prev = m_tail;
    m_tail->m_next = newNode;
    m_tail = newNode;

    put_in_sorted_order(newNode);
}

void vhuk::FrankList::push_front(const_reference elem)
{
    Node* newNode = new Node(elem);
    if(!m_head)
    {   
        m_head = newNode;
        m_tail = newNode;
        return;
    }

    newNode->m_next = m_head;
    m_head->m_prev = newNode;
    m_head = newNode;

    put_in_sorted_order(newNode);
}

void vhuk::FrankList::pop_back()
{
    if(!m_head)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (!m_head->m_next) 
    {   
        std::cout << "asdadsa";
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_asc = nullptr;
        m_desc = nullptr;
        return;
    }
    Node* del = m_tail;
    m_tail = m_tail->m_prev;
    if(m_tail)
    {
        m_tail->m_next = nullptr;
    }
    re_sort(del);
    delete del;
    del = nullptr;
}

void vhuk::FrankList::re_sort(Node* del)
{   
    if(del == m_asc)
    {   
        m_asc = m_asc->m_greater;
        if (m_asc)
        {
            m_asc->m_lesser = nullptr;
        }
        return;
    }
    if(del == m_desc)
    {
        m_desc = m_desc->m_lesser;
        if(m_desc)
        {
            m_desc->m_greater = nullptr;
        }
        return;       
    }

    Node* tmp = m_asc;
    while(tmp->m_greater != del)
    {
        tmp = tmp->m_greater;
    }
    tmp->m_greater = tmp->m_greater->m_greater;
    if(tmp->m_greater)
    {
        tmp->m_greater->m_lesser = tmp;
    }
}
void vhuk::FrankList::pop_front()
{
    if(!m_head)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if(!m_head->m_next)
    {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_asc = nullptr;
        m_desc = nullptr;
        return;
    }

    Node *del = m_head;
    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
    re_sort(del);
    delete del;
    del = nullptr;
}
void vhuk::FrankList::resize(size_type s, const_reference init)
{
    size_type s1 = size(); 
    if(size() >= s)
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

void vhuk::FrankList::swap(FrankList& rhv)
{
    Node* tmp = m_head;
    m_head = rhv.m_head;
    rhv.m_head = tmp;

    tmp = m_tail;
    m_tail = rhv.m_tail;
    rhv.m_tail = tmp;

    tmp = m_asc;
    m_asc = rhv.m_asc;
    rhv.m_asc = tmp;

    tmp = m_desc;
    m_desc = rhv.m_desc;
    rhv.m_desc = tmp;
}

vhuk::FrankList::const_reference vhuk::FrankList::front() const
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::reference vhuk::FrankList::front()
{
    if(m_head)
    {
        return m_head->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::const_reference vhuk::FrankList::back() const
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::reference vhuk::FrankList::back()
{
    if(m_tail)
    {
        return m_tail->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::const_reference vhuk::FrankList::min() const
{
    if(m_asc)
    {
        return m_asc->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::reference vhuk::FrankList::min()
{
    if(m_asc)
    {
        return m_asc->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::const_reference vhuk::FrankList::max() const
{
    if(m_desc)
    {
        return m_desc->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

vhuk::FrankList::reference vhuk::FrankList::max()
{
    if(m_desc)
    {
        return m_desc->m_data;
    }
    throw std::out_of_range("FrankList is empty");
}

void vhuk::FrankList::put_in_sorted_order(Node *ptr)
{
    if(!ptr)
    {   
        return;
    }
    if(!m_asc)
    {
        m_asc = ptr;
        m_desc = ptr;
        return;
    }
    Node* tmp = m_asc;
    while(tmp->m_data < ptr->m_data && tmp->m_greater)
    {
        tmp = tmp->m_greater;
    }
    if(tmp->m_data < ptr->m_data)
    {   
        ptr->m_greater = tmp->m_greater;
        tmp->m_greater = ptr;
        ptr->m_lesser = tmp;
        if(!ptr->m_greater)
        {
            m_desc = ptr;
        }
    }
    else
    {
        ptr->m_lesser = tmp->m_lesser;
        if(tmp->m_lesser)
        {
            tmp->m_lesser->m_greater = ptr;
        }
        else
        {
            m_asc = ptr;
        }
        ptr->m_greater = tmp;
        tmp->m_lesser = ptr;
    }
}

vhuk::FrankList::size_type vhuk::FrankList::size()const
{
    Node* tmp = m_head;
    size_type count = 0;
    while(tmp)
    {
        ++count;
        tmp = tmp->m_next;
    }

    return count;
}

bool vhuk::FrankList::empty()const
{
    return m_head == nullptr;
}

void vhuk::FrankList::display(bool sorted, bool reversed)
{
    if(!m_head)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if(sorted == 0 && reversed == 0)
    {
        Node* tmp1 = m_head;
        while(tmp1)
        {
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_next;
        }
        std::cout << std::endl;
        return;
    }
    
    if(sorted == 0 && reversed == 1)
    {
        Node* tmp1 = m_tail;
        while(tmp1)
        {
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_prev;
        }
        std::cout << std::endl;
        return;
    }

    if(sorted == 1 && reversed == 0)
    {
        Node* tmp1 = m_asc;
        while(tmp1)
        {
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_greater;
        }
        std::cout << std::endl;
        return;
    }

    if(sorted == 1 && reversed == 1)
    {
        Node* tmp1 = m_desc;
        while(tmp1)
        {
            std::cout << tmp1->m_data << " ";
            tmp1 = tmp1->m_lesser;
        }
        std::cout << std::endl;
        return;
    }
}
//=============================Base iterator============================================

vhuk::FrankList::base_iterator::base_iterator(Node* ptr) : ptr(ptr){}

bool vhuk::FrankList::base_iterator::operator==(const base_iterator& rhv) const
{
    return rhv.ptr == ptr;
}

bool vhuk::FrankList::base_iterator::operator!=(const base_iterator& rhv) const
{
    return rhv.ptr != ptr;
}

//=============================Const iterator============================================

vhuk::FrankList::const_iterator::const_iterator(Node* ptr) : base_iterator(ptr) {}

vhuk::FrankList::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

vhuk::FrankList::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

const vhuk::FrankList::const_iterator& vhuk::FrankList::const_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
} 

const vhuk::FrankList::const_iterator& vhuk::FrankList::const_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
} 

vhuk::FrankList::const_reference vhuk::FrankList::const_iterator::operator*()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_iterator::operator->()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_iterator& vhuk::FrankList::const_iterator::operator++()
{   
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_next;
    return *this;
}

const vhuk::FrankList::const_iterator vhuk::FrankList::const_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_iterator& vhuk::FrankList::const_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_prev;
    return *this;
}

const vhuk::FrankList::const_iterator vhuk::FrankList::const_iterator::operator--(value_type)
{   
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

vhuk::FrankList::const_iterator vhuk::FrankList::cbegin() const
{
    return const_iterator(m_head);
}

vhuk::FrankList::const_iterator vhuk::FrankList::cend() const
{
    return const_iterator(nullptr);
}


//=============================Iterator============================================

vhuk::FrankList::iterator::iterator(Node* ptr) : const_iterator(ptr) {}

vhuk::FrankList::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv.ptr) {}

vhuk::FrankList::iterator::iterator(base_iterator&& rhv) : const_iterator(rhv.ptr) {}

vhuk::FrankList::reference vhuk::FrankList::iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::pointer vhuk::FrankList::iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::iterator& vhuk::FrankList::iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;   
}

const vhuk::FrankList::iterator& vhuk::FrankList::iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::iterator vhuk::FrankList::begin()
{
    return iterator(m_head);
}

vhuk::FrankList::iterator vhuk::FrankList::end()
{
    return iterator(nullptr);
}


//=============================Const Reverse Iterator============================================
vhuk::FrankList::const_reverse_iterator::const_reverse_iterator(Node* ptr) : base_iterator(ptr){}

vhuk::FrankList::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr){}

vhuk::FrankList::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr){}

const vhuk::FrankList::const_reverse_iterator& vhuk::FrankList::const_reverse_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::const_reverse_iterator& vhuk::FrankList::const_reverse_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::const_reference vhuk::FrankList::const_reverse_iterator::operator*()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_reverse_iterator::operator->()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_reverse_iterator& vhuk::FrankList::const_reverse_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_prev;
    return *this;
}

const vhuk::FrankList::const_reverse_iterator vhuk::FrankList::const_reverse_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_reverse_iterator& vhuk::FrankList::const_reverse_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_next;
    return *this;
}

const vhuk::FrankList::const_reverse_iterator vhuk::FrankList::const_reverse_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

vhuk::FrankList::const_reverse_iterator vhuk::FrankList::crbegin() const
{
    return const_reverse_iterator(m_tail);
}

vhuk::FrankList::const_reverse_iterator vhuk::FrankList::crend() const
{
    return const_reverse_iterator(nullptr);
}

//=============================Reverse Iterator============================================
vhuk::FrankList::reverse_iterator::reverse_iterator(Node *ptr) : const_reverse_iterator(ptr){}

vhuk::FrankList::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv.ptr){}

vhuk::FrankList::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(rhv.ptr){}

vhuk::FrankList::reference vhuk::FrankList::reverse_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::pointer vhuk::FrankList::reverse_iterator::operator->() 
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::reverse_iterator&  vhuk::FrankList::reverse_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::reverse_iterator&  vhuk::FrankList::reverse_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::reverse_iterator vhuk::FrankList::rbegin()
{
    return reverse_iterator(m_tail);
}

vhuk::FrankList::reverse_iterator vhuk::FrankList::rend()
{
    return reverse_iterator(nullptr);
}

//=============================Const Asc Iterator============================================
vhuk::FrankList::const_asc_iterator::const_asc_iterator(Node* ptr) : base_iterator(ptr) {}

vhuk::FrankList::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

vhuk::FrankList::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

const vhuk::FrankList::const_asc_iterator& vhuk::FrankList::const_asc_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::const_asc_iterator& vhuk::FrankList::const_asc_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::const_reference vhuk::FrankList::const_asc_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_asc_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_asc_iterator& vhuk::FrankList::const_asc_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_greater;
    return *this;
}

const vhuk::FrankList::const_asc_iterator vhuk::FrankList::const_asc_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_asc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_asc_iterator& vhuk::FrankList::const_asc_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_lesser;
    return *this;
}

const vhuk::FrankList::const_asc_iterator vhuk::FrankList::const_asc_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_asc_iterator tmp = *this;
    --(*this);
    return tmp;
}

vhuk::FrankList::const_asc_iterator vhuk::FrankList::cabegin() const
{
    return const_asc_iterator(m_asc);
}

vhuk::FrankList::const_asc_iterator vhuk::FrankList::caend() const
{
    return const_asc_iterator(nullptr);
}

//=============================Asc Iterator============================================
vhuk::FrankList::asc_iterator::asc_iterator(Node* ptr) : const_asc_iterator(ptr) {}

vhuk::FrankList::asc_iterator::asc_iterator(const base_iterator& rhv) : const_asc_iterator(rhv.ptr) {}

vhuk::FrankList::asc_iterator::asc_iterator(base_iterator&& rhv) : const_asc_iterator(rhv.ptr) {}

vhuk::FrankList::reference vhuk::FrankList::asc_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
} 

vhuk::FrankList::pointer vhuk::FrankList::asc_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::asc_iterator& vhuk::FrankList::asc_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::asc_iterator& vhuk::FrankList::asc_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::asc_iterator vhuk::FrankList::abegin()
{
    return asc_iterator(m_asc);
}

vhuk::FrankList::asc_iterator vhuk::FrankList::aend()
{
    return asc_iterator(nullptr);
}

//=============================Const_desc Iterator============================================
vhuk::FrankList::const_desc_iterator::const_desc_iterator(Node* ptr) : base_iterator(ptr) {}

vhuk::FrankList::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

vhuk::FrankList::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

const vhuk::FrankList::const_desc_iterator& vhuk::FrankList::const_desc_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::const_desc_iterator& vhuk::FrankList::const_desc_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::const_reference vhuk::FrankList::const_desc_iterator::operator*()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_desc_iterator::operator->()const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_desc_iterator& vhuk::FrankList::const_desc_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_lesser;
    return *this;
}


const vhuk::FrankList::const_desc_iterator vhuk::FrankList::const_desc_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_desc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_desc_iterator& vhuk::FrankList::const_desc_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    ptr = ptr->m_greater;
    return *this;
}


const vhuk::FrankList::const_desc_iterator vhuk::FrankList::const_desc_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_desc_iterator tmp = *this;
    --(*this);
    return tmp;
}

vhuk::FrankList::const_desc_iterator vhuk::FrankList::cdbegin() const
{
    return const_desc_iterator(m_desc);
}

vhuk::FrankList::const_desc_iterator vhuk::FrankList::cdend() const
{
    return const_desc_iterator(nullptr);
}

//=============================desc Iterator============================================
vhuk::FrankList::desc_iterator::desc_iterator(Node* ptr) : const_desc_iterator(ptr) {}

vhuk::FrankList::desc_iterator::desc_iterator(const base_iterator& rhv) : const_desc_iterator(rhv.ptr) {}

vhuk::FrankList::desc_iterator::desc_iterator(base_iterator&& rhv) : const_desc_iterator(rhv.ptr) {}

vhuk::FrankList::reference vhuk::FrankList::desc_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::pointer vhuk::FrankList::desc_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::desc_iterator& vhuk::FrankList::desc_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::desc_iterator& vhuk::FrankList::desc_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::desc_iterator vhuk::FrankList::dbegin()
{
    return desc_iterator(m_desc);
}

vhuk::FrankList::desc_iterator vhuk::FrankList::dend()
{
    return desc_iterator(nullptr);
}


//=============================Const multi Iterator============================================
vhuk::FrankList::const_multi_iterator::const_multi_iterator(Node* ptr) : base_iterator(ptr){}

vhuk::FrankList::const_multi_iterator::const_multi_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr){}

vhuk::FrankList::const_multi_iterator::const_multi_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr){}

const vhuk::FrankList::const_multi_iterator& vhuk::FrankList::const_multi_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::const_multi_iterator& vhuk::FrankList::const_multi_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::const_reference vhuk::FrankList::const_multi_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_multi_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_multi_iterator& vhuk::FrankList::const_multi_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    if(mode)
    {
        ptr = ptr->m_next;
        return *this;
    }
    ptr = ptr->m_greater;
    return *this;
}

const vhuk::FrankList::const_multi_iterator vhuk::FrankList::const_multi_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_multi_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_multi_iterator& vhuk::FrankList::const_multi_iterator::operator--()
{   
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    if(mode)
    {
        ptr = ptr->m_prev;
        return *this;
    }
    ptr = ptr->m_lesser;
    return *this;
}


const vhuk::FrankList::const_multi_iterator vhuk::FrankList::const_multi_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_desc_iterator tmp = *this;
    --(*this);
    return tmp;
}

void vhuk::FrankList::const_multi_iterator::chmod()
{
    if(mode)
    {
        mode = false;
        return;
    }
    mode = true;
}

vhuk::FrankList::const_multi_iterator vhuk::FrankList::cmbegin() const
{
    return const_multi_iterator(m_head);
}

vhuk::FrankList::const_multi_iterator vhuk::FrankList::cmend() const
{
    return const_multi_iterator(nullptr);
}

vhuk::FrankList::const_multi_iterator vhuk::FrankList::cmabegin() const
{
    return const_multi_iterator(m_asc);
}

vhuk::FrankList::const_multi_iterator vhuk::FrankList::cmaend() const
{
    return const_multi_iterator(nullptr);
}

//============================= Multi Iterator============================================

vhuk::FrankList::multi_iterator::multi_iterator(Node *ptr) : const_multi_iterator(ptr){}

vhuk::FrankList::multi_iterator::multi_iterator(const base_iterator& rhv) :  const_multi_iterator(rhv.ptr) {}

vhuk::FrankList::multi_iterator::multi_iterator(base_iterator&& rhv) :  const_multi_iterator(rhv.ptr) {}

vhuk::FrankList::reference vhuk::FrankList::multi_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::pointer vhuk::FrankList::multi_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::multi_iterator& vhuk::FrankList::multi_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::multi_iterator& vhuk::FrankList::multi_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::multi_iterator vhuk::FrankList::mbegin()
{
    return multi_iterator(m_head);
}

vhuk::FrankList::multi_iterator vhuk::FrankList::mend()
{
    return multi_iterator(nullptr);
}

vhuk::FrankList::multi_iterator vhuk::FrankList::mabegin()
{
    return multi_iterator(m_asc);
}

vhuk::FrankList::multi_iterator vhuk::FrankList::maend()
{
    return multi_iterator(nullptr);
}

//=============================Const Multi reverse Iterator============================================
vhuk::FrankList::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr) : base_iterator(ptr) {}

vhuk::FrankList::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

vhuk::FrankList::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv.ptr) {}

const vhuk::FrankList::const_multi_reverse_iterator& vhuk::FrankList::const_multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::const_multi_reverse_iterator& vhuk::FrankList::const_multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::const_reference vhuk::FrankList::const_multi_reverse_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::const_pointer vhuk::FrankList::const_multi_reverse_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::const_multi_reverse_iterator& vhuk::FrankList::const_multi_reverse_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    if(mode)
    {
        ptr = ptr -> m_prev;
        return *this;
    }
    ptr = ptr -> m_lesser;
    return *this;
}

const vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::const_multi_reverse_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_multi_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

const vhuk::FrankList::const_multi_reverse_iterator& vhuk::FrankList::const_multi_reverse_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    if(mode)
    {
        ptr = ptr -> m_next;
        return *this;
    }
    ptr = ptr -> m_greater;
    return *this;
}

const vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::const_multi_reverse_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    const_multi_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::cmrbegin() const
{
    return const_multi_reverse_iterator(m_tail);
}

vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::cmrend() const
{
    return const_multi_reverse_iterator(nullptr);
}

vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::cmrdbegin() const
{
    return const_multi_reverse_iterator(m_desc);
}

vhuk::FrankList::const_multi_reverse_iterator vhuk::FrankList::cmrdend() const
{
    return const_multi_reverse_iterator(nullptr);
}
void vhuk::FrankList::const_multi_reverse_iterator::chmod()
{
    if(mode)
    {
        mode = false;
        return;
    }
    mode = true;
}

//=============================Multi reverse Iterator============================================
vhuk::FrankList::multi_reverse_iterator::multi_reverse_iterator(Node* ptr) : const_multi_reverse_iterator(ptr) {}

vhuk::FrankList::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv) : const_multi_reverse_iterator(rhv.ptr) {}

vhuk::FrankList::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv) : const_multi_reverse_iterator(rhv.ptr) {}

vhuk::FrankList::reference vhuk::FrankList::multi_reverse_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return ptr->m_data;
}

vhuk::FrankList::pointer vhuk::FrankList::multi_reverse_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range("");
    }
    return &(ptr->m_data);
}

const vhuk::FrankList::multi_reverse_iterator& vhuk::FrankList::multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

const vhuk::FrankList::multi_reverse_iterator& vhuk::FrankList::multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}

vhuk::FrankList::multi_reverse_iterator vhuk::FrankList::mrbegin()
{
    return multi_reverse_iterator(m_tail);
}

vhuk::FrankList::multi_reverse_iterator vhuk::FrankList::mrend()
{
    return multi_reverse_iterator(nullptr);
}

vhuk::FrankList::multi_reverse_iterator vhuk::FrankList::mrdbegin()
{
    return multi_reverse_iterator(m_desc);
}

vhuk::FrankList::multi_reverse_iterator vhuk::FrankList::mrdend()
{
    return multi_reverse_iterator(nullptr);
}








