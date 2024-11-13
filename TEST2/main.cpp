#include <iostream>

using namespace std;

int main(void) {
  // Allocate integer on the heap
  int *number = new int;
  
  // Assign value to number
  *number = 42;
  cout << "Number is now " << *number << endl;

  // Delete the memory
  delete number;

  return 0;
}
