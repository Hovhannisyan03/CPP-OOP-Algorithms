#include <iostream>

std::string to_hex(size_t um)

    std::string res = 0;
    do
    {
        int digit = num % 16;
	res = (digit < 10) ? (char)(digit + '0') + res : (char)(digit - 10 + 'A') + res;
	num /= 16;
    }while(num > 0);

    return res;
}

int main()
{
    int num = 0;
    std::cout << "Enter num: ";
    std::cin >> num;
    std::cout << "Result: " << to_hex(num) << std::endl;
}
