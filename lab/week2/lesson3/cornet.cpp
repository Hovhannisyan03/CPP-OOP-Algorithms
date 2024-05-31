#include <iostream>

int sumOfCorner(int arr[][3], size_t size)
{ 
    int sum = 0;
    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
	{
	    if(i == j)
	    {
	        sum += arr[i][j];
	    } 
	}
    }

    return sum;
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
   

    std::cout << "Sum of corner: " << sumOfCorner(arr, size) << std::endl;

    return 0;
}
