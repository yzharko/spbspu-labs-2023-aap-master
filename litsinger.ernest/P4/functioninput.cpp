#include "functioninput.hpp"

namespace litsinger
{
  size_t inputArray(std::ifstream & input, int * matrix, size_t sizeMatrix)
  {
    size_t count = 0;
    for (size_t i = 0; i < sizeMatrix; ++i)
    {
      input >> matrix[i];
      if (!input)
      {
        throw std::logic_error("Error\n");
      }
      count++;
    }
    return count;
  }
}
