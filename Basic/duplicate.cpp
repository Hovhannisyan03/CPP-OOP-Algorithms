#include <iostream>

int main()
{
   const int size = 7;
   int arr[size];
   int *ptr = arr;
     
   std::cout << "Enter array elements:(" << size << ")";
   for (int i = 0; i < size; ++i)
   {
      std::cin >> *(ptr + i);
   }

   for (int i = 0; i < size; ++i)
   {
      for(int j = 0; j < size; ++j)
      {
         if(*(ptr + i) < *(ptr + j))
	 {
	    int temp = *(ptr + j);
	    *(ptr + j) = *(ptr + i);
	    *(ptr + i) = temp;
	 }
      }
   }
   
   
   for(int i = 0; i < size; ++i)
   {
      if(*(ptr + i) == *(ptr+i+1))
      {
         std::cout << "True" << std::endl;
	 return 0;
      }
   }
   std::cout << "False" << std::endl;

}