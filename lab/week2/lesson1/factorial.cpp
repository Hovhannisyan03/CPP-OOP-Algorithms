#include <iostream>

int factorial(int num)
{   
    if(num < 0)
    {
        return -1;
    }
    else if(num == 0 || num == 0)
    {
        return 1;
    }
   
     return num * factorial(num - 1);
    
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << num << " != " << factorial(num) << std::endl;
}
