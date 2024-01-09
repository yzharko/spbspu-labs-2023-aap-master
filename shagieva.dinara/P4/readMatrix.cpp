#include "readMatrix.hpp"

int shagieva::readMatrix(std::ifstream & input, int * values, const int numberOfValues)
{
  for (int read = 0; read < numberOfValues; read++)
  {
    if (!(input >> values[read]))
    {
      return read;
    }
  }

  return numberOfValues;
}
