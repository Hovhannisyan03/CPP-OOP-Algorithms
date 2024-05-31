#include <iostream>

void print(int num)
{
    if(num == 0)
    {
        return;
    }
    print(num - 1);
    std::cout << num << std::endl;
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    print(num);
}
