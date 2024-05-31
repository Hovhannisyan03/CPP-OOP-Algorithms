#include <string>
#include "any.h"

#ifndef BOOL_H
#define BOOL_H
class Bool : public Any
{
    public:
        Bool(bool x) : num{x}{}
        std::string get_value() override;
        void set_value(std::string& info) override;
    private:
        bool num;
};
#endif