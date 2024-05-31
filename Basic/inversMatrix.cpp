#include <iostream>

int main()
{
    const int size = 2;
    double matrix1[size][size];
    double (*ptr1)[size] = matrix1;
    double mul1 = 1;
    double mul2 = 1;

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
    
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          if(i == j)
	  {
	     double temp = *(*(ptr1 + i) + j);
             *(*(ptr1 + i) + j) = *(*(ptr1 + i + 1) + j + 1);
             *(*(ptr1 + i + 1) + j + 1) = temp;
	     break;
	  }else 
	  {
	     *(*(ptr1 + i) + j) *= -1;
             *(*(ptr1 + j) + i) *= -1;
	     break;
	  }
       }
    }

    if(mul1 - mul2 == 0)
    {
       std::cout << "Invalid input" << std::endl;
    }
    else 
    {
       for(int i = 0; i < size; ++i)
       {
          for(int j = 0; j < size; ++j)
          {  
	     *(*(ptr1 + i) + j) /= (mul1 - mul2);
	     std::cout << *(*(ptr1 + i) + j) << " ";
          }
          std::cout << "\n";
       }
    }

    std::cout << std::endl;
    return 0;
}