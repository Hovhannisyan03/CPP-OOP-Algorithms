#include <iostream>

int main()
{
    const size_t size = 8;
    char arr[size];
    std::cout << "Enter arr: ";
    std::cin >> arr;
    
    size_t i = 0;
    while(arr[i] != '\0')
    {
        if(arr[i] >= '0' && arr[i] <= '9')
	{
	    std::cout << arr[i] << " "; 
	}
	++i;
    }
    std::cout << std::endl;
    return 0;
}
