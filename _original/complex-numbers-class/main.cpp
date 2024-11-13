// Compile with: g++ main.cpp complex.cpp -o complex
// Run with: ./complex
#include <iostream>
#include "complex.h"

using namespace std;
// using namespace VIVES;

int main() {
  cout << "Complex numbers are fun" << endl;

  VIVES::Complex first;            // No () for default constructor !
  VIVES::Complex second(3, 5);
  
  first.real(123);
  first.imaginary(-5);

  cout << "First: " << first.to_string() << endl;
  cout << "Second: " << second.to_string() << endl;

  VIVES::Complex sum = first.add(second);
  cout << "Sum = " << sum.to_string() << endl;

  VIVES::Complex result = sum.add(first).add(sum).add(second);

  return 0;
}