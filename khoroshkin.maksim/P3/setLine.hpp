#ifndef SETLINE_HPP
#define SETLINE_HPP
#include <iostream>
#include <cstddef>

namespace khoroshkin
{
  char * inputLine(std::istream & input, size_t & userStringLength, size_t userAddSize);
}

#endif
