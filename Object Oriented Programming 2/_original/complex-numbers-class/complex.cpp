#include "complex.h"

namespace VIVES {

  Complex::Complex(void)
  : Complex(0, 0) { }

  Complex::Complex(double real, double imaginary) {
    this->real(real);
    this->imaginary(imaginary);
  }

  void Complex::real(double real) {
    _real = real;
  }

  void Complex::imaginary(double imaginary) {
    _imaginary = imaginary;
  }

  Complex Complex::add(Complex second) {
    // Complex result;
    // result.real(this->_real + second._real);
    // result.imaginary(this->_imaginary + second._imaginary);
    // return result;

    // Option 2:
    return Complex(
      this->_real + second._real,
      this->_imaginary + second._imaginary
    );
  }

  std::string Complex::to_string(void) {
    // Option 1 = less efficient but ok for small strings
    // return "{ real: " + std::to_string(real)
    //      + ", imag: " + std::to_string(imaginary) + " }";

    std::stringstream ss;
    ss << "{ real: " << _real
        << ", imag: " << _imaginary << "}";

    return ss.str();
  }

};
