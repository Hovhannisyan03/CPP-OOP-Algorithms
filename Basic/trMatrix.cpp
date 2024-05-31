#include <iostream>

int main()
{
    const int size = 3;
    int matrix1[size][size];
    int tr[size][size];
    int (*ptr1)[size] = matrix1;
    int (*trP)[size] = tr;

    std::cout << "Enter first matrix elements\n";
    for(int i = 0; i < size; ++i)
    {  
       for(int j = 0; j < size; ++j){
          std::cin >> *(*(ptr1 + i) + j);
       }
    }
    
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {  
	  *(*(trP + j) + i) = *(*(ptr1 + i) + j);
       }
       std::cout << "\n";
    }
    
    std::cout << "Matrix transposition\n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          std::cout << *(*(trP + i) + j) << " ";
       }

       std::cout << "\n";
    }

    std::cout << std::endl;
    return 0;
}