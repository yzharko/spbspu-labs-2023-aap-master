#include "stringwork.hpp"
#include <iostream>

void yartsev::readstring(char * str)
{
  char c = 0;
  size_t read = 0;
  size_t size = 10000;
  str[0] = '\0';
  std::cin >> std::noskipws;
  do {
  } while ((std::cin >> str[read]) && (str[read++] != '\n'));
  str[--read] = '\0';
  std::cin >> std::skipws;
}