#include <iostream>
#include "integer.h"
#include "float.h"
#include "bool.h"
#include <vector>

int main()
{
    std::vector<Any*> ptr;
    ptr.push_back(new Integer(5));
    ptr.push_back(new Float(4.2));
    ptr.push_back(new Bool(0));

    for(auto elem : ptr)
    {   
        std::string str;
        std::cin >> str;
        elem->set_value(str);
    }

    for(auto elem : ptr)
    {
        std::cout << elem->get_value() << std::endl;
    }
}