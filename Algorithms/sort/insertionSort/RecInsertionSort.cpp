#include <iostream>

void insertionSort(int *arr, int size)
{ 
    if (size <= 1)
    {
        return;
    }

    insertionSort(arr, size - 1);

    int last = arr[size - 1];
    int j = size - 2;

    while (j >= 0 && arr[j] > last) 
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int size = 0;
    std::cin >> size;
    int *arr = new int[size];

    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    } 

    insertionSort(arr,size);
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    } 
}