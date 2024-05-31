#include <iostream>
#include "float.h"
#include <sstream>

std::string Float::get_value()
{
    return std::to_string(num);
}

void Float::set_value(std::string& str)
{
    std::stringstream info;
    info << str;
    info >> num;
    std::cout << num;
}