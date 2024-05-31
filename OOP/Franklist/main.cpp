#include "franklist.h"

class A
{
    private:
        int x;
    public: 
        A(int x)
        {
            std::cout << "A";
        }
};

int main()
{
   A obj = A(4);
}