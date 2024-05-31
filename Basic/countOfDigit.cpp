#include <iostream>

int count(int,int);

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    do
    {
        std::cin >> num;
    }while(num <= 0);

    std::cout << count(num,0);
}

int count (int num, int k)
{
    if(num == 0)
    {
        return k;
    }
    num /= 10;
    return count(num,++k);
}