#include <iostream>

int main()
{
    const int size = 3;
    int matrix1[size][size];
    int matrix2[size][size];
    int mul[size][size];
    int (*ptr1)[size] = matrix1;
    int (*ptr2)[size] = matrix2;
    int (*mulP)[size] = mul;

    //*(*(ptr+i)+j)
    std::cout << "Enter first matrix elements\n";
    for(int i = 0; i < size; ++i)
    {  
       for(int j = 0; j < size; ++j){
          std::cin >> *(*(ptr1 + i) + j);
       }
    }
    
    std::cout << "Enter second matrix elements\n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j){
          std::cin >> *(*(ptr2 + i) + j);
       }
    }
    
    int temp = 0;

    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {  
	  for(int k = 0; k < size; ++k)
	  { 
	     temp += (*(*(ptr1 + i) + k)) * (*(*(ptr2 + k) + j)); 
	  }
	  *(*(mulP + i) + j) = temp;
	  temp = 0;
       }
    }
    
    std::cout << "Matrix multiplication \n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          std::cout << *(*(mulP + i) + j) << " ";
       }
       std::cout << "\n";
    }

    std::cout << std::endl;
    return 0;
}