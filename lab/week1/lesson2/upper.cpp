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
        if(arr[i] >= 'a' && arr[i] <= 'z')
	{
	   arr[i] -= 32;
	}
	++i;
    }    
    std::cout << arr << std::endl;
}
