#include <algorithm>
#include "algorithm.hpp"

long long khoroshkin::minSumOfParallelArray(int * matrix, int Rows, int Cols)
{
  int minSum = std::numeric_limits< int >::max();
  for (int i = 1 - Rows; i < Rows; i++)
  {
    int currentSum = 0;
    for (int j = 0; j < Cols; j++)
    {
      if  ((i + j) >= 0 && (i + j) < Rows)
      {
        currentSum += matrix[(i + j) * Rows + j];
      }
    }
    minSum = std::min(currentSum, minSum);
  }
  if (Rows * Cols == 0)
  {
    return 0;
  }
  else
  {
    return minSum;
  }
}
