#include <iostream>  

int main()
{
   const int size = 7;
   int arr[size];
   int *ptr = arr;
   int sum = 0;
   int count = 0;
  
   std::cout << "Enter array elements:(" << size << ")";
   for (int i = 0; i < size; ++i)
   {
      std::cin >> *(ptr + i);
   }

   for (int i = 0; i < size; ++i)
   {
      sum += *(ptr + i);
   }
   
   float average = (float)sum/count;

   std::cout << "Average: " << average << std::endl;
}