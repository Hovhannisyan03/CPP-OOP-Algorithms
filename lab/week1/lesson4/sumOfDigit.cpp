#include <iostream>

int SumofDigit(int num)
{
    int sum = 0;
    while(num != 0)
    {
        sum += num % 10;
	num /= 10;
    }

    return sum;
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << SumofDigit(num) << std::endl;

    return 0;
}
