#include "minS.hpp"
#include <algorithm>
#include <cmath>

int lisitsyna::minS(int rows, int cols, int* values)
{
  int minS = std::numeric_limits< int >::max();
  for (int i = 1 - rows; i < rows; i++)
  {
    int curSum = 0;
    for (int j = 0; j < cols; j++)
    {
      if ((i + j) >= 0 && (i + j) < rows)
      {
        curSum += values[(i + j) * rows + j];
      }
    }
    minS = std::min(curSum, minS);
  }
  if (rows * cols == 0)
  {
    return 0;
  }
  else
  {
    return minS;
  }
}
