#include <iostream>

int main()
{
    const int size = 3;
    int matrix1[size][size];
    int matrix2[size][size];
    int (*ptr1)[size] = matrix1;
    int (*ptr2)[size] = matrix2;

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

    std::cout << "Matrix subtractiovn \n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {  
	  *(*(ptr1 + i) + j) -= *(*(ptr2 + i) + j);
          std::cout << *(*(ptr1 + i) + j) << " ";
       }
       std::cout << "\n";
    }

    std::cout << std::endl;
    return 0;
}