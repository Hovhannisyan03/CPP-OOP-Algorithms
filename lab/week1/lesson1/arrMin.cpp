#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    int min = INT_MAX;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	if(arr[i] < min)
	{
	   min = arr[i];
	}
    }
    std::cout << "Min: " << min << std::endl;

    return 0;
}
