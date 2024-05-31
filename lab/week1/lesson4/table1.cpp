#include <iostream>

void table(int num)
{
    for(size_t i = 1; i <= 10; ++i)
    {  
         std::cout << num << " * " << i << " = " << num * i << std::endl;
    }
}

int main()
{   
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    if(num <= 0)
    {   
	std::cout << "Invalid number" << std::endl;
        return 0;
    }
    table(num);
}
