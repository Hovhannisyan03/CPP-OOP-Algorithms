#include <iostream>


int sumOfDigit(int num)
{   
    if(num == 0)
    {
        return 0;
    }

    return num % 10 + sumOfDigit(num/10);
}
int main()
{
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    std::cout << "Sum: " << sumOfDigit(num) << std::endl;

    return 0;
}
