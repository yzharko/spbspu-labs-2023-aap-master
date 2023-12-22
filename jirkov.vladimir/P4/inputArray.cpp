#include "inputArray.hpp"
#include <fstream>

int jirkov::inputArray(std::istream &input, int *matrix, int rows, int cols)
{
  int count = 0;
  for (int i = 0; i < rows * cols; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return count;
    }
    count += 1;
  }
  return count;
}

void jirkov::printArray(std::ostream &output, int const *matrix, int rows, int cols)
{
  output << rows << " " << cols << " ";
  for (int i = 0; i < rows * cols; ++i)
  {
    output << matrix[i] << " ";
  }
}
