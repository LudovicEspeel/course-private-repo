#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {

  cout << "Demo std::array" << endl;

  std::array<std::array<std::string, 10>, 20> buffer;

  buffer[0][0] = "hello";
  buffer[0][2] = "world";

  buffer[2][3] = "dude";

  for (auto & line : buffer) {
    for (auto & element : line) {
      cout << element << " | ";
    }
    cout << endl;
  }

  return 0;

}