#include "stringwork.hpp"
#include <iostream>
#include <cstddef>
#include <cstring>

char * resizeString(const char * str)
{
  const size_t curr_size = strlen(str);
  const size_t add_size = 10000;
  char * new_str = nullptr;
  try {
    new_str = new char [curr_size + add_size]{};
  } catch (const std::bad_alloc & e) {
    throw;
  }
  for (size_t i = 0; i < curr_size; i++) {
    new_str[i] = str[i];
  }
  return new_str;
}

void yartsev::readString(char * str)
{
  size_t read = 0;
  size_t size = 10000;
  char symbol = 0;
  std::cin >> std::noskipws;
  std::cin >> symbol;
  if ((!std::cin) || symbol == '\n') {
    throw std::logic_error("Wrong input: empty string");
  }
  do {
    if (read == size - 1) {
      str[read] = '\0';
      try {
        char * new_str = resizeString(str);
        delete [] str;
        str = new_str;
      } catch (const std::bad_alloc & e) {
        throw;
      }
    }
    str[read++] = symbol;
  } while ((std::cin >> symbol) && (symbol != '\n'));
  str[read] = '\0';
  std::cin >> std::skipws;
}
