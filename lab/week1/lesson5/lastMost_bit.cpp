#include <iostream>

bool is_equal(unsigned int num)
{
    int bit = sizeof(unsigned int) * 8;

    if((num >> (bit - 1)) == (num << (bit - 1)))
    {
        return true;
    }

    return false;
}

int main()
{
    unsigned int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;

    std::cout << is_equal(num) << std::endl;

    return 0;
}
