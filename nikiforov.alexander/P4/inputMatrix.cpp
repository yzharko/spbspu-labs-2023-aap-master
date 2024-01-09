#include "inputMatrix.hpp"

size_t nikiforov::inputMatrix(std::ifstream& in, int* ArrMatrix, size_t lenth)
{
  size_t elemetscount = 0;
  for (size_t i = 0; i < lenth; i++)
  {
    if (!(in >> ArrMatrix[i]))
    {
      return elemetscount;
    }
    elemetscount++;
  }
  return elemetscount;
}
