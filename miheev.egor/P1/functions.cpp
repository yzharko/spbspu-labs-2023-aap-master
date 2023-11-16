#include "functions.hpp"
#include <iostream>

namespace miheev
{
  int getNumberFromCin()
  {
    int variable = 0;
    std::cin >> variable;
    if (!std::cin)
    {
      throw std::invalid_argument("Your input can't be interpret as a sequence of numbers");
    }
    return variable;
  }
}

