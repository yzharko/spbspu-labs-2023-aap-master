#include <iostream>
#include "stringwork.hpp"

void yartsev::readstring(char * str)
{
  char c = 0;
  size_t read = 0;
  size_t size = 10000;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (read < size)) {
    if (c == '\n') {
        break;
    }
    str[read++] = c;
  }
  std::cin >> std::skipws;
}