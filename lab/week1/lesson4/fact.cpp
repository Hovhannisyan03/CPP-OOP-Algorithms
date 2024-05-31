#include <iostream>

void factorial(int num)
{
    int fact = 1;
    while(num != 0)
    {
        fact *= num;
	--num;
    }
    std::cout << fact << std::endl;
    return;
}
int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    
    if(num < 0)
    {
        std::cout << "Invalid number" << std::endl;
	return 0;
    }
    factorial(num);
}
