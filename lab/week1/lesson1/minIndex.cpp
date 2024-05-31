#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    size_t index;
    int min = INT_MAX;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	if(arr[i] < min)
	{
	    min = arr[i];
	    index = i;
	}
    }
    std::cout << "Min: " << index << std::endl;

    return 0;
}
