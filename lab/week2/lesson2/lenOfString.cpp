#include <iostream>

size_t len(char arr[], size_t index)
{
   if(arr[index] == '\0')
   {
       return index;
   } 

   return len(arr, ++index);
}

int main()
{
    const size_t size = 10;
    char arr[size];
    
    std::cout << "Enter arr: ";
    std::cin >> arr;    

    std::cout << len(arr, 0) << std::endl;
    return 0;
}
