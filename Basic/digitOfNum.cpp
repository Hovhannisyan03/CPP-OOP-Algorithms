#include <iostream>

void dig(int);

int main()
{
    int number = 0;
    std::cout << "Enter number: ";
    std::cin >> number;

    dig(number);
    return 0;
}

void dig(int num)
{
    if(num == 0)
    {  
        return;
    }  
    int digit = num % 10;
    num /= 10;
    dig(num);
    std::cout << digit;  
}