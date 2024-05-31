#include <iostream>

int main()
{
    const size_t size = 10;
    char arr[size];
    std::cout << "Enter arr: ";
    std::cin >> arr;
    
    for(size_t i = 0; arr[i] != '\0'; ++i)
    {   
        int count = 0;
        for(size_t j = i + 1; arr[j] != '\0'; ++j)
        {
            if(arr[i] == arr[j])
            {
	        arr[j] = ' ';
	        ++count;
	    }
        } 
        if(count != 0)
        {
            arr[i] = ' ';
        }
    }
    
    size_t newSize = 0;
    for(size_t i = 0; arr[i] != '\0'; ++i)
    {  
       if(arr[i] != ' ')
       {   ++newSize;
           continue;
       }
       for(size_t j = newSize + 1; arr[j] != '\0'; ++j)
       {
           if(arr[i] != arr[j])
	   {
	      arr[newSize] = arr[j];
	      arr[j] = ' ';
	      ++newSize;
	      ++i;
	   }
       }
    }
    arr[newSize] = '\0';
    std::cout << arr; 
}
