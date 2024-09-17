#include <iostream>
#include "user.h"

using namespace std;
using namespace Vives;

// This will not work
// PASS-BY-VALUE !
void swap_numbers(int left, int right) {
  int temp = left;
  left = right;
  right = temp;
}

// Swap using pointers
// STILL PASS-BY-VALUE but we use pointers
void swap_numbers(int * left, int * right) {
  int temp = *left;
  *left = *right;
  *right = temp;
}

// PASS-BY-VALUE !!!
// In other words, object is copy of original
void reset_study_percentage(User user) {
  user.study_percentage(0);
}

// PASS-BY-VALUE !!!
// But this time we pass pointer to user
void reset_study_percentage(User * user) {
  // (*user).study_percentage(0);
  user->study_percentage(0);
}

int main() {
  cout << "Welcome to DYN Memory" << endl;

  int normalValue = 123;

  // Pointer to normalValue
  int * pNormalValue = &normalValue;
    // & = address of operator

  // Access value pointer is pointing to
  cout << "Normal value " << (*pNormalValue) << endl;
    // * = dereferencing operator

  // Assignment of value pointed to
  *pNormalValue = 15;
  cout << "Normal value: " << normalValue << endl;

  // Let's try to swap some numbers
  int x = 10;
  int y = 20;

  swap_numbers(x, y);
  cout << "x = " << x << " y = " << y << endl;

  // Calling swap with pointers
  swap_numbers(&x, &y);
  cout << "x = " << x << " y = " << y << endl;

  // Demo User
  User sille("Sille", "Vanlandschoot");
  
  cout << sille.to_string() << endl;
  sille.study_percentage(203);
  cout << sille.to_string() << endl;

  // Pass object
  reset_study_percentage(sille);
  cout << sille.to_string() << endl;

  // Pass address of object
  reset_study_percentage(&sille);
  cout << sille.to_string() << endl;

  // Arrays and pointers
  int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // Pointer to array
  int * pNumbers = numbers;   // Decaying
  cout << pNumbers[0] << endl;

  int * pNumbersHalf = &numbers[5];
  cout << pNumbersHalf[0] << endl;
  cout << *pNumbersHalf << endl;
  cout << *(pNumbersHalf+1) << endl;
  cout << pNumbersHalf[1] << endl;
  cout << pNumbersHalf[220] << endl;    // We can access memory outside of array

  pNumbersHalf++;
  cout << *pNumbersHalf << endl;
  
  pNumbers--;
  cout << *pNumbers << endl;

  // Dynamic Memory Allocation
  cout << "How many ints do you need? ";
  int size = 0;
  cin >> size;

  int * vector = new int[size];           // Allocation !
  for (int i = 0; i < size; i++) {
    vector[i] = i;
  }

  cout << vector[size-1] << endl;

  delete[] vector;          // De-allocate memory (cleanup)

  // Allocation of objects
  User * jasper = new User("Jasper", "Lievens");

  cout << jasper->to_string() << endl;

  // De-allocate object jasper
  delete jasper;

  return 0;
}