
#include <iostream>

void fib(int num, int first, int second);

int main()
{
   int num = 0;
   std::cout << "Enter number: ";
   std::cin >> num;
   int first = 0;
   int second = 1;
   fib(num, first, second);
}

void fib(int num,int first,int second)
{   
    if(num == 0)
    {
       return;
    }
    
    int number = first + second;
    first = second;
    second = number;
    std::cout << number << " ";
    fib(--num, first, second);
}
