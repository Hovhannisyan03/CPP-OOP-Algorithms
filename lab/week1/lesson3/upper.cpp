#include <iostream>

int main()
{
    const size_t size = 7;
    char arr[size];
    std::cout << "Enter arr: ";
    std::cin >> arr;

    for(size_t i = 0; arr[i] != '\0'; ++i)
    {
        if(arr[i] >= 'a' && arr[i] <= 'z')
	{
	    arr[i] -= 32;
	}
    }

    std::cout << arr << std::endl;
}
