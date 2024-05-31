#include <iostream>

int main()
{
    const size_t size = 4;
    int arr[size][size];
    std::cout << "Enter matrix " << size << "x" << size << std::endl;

    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
	{
            if(i % 2 == 0)
	    {
	        std::cin >> arr[j][i];
	    }
	    if(i % 2 == 1)
	    {
	       std::cin >> arr[size - 1 - j][i];
	    }
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
