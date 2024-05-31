
#include <iostream>

inline int foo(int x) 
{
    return x*x;
}

int foo1(int y)
{
    return y*y;
}
int main()
{
    int x = 15;
    int y = 10;
    std::cout << foo(x++);
    std::cout << "\nX: " << x;

    std::cout << "\n" << foo1(y++);
    std::cout << "\nY: " << y;

}
