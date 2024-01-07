#include <iostream>
#include <iomanip>
#include <iosfwd>
#include "functions.hpp"
int main()
{
  char* input = nullptr;
  size_t readEl = 0;
  try
  {
    std::cin >> std::noskipws;
    input = doroshenko::readInput(input, std::cin, readEl);
    if (readEl == 0)
    {
      std::cerr << "There is no elements in the string\n";
      delete[] input;
      return 1;
    }
    else
    {
      doroshenko::removeDup(input, readEl);
    }
    std::cin >> std::skipws;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation error\n";
    delete[] input;
    return 1;
  }
  delete[] input;
  return 0;
}
