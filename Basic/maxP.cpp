#include <iostream>
#include <limits.h>

int main()
{
   const int size = 7;
   int arr[size];
   int *ptr = arr;
   int max = INT_MIN;
   
   std::cout << "Enter array elements:(" << size << ")";
   for (int i = 0; i < size; ++i)
   {
      std::cin >> *(ptr + i);
   }

   for (int i = 0; i < size; ++i)
   {
      if(max < *(ptr + i))
      {
         max = *(ptr + i);
      }
   }

   std::cout << "Max: " << max << std::endl;
}