#pragma once

#include "DerivedClass.h"

class DerivedClass2 : public DerivedClass
{
public:
    DerivedClass2();
    //virtual void Method1() override;

private:
    int d = 0;
    int e = 0;
};
