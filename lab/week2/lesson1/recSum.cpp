#include <iostream>

int Sum(int num)
{   
    if(num <= 1)
    {
        return num;
    }
    return num + Sum(num - 1);
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << Sum(num) << std::endl;
}
