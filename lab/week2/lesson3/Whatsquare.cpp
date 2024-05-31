#include <iostream>

int square(int num1, int num2)
{ 
   if(num2 >= 300 || num2 < 0)
   {
       return -1;
   }
   return ((num1 / 30) * 3) + ((num2 / 100) + 1;
}

int main()
{
    int num1 = 0;
    int num2 = 0;

    std::cin >> num1;
    std::cin >> num2;

    std::cout << square(num1,num2) << std::endl;

    return 0;
}
