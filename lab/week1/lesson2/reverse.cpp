#include <iostream>

int main()
{
    const size_t size = 6;
    int arr[size];
    std::cout << "Enter array elements: ";
    for(int i = 0; i < size; ++i)
    {   
	std::cin >> arr[i];
    }

    for(int i = size-1; i != -1; --i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
