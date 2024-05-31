#include <iostream>

int fib(int num)
{
    if(num == 0 || num == 1)
    {
        return num;
    }

    return fib(num - 1) + fib(num - 2);
}

int main()
{
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    std::cout << fib(num) << std::endl;

    return 0;
}
