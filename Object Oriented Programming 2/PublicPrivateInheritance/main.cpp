#include "BaseClass.h"
#include "DerivedClass.h"
#include "DerivedClass2.h"

int main(int argc, char const *argv[])
{
    BaseClass base;
    DerivedClass derived;
    DerivedClass2 derived2;

    base.Method1();
    derived.Method1();
    derived2.Method1();



    return 0;
}

