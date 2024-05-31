#include <string>
#include "any.h"

#ifndef FLOAT_H
#define FLOAT_H
class Float : public Any
{
    public:
        Float(float x) : num{x}{}
        std::string get_value() override;
        void set_value(std::string& info) override;
    private:
        float num;
};
#endif