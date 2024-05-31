#include <iostream>


bool foo(int arr1[], int arr2[], size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
       if(arr1[i] != arr2[i])
       {
           return false;
       }
    }

    return true;
}
int main()
{
    const size_t size = 7;
    int arr1[size];
    int arr2[size];

    std::cout << "Enter arr1(" << size << "): ";
    for(size_t i = 0; i < size; ++i){
        std::cin >> arr1[i];
    }
    
    std::cout << "Enter arr2(" << size << "): ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr2[i];
    }

    std::cout << foo(arr1,arr2,size) << std::endl;
    return 0;

}
