#include <iostream>

int power(int num, int exp)
{   
    if(exp == 0)
    {
        return 1;
    }
    --exp;
    int res = num;
    while(exp != 0)
    {
        res *= num;
	--exp;
    }

    return res;
}

int main()
{
    int num = 0;
    int exp = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    
    std::cout << "Enter exp: ";
    std::cin >> exp;

    std::cout << "Result: " << power(num,exp) << std::endl;
    return 0;
}
