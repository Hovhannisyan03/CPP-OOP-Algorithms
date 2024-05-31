#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	if(arr[i] < min)
	{
	    min = arr[i];
	}
	if(arr[i] > max)
	{
	    max = arr[i];
	}
    }
    std::cout << "Sum: " << min + max << std::endl;

    return 0;
}
