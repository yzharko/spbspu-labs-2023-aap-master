#include "stringwork.hpp"
#include <iostream>

void yartsev::readstring(char * str)
{
  size_t read = 0;
  size_t size = 10000;
  std::cin >> std::noskipws;
  std::cin >> str[0];
  read++;
  if (str[0] == '\n') {
    throw std::logic_error("Wrong input: empty string");
  }
  char symbol = 0;
  while ((std::cin >> symbol) && (symbol != '\n')) {
    str[read++] = symbol;
  }
  std::cin >> std::skipws;
}