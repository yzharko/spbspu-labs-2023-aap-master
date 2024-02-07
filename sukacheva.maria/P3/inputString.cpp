#include "inputString.hpp"
#include <iostream>
#include <iomanip>

char * sukacheva::inputString(std::istream& in, size_t& read)
{
  size_t len = 10;
  char* input = new char[len] {};
  char c = 0;
  in >> std::noskipws;
  while (in.get(c))
  {
    if (read == len - 1)
    {
      len += 10;
      char* newInput = new char[len] {};
      std::copy(input, input + read, newInput);
      delete[] input;
      input = newInput;
    }
    if (c == '\n')
    {
      break;
    }
    input[read] = c;
    read++;
  }
  if (!input[0])
  {
    delete[] input;
    throw std::runtime_error("Run without input");
  }
  in >> std::skipws;
  return input;
}
