#include <iostream>

double foo(double far)
{
    return (far - 32) * 5/9;
}

int main()
{
    double far = 0;
    std::cout << "Enter farenheit: ";
    std::cin >> far;

    std::cout << foo(far) << std::endl;
    return 0;
}
