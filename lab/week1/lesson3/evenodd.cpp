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

    int even[size];
    int odd[size];
    size_t even_index = 0;
    size_t odd_index = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] % 2 == 0)
	{
	    even[even_index] = arr[i];
	    ++even_index;
	}
	else
	{
	   odd[odd_index] = arr[i];
	   ++odd_index;
	}
    }
    
    size_t j = 0;
    for(size_t i = 0; i < size; ++i)
    {
       if(i < even_index)
       {
          arr[i] = even[i];
       }
       else
       {
          arr[i] = odd[j];
	  ++j;
       }
    }
    
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
