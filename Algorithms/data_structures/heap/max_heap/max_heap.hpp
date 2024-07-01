#include "max_heap.h"

template <typename T>
max_heap<T>::max_heap() : m_heap(){}

template <typename T>
max_heap<T>::max_heap(const std::vector<T>& heap) : m_heap()
{
    for(auto& elem : heap)
    {
        m_heap.push_back(elem);
    }
}

template <typename T>
max_heap<T>::max_heap(const T arr[], int size) : m_heap()
{
    for(int i = 0; i < size; ++i)
    {
        m_heap.push_back(arr[i]);
    }
}

template <typename T>
max_heap<T>::max_heap(const max_heap& rhv) : m_heap(rhv.m_heap){}

template <typename T>
max_heap<T>::max_heap(max_heap&& rhv) noexcept : m_heap{rhv.m_heap}
{
    rhv.m_heap = nullptr;
}

template <typename T>
max_heap<T>& max_heap<T>::operator=(const max_heap& rhv) 
{
    if (this != &rhv) {
        m_heap = rhv.m_heap;
    }
    return *this;
}

template <typename T>
max_heap<T>& max_heap<T>::operator=(max_heap&& rhv) noexcept 
{
    if (this != &rhv) {
        m_heap = move(m_heap.rhv);
    }
    return *this;
}

template <typename T>
max_heap<T>::~max_heap()
{
    m_heap.clear();
}


template <typename T>
int max_heap<T>::left(int i) const
{ 
    return i*2 + 1;
}

template <typename T>
int max_heap<T>::right(int i) const
{
    return i*2 + 2;
}

template <typename T>
int max_heap<T>::parent(int i) const
{
    return (i - 1) / 2;
}

template <typename T>
void max_heap<T>::max_heapify(int size, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < size && m_heap[i] < m_heap[l])
    {
        largest = l;
    }

    if(r < size && m_heap[largest] < m_heap[r])
    {
        largest = r;
    }

    if(largest != i)
    {
        std::swap(m_heap[i], m_heap[largest]);
        max_heapify(size, largest);
    }
}

template <typename T>
void max_heap<T>::build_max_heap()
{
    for(int i = (m_heap.size() / 2) - 1; i >= 0; --i)
    {
        max_heapify(m_heap.size(), i);
    }
}

template <typename T>
int max_heap<T>::max()const
{
    return m_heap[0];
}

template <typename T>
int max_heap<T>::extract_max()
{
    if(m_heap.size() < 0)
    {
        throw std::logic_error("Array is empty");
    }
    int max = m_heap[0];
    m_heap[0] = m_heap.back();
    m_heap.pop_back();
    max_heapify(m_heap.size(),0);

    return max;
}

template <typename T>
void max_heap<T>::increase_key(int i, T key)
{   
    if(i >= m_heap.size() && key <= m_heap[i])
    {
        throw std::invalid_argument("Invalid argumnet");
    }

    m_heap[i] = key;
    while(i > 0 && m_heap[parent(i)] < m_heap[i])
    {
        std::swap(m_heap[parent(i)], m_heap[i]);
        i = parent(i);
    }
}

template <typename T>
void max_heap<T>::insert(T val)
{
    m_heap.push_back(INT_MIN);
    increase_key(m_heap.size() - 1, val);
}

template <typename T>
void max_heap<T>::sort()
{
    build_max_heap();
    for(int i = m_heap.size() - 1; i > 0; --i)
    {
        std::swap(m_heap[i], m_heap[0]);
        max_heapify(i,0);
    }
}

template <typename T>
void max_heap<T>::print() const
{
    for(auto& elem : m_heap)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool max_heap<T>::isEmpty() const
{
    return m_heap.empty();
}