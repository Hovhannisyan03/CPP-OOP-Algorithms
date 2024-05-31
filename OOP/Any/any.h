#include <string>
#ifndef ANY_H
#define ANY_H
class Any
{
    public:
        virtual std::string get_value() = 0;
        virtual void set_value(std::string& info) = 0;
};
#endif