#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP
#include <iosfwd>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace proselkov
{
  size_t inputArray(std::istream& in, int* matrix, size_t s, size_t toRead);
}
#endif
