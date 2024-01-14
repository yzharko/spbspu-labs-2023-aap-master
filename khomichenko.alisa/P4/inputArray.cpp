#include "inputArray.hpp"
#include <iostream>

int khomichenko::inputArray(std::istream & in, int * matrix, size_t number)
{
  for (size_t i = 0; i < number; ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return number;
}
