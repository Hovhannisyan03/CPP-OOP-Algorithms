#include <iostream>

int main()
{
    const size_t size = 7;
    int arr[size];

    std::cout << "Enter arr(" << size << "): ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
     
    size_t newSize = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] % 2 == 0)
	{
	    continue;
	}
	for(size_t j = newSize + 1; j < size; ++j)
	{
	    if(arr[j] % 2 == 0)
	    {
	        int tmp = arr[i];
		arr[newSize] = arr[j];
		arr[j] = tmp;
		++i;
		++newSize;
	    }
	}
    }

    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
