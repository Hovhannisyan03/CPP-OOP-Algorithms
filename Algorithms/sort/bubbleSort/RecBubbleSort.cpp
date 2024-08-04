#include <iostream>


void bubbleSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }

    bool sorted = sorted;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            std::swap(arr[i], arr[i + 1]);
            sorted = false;
        }
    }

    if(sorted)
    {
        return;
    }
    bubbleSort(arr, size - 1);
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

    bubbleSort(arr,size);
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    } 
}
