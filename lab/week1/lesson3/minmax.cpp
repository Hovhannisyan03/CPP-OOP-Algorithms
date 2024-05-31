#include <iostream>
#include <limits.h>

int main()
{
    const size_t size = 7;
    int arr[size];
    std::cout << "Enter arr: ";
    for(int i = 0; i < size; ++i){
        std::cin >> arr[i];
    }
    
    int min = INT_MAX;
    int max = INT_MIN;
    int minIndex = 0;
    int maxIndex = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] > max)
	{
	   max = arr[i];
	   maxIndex = i;
	}
	if(arr[i] < min)
	{
	   min = arr[i];
	   minIndex = i;
	}
    }

    std::cout << maxIndex - minIndex << std::endl;
}
