#include "input_ar.hpp"
#include <istream>
#include <fstream>

size_t lisitsyna::input_ar(std::ifstream& in, int* values, size_t sizeMatrix)
{
  for (size_t i = 0; i < sizeMatrix; i++)
  {
    in >> values[i];
    if (!in)
    {
      return i;
    }
  }
  return sizeMatrix;
}
