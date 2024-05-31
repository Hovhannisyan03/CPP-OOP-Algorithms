#include <iostream>

int max(int a, int b)
{
    return a > b ? a : b;
}


int Max(size_t size, int arr[])
{   
    if(size == 1)
    {
        return arr[0];
    }
    return max(arr[size - 1], Max(size - 1, arr));
}

int main()
{
    const int size = 8;
    int arr[size];
    std::cout << "Enter arr: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Max is: " << Max(size, arr) << std::endl;

    return 0;
}
