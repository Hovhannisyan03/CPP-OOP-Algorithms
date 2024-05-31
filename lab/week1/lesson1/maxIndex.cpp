#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    size_t index = 0;
    int max = INT_MIN;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	if(arr[i] > max)
	{  max = arr[i];
	   index = i;
	}
    }
    std::cout << "Max index: " << index << std::endl;

    return 0;
}
