#include <iostream>
#include <cstddef>
#include "uppLow.hpp"

int main()
{
  char * inputStr = new char[10]{};
  size_t add = 30;
  char cur = 0;
  size_t read = 0;

  std::cin >> std::noskipws;
  do
  {
    std::cin >> cur;
    if (read == 0 && cur == '\n')
    {
      std::cerr << "Empty line entered.\n";
      return 1;
    }
    inputStr[read++] = cur;
    if (read % add == 0)
    {
      char * newInputStr = new char[read + add];
      for (size_t i = 0; i < read; i++)
      {
        newInputStr[i] = inputStr[i];
      }
      delete [] inputStr;
      inputStr = newInputStr;
    }
  }
  while (cur != '\n');
  std::cin >> std::skipws;

  char * changedStr = new char[read]{};
  shagieva::uppLow(inputStr, changedStr, read);

  for (size_t i = 0; i < read; i++)
  {
    std::cout << changedStr[i];
  }
  std::cout << "\n";

  delete[] inputStr;
  delete[] changedStr;
  return 0;
}
