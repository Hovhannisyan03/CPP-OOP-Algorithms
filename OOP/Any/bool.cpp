#include <iostream>
#include "bool.h"
#include <sstream>

std::string Bool::get_value()
{   
    return std::to_string(num);
}

void Bool::set_value(std::string& str)
{
    std::stringstream info;
    int tmp1 = 0;
    info << str;
    info >> tmp1;
    if(tmp1 != 0)
    {
        num = true;
        return;
    }
    else
    {
        num = false;
    }
}