#include <iostream>
#include <map>

int fibonacci(int n, std::map<int,int> map = {})
{
    if(n <= 2)
    {
        return 1;
    }
    if(map.count(n) == 0)
    {
        map.insert({n,fibonacci(n - 1, map) + fibonacci(n - 2, map)});
    }
    return map[n];
}

int main()
{
    std::cout << fibonacci(1) << std::endl;
    std::cout << fibonacci(2) << std::endl;
    std::cout << fibonacci(3) << std::endl;
    std::cout << fibonacci(4) << std::endl;
    std::cout << fibonacci(5) << std::endl;
    std::cout << fibonacci(6) << std::endl;
    std::cout << fibonacci(7) << std::endl;
    std::cout << fibonacci(8) << std::endl;
    std::cout << fibonacci(9) << std::endl;
    std::cout << fibonacci(10) << std::endl;
    std::cout << fibonacci(11) << std::endl;
}