#include <string>
using namespace std;

namespace DateLib
{
    class Date
    {
    public:
        Date();
        Date(int day);
        Date(int day, int month);
        Date(int day, int month, int year);
        // Date(int day=1, int month=1, int year=2024); // constructor with default parameters
        ~Date();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        string getString() const;

    private:
        int day;
        int month;
        int year;
    };
}