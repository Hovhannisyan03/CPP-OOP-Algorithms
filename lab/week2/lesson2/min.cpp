#include <iostream>

int min(int a, int b)
{
    return a > b ? b : a;
}


int Min(size_t size, int arr[])
{   
    if(size == 1)
    {
        return arr[0];
    }
    return min(arr[size - 1], Min(size - 1, arr));
}

int main()
{
    const int size = 5;
    int arr[size];
    std::cout << "Enter arr: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Min is: " << Min(size, arr) << std::endl;
    return 0;
}
