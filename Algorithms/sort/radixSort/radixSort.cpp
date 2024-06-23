#include <iostream>

int getMax(int* arr, int size)
{
    int max = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
} 

void countingSort(int* arr, int size, int exp)
{
    int count[10] = {};

    for(int i = 0; i < size; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    int output[size] = {};

    for(int i = size - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; ++i)
    {
        arr[i] = output[i];
    }
}

void radixSort(int* arr, int size)
{
    int max = getMax(arr,size);
    for(int i = 1; max / i > 0; i *= 10)
    {
        countingSort(arr,size,i);
    }
}

int main()
{
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;
    int *arr = new int[size];

    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    radixSort(arr,size);

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}