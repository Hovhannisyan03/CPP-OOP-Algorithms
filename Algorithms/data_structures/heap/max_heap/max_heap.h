#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>

template <typename T>
class max_heap
{
    private:
        std::vector<T> m_heap;
        int left(int i) const;
        int right(int i) const;
        int parent(int i) const;  

    public:
        max_heap();
        max_heap(const std::vector<T>& v);
        max_heap(const T arr[], int size);
        max_heap(const max_heap& rhv);
        max_heap(max_heap&& rhv) noexcept;
        ~max_heap();

    public:
        max_heap& operator=(const max_heap& rhv);
        max_heap& operator=(max_heap&& rhv) noexcept;

    public:
        void max_heapify(int size, int i);
        void build_max_heap();
        int max() const;
        int extract_max();
        void increase_key(int i, T key);
        void insert(T val);
        void sort();
        void print() const;
        bool isEmpty() const;
};

#include "max_heap.hpp"
#endif