#include <iostream>

int maxDivider(int num1, int num2)
{   
    if(num2 == 0)
    {
        return num1;
    }
    return maxDivider(num2, num1 % num2);
}

int main()
{
    int num1 = 0;
    int num2 = 0;

    std::cout << "Num1: ";
    std::cin >> num1;

    std::cout << "Enter num2: ";
    std::cin >> num2;
    std::cout << maxDivider(num1, num2) << std::endl;

    return 0;
}
