#include <iostream>

void sumOfCorner(int arr[][3], size_t size)
{ 
    int sum = 0;
    for(size_t i = 0; i < size; ++i)
    {     
	for(size_t j = 0; j < size; ++j)
	{
	    if(i % 2 == 0)
	    {
		std::cout << arr[i][j] << " ";
	    }
	    else 
	    {
	        std::cout << arr[i][size - 1 - j] << " ";
	    }
	}
	std::cout << std::endl;
    }

    return ;
}

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
   
    sumOfCorner(arr, size);

    return 0;
}
