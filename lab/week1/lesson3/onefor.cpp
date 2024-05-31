#include <iostream>

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
    
  
    for(size_t i = 0, j = 0; i < 2*size; ++i)
    {
        if(i < size)
	{
	    std::cout << arr1[i] << " ";
	}  
	else
	{   
	    if(i == size)
	    {
	        std::cout << std::endl;
	    }
	    std::cout << arr2[j] << " ";
	    ++j;
	}
    }

    std::cout << std::endl;
    return 0;

}
