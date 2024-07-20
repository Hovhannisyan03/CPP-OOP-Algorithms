#include <iostream>
#include <cstdlib> 
#include <ctime>  

// ==================================== MOT ====================================
void medianOfthree(int *arr, int first, int middle, int last)
{
    if(arr[first] > arr[middle])
    {
        std::swap(arr[first], arr[middle]);
    }
    if(arr[middle] > arr[last])
    {
        std::swap(arr[middle], arr[last]);
    }
    if(arr[first] > arr[middle])
    {
        std::swap(arr[first], arr[middle]);
    }

}

int partitionMOT(int *arr, int first, int last)
{
    int middle = first + (last - first) / 2;
    medianOfthree(arr, first, middle, last);
    std::swap(arr[middle], arr[last - 1]);
    int pivotIndex = last - 1;
    int pivot = arr[last - 1];

    int leftIndex = first;
    int rightIndex = last - 2;

    bool done = false;
    while (!done)
    {
        while (arr[leftIndex] < pivot && leftIndex <= rightIndex)
        {
            ++leftIndex;
        }

        while (arr[rightIndex] > pivot && leftIndex <= rightIndex)
        {
            --rightIndex;
        }

        if (leftIndex < rightIndex)
        {
            std::swap(arr[leftIndex], arr[rightIndex]);
            ++leftIndex;
            --rightIndex;
        }
        else
        {
            done = true;
        }
    }

    std::swap(arr[pivotIndex], arr[leftIndex]);
    return leftIndex;
}

// ==================================== Pivot as Last ====================================


int partitionLast(int *arr, int first, int last)
{
    int pivot = arr[last];
    int leftIndex = first;      
    int rightIndex = last - 1;      

    bool done = false;
    while (!done)
    {
        while (arr[leftIndex] < pivot)
        {
            ++leftIndex;
        }

        while (arr[rightIndex] > pivot)
        {
            --rightIndex;
        }

        if (leftIndex < rightIndex)
        { 
            std::swap(arr[leftIndex], arr[rightIndex]);
            ++leftIndex;
            --rightIndex;
        }
        else
        {
            done = true;
        }
    }

    std::swap(arr[leftIndex], arr[last]);
    return leftIndex; 
}

// ==================================== Pivot as First ====================================

int partitionFirst(int *arr, int first, int last)
{
    int pivot = arr[first];
    int leftIndex = first + 1;      
    int rightIndex = last;      

    bool done = false;
    while (!done)
    {
        while(arr[leftIndex] < pivot && leftIndex <= rightIndex)
        {
            ++leftIndex;
        }

        while(arr[rightIndex] > pivot && leftIndex <= rightIndex)
        {
            --rightIndex;
        }

        if (leftIndex < rightIndex)
        { 
            std::swap(arr[leftIndex], arr[rightIndex]);
            ++leftIndex;
            --rightIndex;
        }
        else
        {
            done = true;
        }
    }

    std::swap(arr[rightIndex], arr[first]);
    return rightIndex; 
}

// ==================================== Pivot as Random ====================================
int random_pivot(int first, int last) 
{
    return first + rand() % (last - first + 1);
}

int partitionRandom(int *arr, int first, int last)
{
    int pivotIndex = random_pivot(first,last);
    std::swap(arr[pivotIndex], arr[last]);
    int pivot = arr[last];
    int leftIndex = first;      
    int rightIndex = last - 1;      

    bool done = false;
    while (!done)
    {
        while (arr[leftIndex] < pivot && leftIndex <= rightIndex)
        {
            ++leftIndex;
        }

        while (arr[rightIndex] > pivot && leftIndex <= rightIndex)
        {
            --rightIndex;
        }

        if (leftIndex < rightIndex)
        { 
            std::swap(arr[leftIndex], arr[rightIndex]);
            ++leftIndex;
            --rightIndex;
        }
        else
        {
            done = true;
        }
    }

    std::swap(arr[leftIndex], arr[last]);
    return leftIndex; 
}

void quickSort(int *arr, int first, int last)
{
    if(first < last)
    {
        int pivotIndex = partitionMOT(arr,first,last);
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

int main()
{
    int size = 0;
    std::cin >> size;
    int *arr = new int[size];

    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }    
    quickSort(arr, 0, size - 1);

    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
