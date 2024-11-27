#include <iostream>

using namespace std;

int main()
{
    string days[]{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    unsigned int dayOfTheWeek = 0;
    do
    {
        cout << "Please enter the day of the week (1 - 7): ";
        cin >> dayOfTheWeek;
    } while (dayOfTheWeek < 1 || dayOfTheWeek > 7);

    cout << "Then it's " << days[dayOfTheWeek-1] << " today" << std::endl;

    return 0;
}
