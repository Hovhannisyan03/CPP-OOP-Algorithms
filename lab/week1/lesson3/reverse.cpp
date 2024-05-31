#include <iostream>

int main()
{
    const size_t size = 7;
    char arr[size];
    std::cout << "Enter arr: ";
    std::cin<<arr;
    size_t size1 = 0;
    
    while(arr[size1] != '\0')
    {
       ++size1;
    }
    for(size_t i = 0, j = size1 - 1; i < j; ++i,--j)
    {
        char tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
    }

    std::cout << arr << std::endl;
    return 0;
}
