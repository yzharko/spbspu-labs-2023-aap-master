#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "readString.hpp"
#include "uppLow.hpp"

int main()
{
  char * inputStr = nullptr;
  size_t read = 0;

  try
  {
    inputStr = shagieva::readString(std::cin, read);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  char * changedStr = new char[read]{};
  shagieva::uppLow(inputStr, changedStr, read);

  delete[] inputStr;

  for (size_t i = 0; i < read; i++)
  {
    std::cout << changedStr[i];
  }
  std::cout << "\n";

  delete[] changedStr;

  return 0;
}
