#include <iostream>

int foo(int n)
{   
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }

    int fib = 0;
    int a = 0; 
    int b = 1;
    int i = 2;
    while(i != n)
    {
	fib = a + b;
	a = b;
	b = fib;
        ++i;	
    }   
    return fib; 
}

int main()
{
    int n = 0;
    std::cout << "Enter number: ";
    std::cin >> n;
    std::cout << foo(n) << std::endl;

}
