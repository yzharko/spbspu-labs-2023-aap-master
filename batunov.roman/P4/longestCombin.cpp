#include "longestCombin.hpp"

int batunov::longestCombin(int** matrix, int rows, int cols)
{
  int longestCombinRow = -1;
  int longestCombinLength = 0;
  for (int i = 0; i < rows; i++)
  {
    int currentCombinLength = 1;
    for (int j = 1; j < cols; j++)
    {
      if (matrix[i][j] == matrix[i][j - 1])
      {
        currentCombinLength++;
      }
      else
      {
        if (currentCombinLength > longestCombinLength)
        {
          longestCombinRow = i;
          longestCombinLength = currentCombinLength;
        }
        currentCombinLength = 1;
      }
    }
    if (currentCombinLength > longestCombinLength)
    {
      longestCombinRow = i;
      longestCombinLength = currentCombinLength;
    }
  }
  return longestCombinRow + 1;
}
