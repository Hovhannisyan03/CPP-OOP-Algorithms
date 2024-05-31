#include <iostream>

int findMaxIndex(const int* arr, int size)
{
    int index = 0;
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > arr[index])
        {
            index = i;
        }
    }
    return index;
}

void SelectionSort(int *arr, int size)
{
    for(int i = size - 1; i >= 1; --i)
    {
        int maxIndex = findMaxIndex(arr,i+1);
        std::swap(arr[maxIndex], arr[i]);
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

    SelectionSort(arr,size);
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    } 


}