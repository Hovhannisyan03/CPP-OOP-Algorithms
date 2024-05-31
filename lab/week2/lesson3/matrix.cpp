#include <iostream>

int main()
{
    const size_t size = 3;
    int arr[size][size];
    std::cout << "Enter matrix " << size << "x" << size << std::endl;

    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
	{
	    std::cin >> arr[i][j];
	}
    }

    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
	{
	    std::cout << arr[i][j] << " "; 
	}
	std::cout << std::endl;
    }

    return 0;
}
