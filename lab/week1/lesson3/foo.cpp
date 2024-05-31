#include <iostream>

class Foo 
{
    public:
       Foo(){}
       Foo& operator()()
       {
           ++count;
	   return *this;
       }
       int count;

};

int main()
{
    Foo foo;
    foo()()();
    std::cout << foo.count << std::endl;
}
