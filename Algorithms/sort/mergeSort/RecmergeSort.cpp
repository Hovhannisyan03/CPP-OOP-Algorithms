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

void mergeSort(int *arr, int first, int last)
{
    if(first < last)
    {
        int mid = first + (last - first) / 2;
        mergeSort(arr,first, mid);
        mergeSort(arr,mid + 1, last);
        merge(arr,first,mid,last);
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

    mergeSort(arr,0,size - 1);
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}