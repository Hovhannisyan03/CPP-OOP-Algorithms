#include "vector.h"

template <typename T>
vector<T>::vector() : m_arr{nullptr}, m_size{0}, m_capacity{0} {}

template <typename T>
vector<T>::~vector()
{
    clear();
}

template <typename T>
vector<T>::vector(const vector& rhv) :  m_arr(new value_type[rhv.m_capacity]),  m_size(rhv.m_size), m_capacity(rhv.m_capacity)
{
    for(size_type i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhv.m_arr[i];
    }
}

template <typename T>
vector<T>::vector(vector&& rhv) noexcept : m_arr{rhv.m_arr}, m_size{rhv.m_size}, m_capacity{rhv.m_capacity} 
{
    rhv.m_arr = nullptr;
    rhv.m_size = 0;
    rhv.m_capacity = 0;
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> init) : m_arr(new value_type[init.size()]),  m_size(init.size()), m_capacity(init.size())
{
    size_type i = 0;
    for (auto& elem : init) 
    {
        m_arr[i++] = elem;
    }
}

template <typename T>
vector<T>::vector(size_type size, const_reference val) : m_arr(new value_type[size]),  m_size(size), m_capacity(size)
{
    for(size_type i = 0; i < m_size; ++i)
    {
        m_arr[i] = val;
    }
}

template <typename T>
template <typename InputIt>
vector<T>::vector(InputIt first, InputIt last) : m_arr{nullptr}, m_size{0}, m_capacity{0}
{
    for (auto it = first; it != last; ++it) 
    {
        push_back(*it);
    }
}

template <typename T>
const vector<T>& vector<T>::operator=(const vector& rhv)
{
    if(this == &rhv)
    {
        return *this;
    }
    clear();
    reserve(rhv.m_capacity);
    m_size = rhv.m_size;    
    for(size_type i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhv.m_arr[i];
    }
    return *this;
}

template <typename T>
const vector<T>& vector<T>::operator=(vector&& rhv) noexcept
{
    if(this == &rhv)
    {
        return *this;
    }

    m_arr = rhv.m_arr;
    m_size = rhv.m_size;
    m_capacity = rhv.m_capacity;

    rhv.m_arr = nullptr;
    rhv.m_size  = 0;
    rhv.m_capacity = 0;

    return *this;
}

template <typename T>
const vector<T>& vector<T>::operator=(std::initializer_list<value_type> init)
{
    clear();
    reserve(init.size());
    m_size = init.size();
    size_type i = 0;
    for(auto& elem : init)
    {
        m_arr[i++] = elem;
    }

    return *this;
}

template <typename T>
void vector<T>::reserve(size_type new_cap)
{
    m_capacity = new_cap;
    pointer new_arr = new value_type[new_cap];
    for(size_type i = 0; i < m_size; ++i)
    {
        new_arr[i] = m_arr[i];
    }
    delete []m_arr;
    m_arr = new_arr;
}

template <typename T>
void vector<T>::clear()
{
    delete []m_arr;
    m_arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos)
{
    if(pos < m_size)
    {
        return m_arr[pos];
    }
    throw std::out_of_range("Out of range");
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const
{
    if(pos < m_size)
    {
        return m_arr[pos];
    }
    throw std::out_of_range("Out of range");
}

template <typename T>
typename vector<T>::reference vector<T>::front()
{
    if(m_size != 0)
    {
        return m_arr[0];
    }
    throw std::logic_error("Vector is empty");
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const
{
    if(m_size != 0)
    {
        return m_arr[0];
    }
    throw std::logic_error("Vector is empty");
}

template <typename T>
typename vector<T>::reference vector<T>::back()
{
    if(m_size != 0)
    {
        return m_arr[m_size - 1];
    }
    throw std::logic_error("Vector is empty");
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const
{
    if(m_size != 0)
    {
        return m_arr[m_size - 1];
    }
    throw std::logic_error("Vector is empty");
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos)
{
    return m_arr[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const
{
    return m_arr[pos];
}

template <typename T>
typename vector<T>::pointer vector<T>::data()
{
    return m_arr;
}

template <typename T>
typename vector<T>::const_pointer vector<T>::data() const
{
    return m_arr;
}

template <typename T>
void vector<T>::push_back(const_reference value)
{   
    m_capacity = m_capacity == 0 ? 1 : m_capacity;
    if(m_size >= m_capacity || m_size == 0)
    {
        reserve(m_capacity * 2);
    }
    m_arr[m_size] = value;
    ++m_size;
}

template <typename T>
void vector<T>::pop_back()
{   
    if(m_size == 0)
    {
        return;
    }
    --m_size;
}

template <typename T>
void vector<T>::push_front(const_reference value)
{
    m_capacity = m_capacity == 0 ? 1 : m_capacity;
    if (m_size >= m_capacity || m_size == 0) 
    {
        reserve(2 * m_capacity);
    }

    for (size_type i = m_size; i > 0; --i) 
    {
        m_arr[i] = m_arr[i - 1];
    }

    m_arr[0] = value;

    ++m_size;
}

template <typename T>
void vector<T>::pop_front()
{
    if(m_size == 0)
    {
        return;
    }
   
    for (int i = 1; i < m_size; ++i) 
    {
        m_arr[i - 1] = m_arr[i];
    }
    --m_size;
    return;
}

template <typename T>
typename vector<T>::value_type vector<T>::find(value_type val) const
{
    for(size_type i = 0; i < m_size; ++i)
    {
        if(m_arr[i] == val)
        {
            return i;
        }
    }
    throw std::logic_error("No such value exists");
}


template<typename T>
void vector<T>::assign(size_type count, const vector& rhv)
{
    if(m_size < count)
    {
        clear();
        reserve(count);
    }
    m_size = count;
    for(int i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhv.m_arr[i];
    }
}

template <typename T>
void vector<T>::assign(std::initializer_list<value_type> init)
{
    clear();
    reserve(init.size());
    m_size = init.size();
    size_type i = 0;
    for(auto& elem : init)
    {
        m_arr[i++] = elem;
    }
}

template <typename T>
void vector<T>::assign(const_iterator first, const_iterator last)
{
    clear();
    while(first < last)
    {
        push_back(*first);
        ++first;
    }
}

template <typename T>
void vector<T>::reverse()
{   
    value_type j = 1;
    for(int i = 0; i < m_size/2; ++i)
    {
        value_type tmp = m_arr[i];
        m_arr[i] = m_arr[m_size - j];
        m_arr[m_size - j] = tmp;
        ++j;
    } 
}

template <typename T>
bool vector<T>::empty()const
{
    return m_size == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const
{
    return m_size;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
void vector<T>::sort()
{
    size_type pass = 1;
    bool sorted = false;
    while(!sorted && (m_size - pass != 0))
    {
        sorted = true;
        for(size_type i = 0; i < m_size - pass; ++i)
        {
            if(m_arr[i] > m_arr[i + 1])
            {
                std::swap(m_arr[i],m_arr[i+1]);
                sorted = false;
            }
        }
        ++pass;
    }
}

template <typename T>
void vector<T>::shrink_to_fit() 
{
    if (m_size < m_capacity) {
        pointer new_arr = new T[m_size];
        
        for (size_type i = 0; i < m_size; ++i) 
        {
            new_arr[i] = m_arr[i];
        }
        
        delete[] m_arr;
        
        m_arr = new_arr;
        m_capacity = m_size;
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos, const_reference val)
{
    size_type index = 0;
    const_iterator it = cbegin();
    while (it != pos && it != cend()) 
    {
        ++it;
        ++index;
    }

    if (it == pos) 
    {
        insert(index, val);
        return begin() + index + 1;
    }

    return end();
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos, std::initializer_list<value_type> init)
{
    size_type index = 0;
    const_iterator it = cbegin();
    while (it != pos && it != cend()) 
    {
        ++it;
        ++index;
    }
    
    if (it == pos) 
    {   
        for(auto& elem : init)
        {
            insert(index++, elem);
        }
        return begin() + index - init.size();
    }

    return end();
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos, size_type count, const_reference val)
{
    size_type index = 0;
    const_iterator it = cbegin();
    while (it != pos && it != cend()) 
    {
        ++it;
        ++index;
    }   

    if (it == pos) 
    {
        while(count --)
        {
            insert(index, val);
            ++it;
        }
        return begin() + index;
    }

    return end();
}

template <typename T>
template <typename InputIt>
typename vector<T>::iterator vector<T>::insert(const_iterator pos, InputIt first, InputIt last)
{
    size_type index = pos.m_ptr - m_arr;

    size_type i = index;
    while(first != last)
    {
        insert(i, *first);
        ++i;
        ++first;
    }
    return begin() + index;
}

template <typename T>
void vector<T>::insert(size_type index, value_type value)
{
    if (index > m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    if (m_size >= m_capacity) 
    {
        reserve(2 * m_capacity);
    }

    for (size_type i = m_size; i > index; --i) 
    {
        m_arr[i] = m_arr[i - 1];
    }

    m_arr[index] = value;

    ++m_size;
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(const_iterator pos)
{
    if(pos == cbegin())
    {
        pop_front();
        return begin();
    }
    if(pos == cend() - 1)
    {
        pop_back();
        return end() - 1;
    }
    else
    {
        size_type index = pos.m_ptr - m_arr;
        for (size_type i = index; i < m_size - 1; ++i) 
        {
            m_arr[i] = m_arr[i + 1];
        }
        --m_size;
        return begin() + index;
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::const_iterator first, typename vector<T>::const_iterator last)
{
    size_type start = first.m_ptr - m_arr;
    size_type count = last.m_ptr - first.m_ptr;

    for (size_type i = start; i < m_size - count; ++i) 
    {
        m_arr[i] = m_arr[i + count];
    }

    m_size -= count;

    return m_arr + start;
}

template <typename T>
void vector<T>::resize(size_type count, const_reference val)
{
    if(count != m_size)
    {
        if(count < m_size)
        {
            m_size = count;
        }
        else
        {
            if(count < m_capacity)
            {
                for(size_type i = m_size; i < count; ++i)
                {
                    m_arr[i] = val;
                }
                m_size = count;
            }
            else
            {
                reserve(count);
                for(size_type i = m_size; i < count; ++i)
                {
                    m_arr[i] = val;
                }
                m_size = count;
            }
        }
    }
}

template <typename T>
bool vector<T>::operator==(const vector& rhv) const
{
    if(m_size != rhv.m_size)
    {
        return false;
    }
    for(size_type i = 0; i < m_size; ++i)
    {
        if(m_arr[i] != rhv[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool vector<T>::operator!=(const vector& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool vector<T>::operator<(const vector& rhv) const
{
    size_type size = m_size > rhv.m_size ? rhv.m_size : m_size;
    for(size_type i = 0; i < size; ++i)
    {
        if(m_arr[i] < rhv[i])
        {
            return true;
        }
        else if(m_arr[i] > rhv[i])
        {
            return false;
        }
    }

    return m_size < rhv.m_size;
}

template <typename T>
bool vector<T>::operator<=(const vector& rhv) const
{
    return  (*this < rhv) || (*this == rhv);
}

template <typename T>
bool vector<T>::operator>(const vector& rhv) const
{
    return  !(*this <= rhv);
}

template <typename T>
bool vector<T>::operator>=(const vector& rhv) const
{
    return  (*this > rhv) || (*this == rhv);
}

// ================================================== Const Iterator ==================================================
template<typename T>
vector<T>::const_iterator::const_iterator(pointer ptr) : m_ptr{ptr} {}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator+(size_type n) const
{
    return const_iterator(m_ptr + n);
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator-(size_type n) const
{
    return const_iterator(m_ptr - n);
}

template<typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator++()
{
    ++m_ptr;
    return *this;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator--()
{
    --m_ptr;
    return *this;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator--(int)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
typename vector<T>::const_reference vector<T>::const_iterator::operator*() const
{
    return *m_ptr;
}

template<typename T>
typename vector<T>::const_pointer vector<T>::const_iterator::operator->() const
{
    return m_ptr;
}

template<typename T>
typename vector<T>::const_reference vector<T>::const_iterator::operator[](size_type pos) const
{
    return m_ptr[pos];
}

template<typename T>
bool vector<T>::const_iterator::operator==(const const_iterator& rhv) const
{
    return m_ptr == rhv.m_ptr;
}

template<typename T>
bool vector<T>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return m_ptr != rhv.m_ptr;
}

template<typename T>
bool vector<T>::const_iterator::operator<(const const_iterator& rhv) const
{
    return m_ptr < rhv.m_ptr;
}

template<typename T>
bool vector<T>::const_iterator::operator<=(const const_iterator& rhv) const
{
    return m_ptr <= rhv.m_ptr;
}

template<typename T>
bool vector<T>::const_iterator::operator>(const const_iterator& rhv) const
{
    return m_ptr < rhv.m_ptr;
}

template<typename T>
bool vector<T>::const_iterator::operator>=(const const_iterator& rhv) const
{
    return m_ptr <= rhv.m_ptr;
}


template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const noexcept
{
    return const_iterator(m_arr);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const noexcept
{
    return const_iterator(m_arr + m_size);
}

// ================================================== Iterator ==================================================
template <typename T>
vector<T>::iterator::iterator(pointer ptr) : const_iterator(ptr) {}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator+(size_type n) const
{
    return iterator(this->m_ptr + n);
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator-(size_type n) const
{
    return iterator(this->m_ptr - n);
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
    ++this->m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
    iterator tmp = this->m_ptr;
    ++(*this);
    return tmp;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--()
{
    --this->m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator--(int)
{
    iterator tmp = this->m_ptr;
    --(*this);
    return tmp;
}

template <typename T>
typename vector<T>::reference vector<T>::iterator::operator*()
{
    return *this->m_ptr;
}

template <typename T>
typename vector<T>::pointer vector<T>::iterator::operator->()
{
    return this->m_ptr;
}

template <typename T>
typename vector<T>::reference vector<T>::iterator::operator[](size_type pos) const
{
    return this->m_ptr[pos];
}

template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
    return iterator(m_arr);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept
{
    return iterator(m_arr + m_size);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const
{
    return const_iterator(m_arr);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const noexcept
{
    return const_iterator(m_arr + m_size);
}

// ================================================== Const Reverse Iterator ==================================================
template <typename T>
vector<T>::const_reverse_iterator::const_reverse_iterator(pointer ptr) : m_ptr{ptr}{}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator+(size_type n) const
{
    return const_reverse_iterator(m_ptr - n);
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator-(size_type n) const
{
    return const_reverse_iterator(m_ptr + n);
}

template <typename T>
typename vector<T>::const_reverse_iterator& vector<T>::const_reverse_iterator::operator++()
{
    --m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator++(int)
{
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
} 

template <typename T>
typename vector<T>::const_reverse_iterator& vector<T>::const_reverse_iterator::operator--()
{
    ++m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator--(int)
{
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
} 

template <typename T>
typename vector<T>::const_reference vector<T>::const_reverse_iterator::operator*() const
{
    return *m_ptr;
}

template <typename T>
typename vector<T>::const_pointer vector<T>::const_reverse_iterator::operator->()const
{
    return m_ptr;    
}

template <typename T>
typename vector<T>::const_reference vector<T>::const_reverse_iterator::operator[](size_type pos) const
{
    return m_ptr[pos];
}

template <typename T>
bool vector<T>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const
{
    return m_ptr == other.m_ptr;
}    

template <typename T>
bool vector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const
{
    return m_ptr != other.m_ptr;
}  

template <typename T>
bool vector<T>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const
{
    return m_ptr < other.m_ptr;
}  

template <typename T>
bool vector<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const
{
    return m_ptr <= other.m_ptr;
}  

template <typename T>
bool vector<T>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const
{
    return m_ptr > other.m_ptr;
}  

template <typename T>
bool vector<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const
{
    return m_ptr >= other.m_ptr;
}  

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::crbegin() const noexcept
{
    return const_reverse_iterator(m_arr + m_size - 1);
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::crend() const noexcept
{
    return const_reverse_iterator(m_arr - 1);
}

// ================================================== Reverse Iterator ==================================================

template <typename T>
vector<T>::reverse_iterator::reverse_iterator(pointer ptr) : const_reverse_iterator(ptr){}

template <typename T>
const typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator=(const reverse_iterator& rhv)
{
    if(this != &rhv)
    {
        this->m_ptr = rhv.m_ptr;
    }
    return *this;
}  

template <typename T>
const typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator=(reverse_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->m_ptr = rhv.m_ptr;
        rhv.m_ptr = nullptr;
    }
    return *this;
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator+(size_type n) const
{
    return reverse_iterator(this->m_ptr - n);
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator-(size_type n) const
{
    return reverse_iterator(this->m_ptr + n);
}

template <typename T>
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator++()
{
    --this->m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator++(int)
{
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator--()
{
    ++this->m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator--(int)
{
    reverse_iterator tmp = *this;
    --this->m_ptr;
    return tmp;
}

template <typename T>
typename vector<T>::reference vector<T>::reverse_iterator::operator*()
{
    return *this->m_ptr;
}

template <typename T>
typename vector<T>::pointer vector<T>::reverse_iterator::operator->()
{
    return this->m_ptr;
}

template <typename T>
typename vector<T>::reference vector<T>::reverse_iterator::operator[](size_type pos)const
{
    return this->m_ptr[pos];
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
{
    return reverse_iterator(m_arr + m_size - 1);
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rend() const
{
    return reverse_iterator(m_arr - 1);
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::rbegin()
{
    return reverse_iterator(m_arr + m_size - 1);
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::rend()
{
    return reverse_iterator(m_arr - 1);
}

