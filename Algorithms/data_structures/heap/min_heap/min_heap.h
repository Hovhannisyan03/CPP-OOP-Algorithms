#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>

template <typename T>
class min_heap
{
    private:
        std::vector<T> m_heap;
        int left(int i) const;
        int right(int i) const;
        int parent(int i) const;  

    public:
        min_heap();
        min_heap(const std::vector<T>& v);
        min_heap(const T arr[], int size);
        min_heap(const min_heap& rhv);
        min_heap(min_heap&& rhv) noexcept;
        ~min_heap();

    public:
        min_heap& operator=(const min_heap& rhv);
        min_heap& operator=(min_heap&& rhv) noexcept;

    public:
        void min_heapify(int size, int i);
        void build_min_heap();
        int min() const;
        int extract_min();
        void decrease_key(int i, T key);
        void insert(T val);
        void sort();
        void print() const;
        bool isEmpty() const;
};

#include "min_heap.hpp"
#endif