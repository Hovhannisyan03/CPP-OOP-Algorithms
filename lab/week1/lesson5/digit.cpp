#include <iostream>

void foo(int num)
{   
    int tmp = num;
    int count = 0;
    while(tmp != 0)
    {
    	tmp /= 10;
	++count;
    }

    int div = 1;
    int count2 = count;
    while(count != 0)
    {
        div *= 10;
	--count;
    }

    while(count2 != 0)
    {   
	int tmp1 = num % div;
	int digit = 0;
	while(tmp1 != 0)
	{
	    digit = tmp1 % 10;
	    tmp1 /= 10;
	}
        std::cout << digit << " ";
	div /= 10;
	--count2;
    }
    std::cout << std::endl;
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;

    foo(num);

    return 0;
}
