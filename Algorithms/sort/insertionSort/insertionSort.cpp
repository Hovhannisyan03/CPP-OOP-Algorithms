#include <iostream>


void insertionSort(int* arr, int size)  
{
    for(int i = 1; i < size; ++i)
    {
        int nextItem = arr[i];
        int loc = i;
        while((loc > 0) && (arr[loc - 1] > nextItem))
        {
            arr[loc] = arr[loc - 1];
            --loc;
        }

        arr[loc] = nextItem;
    }
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