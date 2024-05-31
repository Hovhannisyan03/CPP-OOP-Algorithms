#include <iostream>

void merge(int *arr, int first, int mid, int last)
{
    int tmpArr[last + 1];
    int f1 = first;
    int l1 = mid;
    int f2 = mid + 1;
    int l2 = last;

    int index = f1;
    while((f1 <= l1) && (f2 <= l2))
    {
        if(arr[f1] <= arr[f2])
        {
            tmpArr[index++] = arr[f1++];
        }
        else
        {
            tmpArr[index++] = arr[f2++];
        }
    }

    while(f1 <= l1)
    {
        tmpArr[index++] = arr[f1++];
    }

    while(f2 <= l2)
    {
        tmpArr[index++] = arr[f2++];
    }

    for(index = first; index <= last; ++index)
    {
        arr[index] = tmpArr[index];
    }
}

void mergeSort(int* arr, int size) 
{
    int n = size;

    for (int currSize = 1; currSize <= n - 1; currSize *= 2) 
    {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) 
        {
            int mid = std::min(leftStart + currSize - 1, n - 1);

            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);

            merge(arr, leftStart, mid, rightEnd);
        }
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

    mergeSort(arr,size);
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}