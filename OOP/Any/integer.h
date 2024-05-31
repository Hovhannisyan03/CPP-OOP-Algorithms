#include <string>
#include "any.h"

#ifndef INTERGER_H
#define INTERGER_H
class Integer : public Any
{
    public:
        Integer(int x) : num{x}{}
        std::string get_value() override;
        void set_value(std::string& info) override;
    private:
        int num;
};
#endif