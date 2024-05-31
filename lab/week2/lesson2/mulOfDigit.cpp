#include <iostream>

int mul(int num)
{   
    if(num < 10)
    {
        return num;
    }
    return (num % 10) * mul(num / 10);    
}

int main()
{
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    
    num = num > 0 ? num : -1 * num;
    std::cout << "Mul of number is: " << mul(num) << std::endl;

    return 0;
}
