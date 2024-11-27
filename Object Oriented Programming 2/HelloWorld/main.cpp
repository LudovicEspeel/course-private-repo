// This is hello world
// Compile with: g++ main.cpp -o hello.exe
// Execute with: ./hello

#include <iostream>
    // # = pre-processor directive
    // Runs before compiler
    // Includes the whole library file

using namespace std;
    // Open the standard namespace

int main() {
  cout << "Hello World" << endl;
    // cout = console out
    // endl = end line + flush

  int age = 30;
  cout << "My age is " << age << endl;
  cout << "Number of bytes for int: "
    << sizeof(age) << endl;

  long long int veryLongInt = 123;
  cout << "Sizeof long long int: "
    << sizeof(long long int) << endl;
 
  cout << "A very long number: " << 1'323'223 << endl;
  cout << "A special floating point: " << 34.234'323 << endl;
  cout << "Zero dot one: " << 0.1 << endl;

  char start = 56;
  cout << "Char start: " << start << endl;
  cout << "Char start: " << (int)start << endl;
      // Casting to int

  char stop = 0x58;   // Hexadecimal: prefix 0x
  cout << "Char stop: " << stop << endl;

  char bin = 0b1001'0101;     // Binary literal: prefix 0b
  char oct = 060;             // Octal: prefix 0
  char character = 'a';       // Character

  double floating = 3.1415;     // Double precision
  float smallerFloat = 3.14f;   // Single precision

  bool theTruth = false;
  bool test = 123;

  int sum;    // Not DONE ! Not Initialized
  cout << "Init: " << sum << endl;

  int total = 0;

  // Constant value
  const int NUMBER_OF_STUDENTS = 9;

  // Pre-processor define ~constante
  #define MAX_STUDENTS 24

  cout << NUMBER_OF_STUDENTS << endl;

  // Operators
  double value = 33 / 2;
  cout << "Value = " << value << endl;
  
  double floatingValue = 33.0 / 2;
         floatingValue = 33 / 2.0;
         floatingValue = ((double)33)/2;
  
  int x = 3;
  int y = 2;
  double xY = 1.0 * x / y;
  double yX = ((double)x)/y;

  int remainder = 33 % 2;
  cout << "Remainder: " << remainder << endl;

  // Increment / decrement
  int c = 0;
  c++;        // Achterliggend: c = c + 1

  cout << "C++: " << c << endl;

  int z = ++c;    // c = 1, c => 2
  cout << "C++: " << c << endl;
  cout << "z: " << z << endl;

  int w = c++;  // c = 2, c => 3
  cout << "C++: " << c << endl;
  cout << "w: " << w << endl;

  bool a = true;
  bool b = false;

  if (a && b) {   // a == true && b == true
    cout << "Both true" << endl;
  } else {
    cout << "Not both true" << endl;
  }

  int i = 0;
  if (a || (++i)) {   // Lazy Evaluation !
    cout << "Either is true" << endl;
    cout << "i = " << i << endl;
  }

  // Ternary operator
  cout << (i == 0 ? "Yoepiie" : "Ahh") << endl;

  char A = 0b0000'0101;   // 5
  char B = 0b1111'0000;   // 240
  char C = 0b0000'0001;   // 1

  // Binary operations
  unsigned char D = A & B;         // 0
  unsigned char E = A | B;         // 245
  unsigned char F = C << 2;        // 4
  unsigned char G = A ^ B;         // xor, 245
  
  cout << "D: " << (int)D << endl;
  cout << "E: " << (int)E << endl;
  cout << "F: " << (int)F << endl;
  cout << "G: " << (int)G << endl;

  i = i + 5;
  i += 5;

  // Unary operators
  int one = -1;
  unsigned char H = ~A;   // Invert bits
  bool two = !false;

  if (one < 0) {
    cout << "One is negative" << endl;
  } else if (one > 0) {
    cout << "One is positive" << endl;
  } else {
    cout << "One is zero" << endl;
  }

  // Looping
  for (int i = 0; i < 10; i+=2) {
    cout << i << " ";
  }
  cout << endl;

  // Endless Loop
  // for (;;) {
  //   cout << "What ?" << endl;
  // }

  // Using i from larger scope
  for (; i < 100; i+=10) {
  }
  
  // Codeblock
  {
    int x = 3;
    cout << "x: " << x << endl;
  } // end of scope: x

  // While loop
  int k = 0;
  while (k < 10) {
    cout << k << " ";
    k++;
  }
  cout << endl;

  i = 0;
  do {
    cout << "Doing stuff" << endl;
    i++;
  } while (i < 5);

  enum Color { RED = 0, GREEN = 1, BLUE = 2 };

  Color color = RED;
  cout << "Color: " << color << endl;

  enum ConfigRegister {
    DATE = 0x3E,
    CONFIG = 0x5F,
    ENDIANESS = 0xEE,
    _RED = 0xFF         // Cannot use RED again !
  };

  // ConfigRegister config = RED;
  
  enum class MainRegister {
    HELLO = 1,
    RED = 2,
    OLA = 3
  };

  MainRegister mainReg = MainRegister::RED;

  if (mainReg == MainRegister::RED) {
    cout << "Main Register is RED" << endl;
  }

  mainReg = MainRegister::OLA;
  switch (mainReg) {
    case MainRegister::RED: {
      cout << "Main is RED" << endl;
      break;
    }

    case MainRegister::HELLO:
      cout << "Main is HELLO" << endl;
      break;
    
    default:
      cout << "Main is OLA?" << endl;
      break;
  }

  return 0;    // status code end of program
               // different from 0 = FAIL
}