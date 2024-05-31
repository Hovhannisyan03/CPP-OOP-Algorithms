#include <iostream>

int main()
{
    const size_t size = 7;
    int arr1[size];
    int arr2[size];
    std::cout << "Enter first array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr1[i];
    }
    std::cout << "Enter second array elements(" << size << "): " << std::endl;
    int arr3[size];
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr2[i];
	arr3[i] = arr1[i] * arr2[i];
    }
    
    std::cout << "Result: ";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr3[i] << " "; 

    }
    std::cout << std::endl;
    return 0;
}
