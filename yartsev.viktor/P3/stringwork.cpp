#include "stringwork.hpp"
#include <iostream>
#include <cstddef>

void yartsev::readString(char * str)
{
  size_t read = 0;
  size_t size = 10000;
  char symbol = 0;
  std::cin >> std::noskipws;
  std::cin >> symbol;
  if (symbol == '\n') {
    throw std::logic_error("Wrong std::cin: empty string");
  }
  do {
    if (read == size - 1) {
      try {
        size = yartsev::resizeString(str, read);
      } catch (std::bad_alloc) {
        throw;
      }
    }
    str[read++] = symbol;
  } while ((std::cin >> symbol) && (symbol != '\n'));
  str[read] = '\0';
  std::cin >> std::skipws;
}

size_t yartsev::resizeString(char *& str, const size_t curr_size, const size_t add_size)
{
  char * new_str = nullptr;
  try {
    new_str = new char [curr_size + add_size]{};
  } catch (std::bad_alloc & e) {
    throw;
  }
  for (int i = 0; i < curr_size; i++) {
    new_str[i] = str[i];
  }
  delete [] str;
  str = new_str;
  return curr_size + add_size;
}
