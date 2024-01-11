#include <iostream>
#include <limits>
#include <fstream>
#include "matrix.hpp"

namespace LabP4
{
  void InputMatrixAsArray(std::ifstream & inputStream, int * matrix, size_t rows, size_t columns)
  {
    size_t matrixSize = rows * columns;

    for (size_t i = 0; i < matrixSize; i++)
    {
      inputStream >> matrix[i];
      if (!inputStream)
      {
        throw std::invalid_argument("Could not input matrix.\n");
      }
    }
  }

  int MaxSumParallelToSDG(int * matrix, size_t rows, size_t columns)
  {
    int maxSum = std::numeric_limits<int>::min();
    for (int i = 0; i < columns; i++)
    {
      int sum = 0;
      for (int row = 0, column = i; row < rows && column < columns; row++, column++)
      {
	if (row != column)
	{
	  sum += matrix[row * columns + column];
	}
      }
      maxSum = std::max(maxSum, sum);
    }
    for (int i = 1; i < rows; i++)
    {
      int sum = 0;
      for (int row = i, column = 0; row < rows && column < columns; row++, column++)
      {
	if (row != column)
	{
          sum += matrix[row * columns + column];
	}
      }
      maxSum = std::max(maxSum, sum);
    }
    return maxSum;    
  }
}
