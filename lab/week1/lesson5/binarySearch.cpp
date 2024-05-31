#include <iostream>

int main()
{
    const size_t size = 5;
    int arr[size];
    std::cout << "Enter array: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
	{
	    if(arr[i] < arr[j])
	    {
	        int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	    }
	}
    }

    int target = 0;
    std::cout << "Enter target: ";
    std::cin >> target;
    size_t left = 0;
    size_t right = size - 1;
    while(left < right)
    {
       mid = (left + right) / 2;
       if(arr[mid] == target)
       {
           std::cout << mid << std::endl;
	   return 0;
       }
       else if(arr[mid] > target)
       {
           --right;
       }
       else 
       {
          ++left;
       }
    }

    std::cout << "Invalid target" << std::endl;
}
