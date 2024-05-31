#include <iostream>

void binary(int num)
{   
    if(num == 0)
    {
        return;
    }
 
    binary(num / 2);
    std::cout << num % 2;
} 

int main()
{
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;

    binary(num);

    return 0;
}
