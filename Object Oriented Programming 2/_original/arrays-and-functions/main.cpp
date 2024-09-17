// Compile with: g++ main.cpp -o hello
// Run with: ./hello
#include <iostream>

using namespace std;

// Function
// C++: pass-by-value
int sum(int left, int right) {
  return left + right;
}

// Default values
int sum(int first, int second, int third, int fourth = 0) {
  return first + second + third + fourth;
}

int sum(int values[], size_t length) {
  // cout << "Sizeof values: " << sizeof(values)/sizeof(int) << endl;
      // output = 2
      // because pointer = 8 bytes / 4 bytes (int)
      // array degrades (resolves) to pointer when passing to function/method

  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += values[i];
  }

  // Cannot use foreach here because values = pointer

  return sum;
}

int main() {

  // Creating arrays
  const int MAX_NUMBERS = 10;
  int numbers[MAX_NUMBERS] = { 1, -4, 23 };

  // arrays have no ".Length" in c++
  for (int i = 0; i < MAX_NUMBERS; i++) {
    cout << numbers[i] << endl;
  }

  cout << "Sizeof numbers: " << sizeof(numbers) << endl;
  cout << "Length numbers: " << sizeof(numbers)/sizeof(int) << endl;

  char hello[] = "Hello";   // "Hello" = c-string
  char world[] = { 'w', 'o', 'r', 'l', 'd', '\0' };

  cout << "Sizeof hello: " << sizeof(hello) << endl;

  // 2D-array
  int matrix[2][3] = {
    { 1, 2, 3 },
    { 5, 6, 7 }
  };

  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 3; col++) {
      cout << matrix[row][col] << " ";
    }
    cout << endl;
  }

  cout << "Sum of 3 and 5 = " << sum(3, 5) << endl;
  cout << "Sum of 3, 5 and 8 = " << sum(3, 5, 8) << endl;
  cout << "Sum of 3, 5, 8, 2 = " << sum(3, 5, 8, 2) << endl;

  cout << "Sum of numbers: " << sum(numbers, MAX_NUMBERS) << endl;

  // Here we can use sizeof(numbers)
  // Same scope as numbers array
  cout << "Sum of numbers: "
      << sum(numbers, sizeof(numbers)/sizeof(int)) << endl;

  // Sizeof a pointer = memory address variable
  cout << "Sizeof pointer " << sizeof(int*) << endl;

  // Here we can use foreach but not inside sum
  for (int val : numbers) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}