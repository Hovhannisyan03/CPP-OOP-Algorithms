#include <iostream>


char* foo(char *arr, size_t index)
{    
    size_t size = 0;
    while(arr[size] != '\0')
    {
        ++size;
    }
    if(size < index)
    {
        return arr;
    }
    for(size_t i = 0; i < size; ++i)
    {
        if(i == index)
	{
	   arr[i] = '\0';
	   size_t j = i + 1;
	   while(j <= size)
	   {
	       char tmp = arr[i];
	       arr[i] = arr[j];
	       arr[j] = tmp;
	       ++i;
	       ++j;
	   }
	   break;
	}
    }
    return arr;
}

int main()
{
    const size_t size = 7;
    char arr[size];
    std::cin >> arr;
    
    size_t index = 0;
    std::cout << "Enter index: ";
    std::cin >> index;
    char *ptr = foo(arr,index);
    std::cout << ptr << std::endl;
}
