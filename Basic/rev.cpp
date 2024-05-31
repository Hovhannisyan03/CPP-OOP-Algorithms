
#include <iostream>

void rev(char *, int, int);

int main()
{
    int size = 0;
    std::cout << "Enter string size: ";
    std::cin >> size;

    char *arr = new char[size];

    int first = 0;
    int last = size;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    rev(arr,first,--last);

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    delete []arr;
    return 0;
}

void rev(char *arr,int first, int last)
{
    if(first == last)
    {
        return;
    }
    char tmp = arr[first];
    arr[first] = arr[last];
    arr[last] = tmp;
    rev(arr,++first,--last);
}
