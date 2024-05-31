#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    int max = INT_MIN;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	if(arr[i] > max)
	{
	   max = arr[i];
	}
    }
    std::cout << "Max: " << max << std::endl;

    return 0;
}
