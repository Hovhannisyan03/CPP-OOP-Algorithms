#include <iostream>

int main()
{
    const int size = 2;
    int matrix1[size][size];
    int (*ptr1)[size] = matrix1;
    int det = 0;
    int mul1 = 1;
    int mul2 = 1;

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
       	  if(i == j)
	  {
	     mul1 *= *(*(ptr1 + i) + j);
	  }
	  else
	  {
	     mul2 *= *(*(ptr1 + i) + j);
	  }
       }   
    }

    std::cout << "Determinant: " << mul1 - mul2 << std::endl;
    return 0;
}