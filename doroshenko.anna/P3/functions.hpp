#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cstddef>
#include <iostream>

namespace doroshenko
{
  char* resizeArray(char* input, size_t size, size_t newSize);
  char* readInput(char* input, std::istream& in, size_t& readEl);
  void removeDup(char* input, size_t readEl);
}

#endif
