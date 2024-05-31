#include <iostream>

char upper(char* arr)
{
    if(*arr >= 'A' && *arr <= 'Z')
    {
        return *arr;
    }   
    return upper(arr + 1);
}

int main()
{
    const size_t size = 10;
    char arr[size];

    std::cout << "Enter str: ";
    std::cin >> arr;

    std::cout << upper(arr) << std::endl;

    return 0;
}

