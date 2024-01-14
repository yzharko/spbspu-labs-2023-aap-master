#include "fillMatrix.hpp"

namespace sobolevsky
{
  size_t fillMatrix(std::istream & in, int * matrix, size_t s, size_t counter)
  {
    for (size_t i = 0; i < s; ++i)
    {
      if (in >> matrix[i])
      {
        counter++;
      }
    }
    return counter;
  }
}
