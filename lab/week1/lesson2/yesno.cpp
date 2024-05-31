#include <iostream>

int main()
{
    const size_t size = 6;
    int arr[size];
    std::cout << "Enter array elements: ";
    for(int i = 0; i < size; ++i)
    {   
	std::cin >> arr[i];
    }
    
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;

    for(int i = 0; i < size; ++i)
    {
        if(num == arr[i])
	{
	   std::cout << "YES" << std::endl;
	   return 0;
	}    
    }
    std::cout << "No" << std::endl;
    return 0;
}
