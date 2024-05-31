#include <iostream>

void reverse(char arr[])
{
    size_t size = 0;
    while(arr[size] != '\0')
    {
       ++size;
    }
    --size;
    for(size_t i = 0; i < size; ++i,--size)
    {
        char tmp = arr[i];
	arr[i] = arr[size];
	arr[size] = tmp;
    }
}

int main()
{
    const size_t size = 6;
    char arr[size];
    std::cin >> arr;

    reverse(arr);
    std::cout << arr << std::endl;
}
