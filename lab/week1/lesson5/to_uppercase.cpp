#include <iostream>


std::string to_upper(std::string str)
{   
    size_t size = 0;
    while(str[size] != '\0')
    {
        if(str[size] >= 'a' && str[size] <= 'z')
	{
	    str[size] -= 32;
	}
	++size;
    }
    return str;
}

int main()
{
    std::string str = "";
    std::cout << "Enter num: ";
    std::cin >> str;

    str = to_upper(str);
    std::cout << "Result: " << str << std::endl;

    return 0;
}
