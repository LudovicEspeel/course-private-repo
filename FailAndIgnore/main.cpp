#include <iostream>
#include <limits>

using namespace std;

int main() {

  int number = 0;
  do {
    cout << "Please enter a number between 1 and 10: ";
    cin >> number;
    if(cin.fail()) //or: if(!(cin >> number))
    {
        cin.clear(); // clear error flag
        //cin.ignore(1000, '\n'); // ignore the invalid input until newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input until newline

        cout << "Invalid input" << endl;
        number = 0;
    }

  } while (number < 1 || number > 10);

  return 0;
}
