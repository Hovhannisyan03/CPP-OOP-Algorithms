#include <iostream>

void bubbleSort(int arr[], int size)
{
    bool sorted = false;
    int pass = 1;

    while(!sorted && (pass < size))
    {
        sorted = true;
        for(int i = 0; i < size - pass; ++i)
        {
            if(arr[i] > arr[i + 1])
            {
                std::swap(arr[i],arr[i + 1]);
                sorted = false;
            }
        }
        ++pass;
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

    bubbleSort(arr,size);
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    } 

}