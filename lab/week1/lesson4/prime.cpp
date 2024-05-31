#include <iostream>

bool prime(int num)
{   
    if (num <= 1)
    {
        return false;
    }
    for(int i = 2; i <= num/2; ++i)
    {
        if(num % i == 0)
	{
	    return false;
	}
    }
    return true;
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << prime(num) << std::endl;

    return 0;
}
