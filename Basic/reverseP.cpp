
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

   for (int i = 0; i < size/2; ++i)
   {
      int temp = *(ptr + i);
      *(ptr + i) = *(ptr + size - 1 - i);
      *(ptr + size - 1 - i) = temp;
   }
   
   for(int i = 0; i < size; ++i)
   {
      std::cout << *(ptr + i) << " ";
   }
   std::cout << std::endl;
}
