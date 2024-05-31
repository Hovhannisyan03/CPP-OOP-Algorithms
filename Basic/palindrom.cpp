#include <iostream>

int palindrome(char *, int, int);

int main()
{   
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cin.get();

    char *arr = new char[size];
    std::cout << "Enter string: ";
    std::cin.getline(arr,size);

    std::cout << palindrome(arr,0,size-2) << std::endl;
    delete []arr;
}

int palindrome(char *arr, int first, int size)
{
    if(first > size)
    {
        return 1;
    }
    if(arr[first] != arr[size])
    {
        return 0;
    }
    return palindrome(arr,++first,--size);

}