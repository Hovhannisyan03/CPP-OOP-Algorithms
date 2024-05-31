#include <iostream>
#include "integer.h"
#include <sstream>

std::string Integer::get_value()
{
    return std::to_string(num);
}

void Integer::set_value(std::string& str)
{
    std::stringstream info;
    info << str;
    info >> num;
    std::cout << num;
}
