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
    if(size <= 1)
    {
        return; 
    }
    int maxIndex = findMaxIndex(arr,size);
    std::swap(arr[maxIndex], arr[size - 1]);
    SelectionSort(arr,size - 1);
    
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