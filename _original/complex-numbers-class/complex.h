#pragma once
// Include guard

// Old c-syntax
// #ifndef _HEADER_COMPLEX_
// #define _HEADER_COMPLEX_
// // class
// #endif

#include <string>
#include <sstream>

// No using namespace here !!!!
// Opens it up for every include

namespace VIVES {

  class Complex {
    public:
      Complex(void);
      Complex(double real, double imaginary);

    public:
      void real(double real);
      void imaginary(double imaginary);

    public:
      Complex add(Complex second);

    public:
      std::string to_string(void);

    private:
      double _real = 0;
      double _imaginary = 0;
  };

};

