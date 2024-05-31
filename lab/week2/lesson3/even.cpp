#include <iostream>

int sumOfCorner(int arr[][3], size_t size)
{ 
   
    for(size_t i = 0; i < size; ++i)
    {     
	for(size_t j = 0; j < size; ++j)
	{
	    if(i % 2 == 0)
	    {
	        arr[i][j] = 0;
	    }
	}
    }

    return 0;
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
