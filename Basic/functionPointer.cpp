#include <iostream>

int foo(int *, int size, int (*ptr)(int *));

int change(int *);

int main()
{
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;

    int *arr = new int[size];
    std::cout << "Enter array elements: ";
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    foo(arr,size,change);

    std::cout << "After change: ";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete []arr;
}

int foo(int *arr, int size, int (*ptr)(int *x))
{
    for(int i = 0; i < size; ++i)
    {
        ptr(&arr[i]);
    }
    return 0;
}

int change(int *x)
{
    *x *= 2;
    return 0;
}