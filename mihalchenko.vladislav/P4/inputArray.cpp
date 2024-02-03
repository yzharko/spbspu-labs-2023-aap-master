#include "inputArray.hpp"
#include <iostream>

size_t mihalchenko::inputArray(std::istream& in, float* arrInput, size_t arrCols)
{
  for (size_t i = 0; i < arrCols; i++)
  {
    if (!(in >> arrInput[i]))
    {
      return i;
    }
  }
  return arrCols;
}
