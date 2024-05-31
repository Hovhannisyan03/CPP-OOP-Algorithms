#include <iostream>

int swop(int arr[][3], size_t size)
{ 
    int sum = 0;
    for(size_t i = 0; i < size; ++i)
    {    
	 int tmp = arr[i][i];
	 arr[i][i] = arr[i][size - 1 - i]; 
         arr[i][size - 1 - i] = tmp;
	
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
   
    swop(arr, size);

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
