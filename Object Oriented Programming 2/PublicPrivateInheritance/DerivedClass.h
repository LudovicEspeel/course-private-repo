#pragma once

#include "BaseClass.h"

class DerivedClass : private BaseClass
{
public:
    DerivedClass();
    //virtual void Method1() override;

private:
    int d = 0;
    int e = 0;
};
