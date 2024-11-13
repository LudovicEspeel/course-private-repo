// #######################
// # DynamicArray
// #######################
// # - values[]: double
// # - size: size_t       => actual size of array
// # - _count: size_t     => number of used elements
// #######################
// # + DynamicArray()
// # + ~DynamicArray()
// # + add(value: double)   => achteraan toevoegen
// # + count(): size_t      => het aantal gebruikte cellen
// # + clear()              => alles op 0
// # + trim_to_size()       => geen lege elementen
// # + get(index: uint): double         => boundary check: return 0
// # + set(index: uint, value: double)  => boundary check: no change
// # - grow(to_size: size_t)      => grow the internal array

#pragma once

#include <cstddef>

namespace Vives {

  class DynamicArray {

    private:
      std::size_t _size = 0;
      std::size_t _count = 0;

  };

};