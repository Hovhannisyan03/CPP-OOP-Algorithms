#include <iostream>

void print(int n)
{
    if(n == -1)
    {
        return;
    }
    std::cout << n << std::endl;
    print(--n);
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;
    print(num);
}
