#include <iostream>

int main()
{
    const int size = 3;
    int matrix1[size][size];
    int (*ptr1)[size] = matrix1;

    std::cout << "Enter first matrix elements\n";
    for(int i = 0; i < size; ++i)
    {  
       for(int j = 0; j < size; ++j){
          std::cin >> *(*(ptr1 + i) + j);
       }
    }
    
    int other = 0;
    int zero = 0;

    for(int i = 0; i < size; ++i)
    {  
       for(int j = 0; j < size; ++j)
       {  
	  if(*(*(ptr1 + i) + j) == 0 && i!=j)
	  {
	     zero++;
          }	
       }

       if(*(*(ptr1 + i) + i) != 0)
       {  
          other++;
       }
    }


    if((zero == size*size-size) && other == size)
    {
       std::cout << "True";
    }
    else 
    {
       std::cout << "False";
    }
    std::cout << std::endl;
    return 0;
}