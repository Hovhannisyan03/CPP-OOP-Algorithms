#include <iostream>

int main()
{
    const size_t size1 = 3;
    const size_t size2 = 2;
    int arr1[size1];
    int arr2[size2];

    std::cout << "Enter arr(" << size1 << "): ";
    for(size_t i = 0; i < size1; ++i)
    {
        std::cin >> arr1[i];
    }

    std::cout << "Enter arr(" << size2 << "): ";
    for(size_t i = 0; i < size2; ++i)
    {
        std::cin >> arr2[i];
    }
    
    for(size_t size = size1 + size2 - 1, i = size1 - 1, j = size2 - 1; size != -1; --size)
    {
        if(i >= 0)
	{
	    std::cout << arr1[i] << " ";
	    --i;
	}
	else 
	{
	    std::cout << arr2[j] << " ";
	    --j;
	}
    }
}
