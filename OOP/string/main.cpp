#include <iostream>
#include "string.h"

// class A
// {
//     public:
//     A(int x) : x{x}{}
//     int operator++(int i)
//     {   
//         return x++;
//     }
//     int operator++()
//     {
//         std::cout << "1";
//         x += 1;
//         return x;
//     }
//     private:
//         int x;
// };
int main()
{  String obj("hello");
String obj2("World");
String obj3 = obj + obj2;
String obj4 = obj + obj2 + obj3;
std::cout << obj4.c_str();
    // String obj1(obj);
    // obj += "world";
    // std::cout << "Result: ";
    // obj.display();
    // obj1.display();
    // String obj2;
    // obj2 = obj1;
    // obj2.display();
    // obj2 = std::move(obj);
    // obj2.display();
    // std::cout << obj2.size();
    // std::cout << obj.size();
    // char* arr = obj2.c_str();
    // std::cout << arr;
    // std::cout << obj2.at(2);
    // std::cout << obj2.front();
    // std::cout << obj2.back();
    // std::cout << "Before: ";
    // obj2.display();
    // obj2.clear();
    // std::cout << "After: ";
    // obj2.display();
    // String obj1("Hello");
    // String obj2("world");
    // String obj3;
    // obj3 = obj1 + obj2;
    // obj1.append(obj1);
    // obj1.append("Hello");
    // obj1.display();
    // std::cout << obj1.size();
    // String obj = "hello";
    // String obj1;
    // String obj1 = "World";
    // String obj2("Hello");
    // obj += obj2;
    // obj == obj2;
    // std::cout << obj.size();
    // std::cout << obj.c_str();
    // std::cout << obj;
    // std::cin >> obj >> obj1;
    // if(obj.c_str() == obj.c_str())
    // std::cout << "1";
    // obj += obj1;
    // std::cout << obj << "\n" << obj1;
    // const char *arr = (const char*)obj;
    // std::cout << arr;
    // int x = (int)obj;
    // std::cout << x;
    // std::cout << sizeof(String) << std::endl;
    // String str(str);
    // std::cout << str.c_str() << str.size();

}