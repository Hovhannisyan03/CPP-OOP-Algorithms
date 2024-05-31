#include <iostream>

int main()
{
    const size_t size = 7;
    int arr[size];

    std::cout << "Enter arr: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    if(size % 2 == 0)
    {
        std::cout << "There is no unique element" << std::endl;
    }
    for(size_t i = 0; i < size - 1; i += 2)
    {   
	if(i == size - 2)
	{
		std::cout << arr[size - 1] << std::endl;
		return 0;
	}
        if(arr[i] != arr[i + 1])
	{
	    std::cout << arr[i] << std::endl;
	    return 0;
	}
    }

    return 0;
}
