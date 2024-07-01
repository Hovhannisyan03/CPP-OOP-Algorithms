#include <iostream>
#include <vector>

int left(int i);
int right(int i);
int parent(int i);

void max_heapify(std::vector<int>&, int size, int i);
void build_max_heap(std::vector<int>& arr);
void heap_sort(std::vector<int>& arr);
void print(std::vector<int>& arr);


int main() 
{
    std::vector<int> arr = {9,2,45,82,3,6,9,7,4,2,5};
    heap_sort(arr);
    print(arr);
}

int left(int i)
{
    return i*2 + 1;
}

int right(int i)
{
    return i*2 + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void max_heapify(std::vector<int>& arr, int size, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < size && arr[i] < arr[l])
    {
        largest = l;
    }

    if(r < size && arr[largest] < arr[r])
    {
        largest = r;
    }

    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, size, largest);
    }
}

void build_max_heap(std::vector<int>& arr)
{
    for(int i = (arr.size() / 2) - 1; i >= 0; --i)
    {
        max_heapify(arr, arr.size(), i);
    }
}

void heap_sort(std::vector<int>& arr)
{
    build_max_heap(arr);
    for(int i = arr.size() - 1; i > 0; --i)
    {
        std::swap(arr[i], arr[0]);
        max_heapify(arr,i,0);
    }
}

void print(std::vector<int>& arr)
{
    for(auto& elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}