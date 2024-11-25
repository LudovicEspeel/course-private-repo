#include "Date.h"
#include <iostream>
#include <string>

using namespace std;
using namespace DateLib;

int main()
{
    try
    {
        Date date1;
        cout << date1.getString() << endl;

        Date date2(16, 10, 2024);
        date2.setDay(0);
        cout << date2.getString() << endl;
    }
    catch (const invalid_argument e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}