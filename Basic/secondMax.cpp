#include <iostream>
#include <limits.h>

int main()
{
   const int size = 8;
   int arr[size];
   int *arrP = arr;
   int max1 = INT_MIN;
   int max2 = INT_MIN;

   std::cout << "Enter array elements: ";
   for(int i = 0; i < size; ++i)
   {
      std::cin >> *(arrP + i);
      if(max1 < *(arrP + i))
      {  
         max2 = max1;
	 max1 = *(arrP + i);
      }
      else if(max2 < *(arrP + i))
      {
         max2 = *(arrP + i);
      }
   }

   std::cout << "Max2: " << max2 << std::endl;


}