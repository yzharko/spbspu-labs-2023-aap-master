#include "countCols.hpp"

int redko::countCols(const int * matrix, int rows, int cols)
{
  int colsWithoutRep = 0;
  int elemWithoutRep;
  for (int i = 0; i < cols; ++i)
  {
    elemWithoutRep = 0;
    for (int j = 1; j < rows; ++j)
    {
      if (matrix[i + cols * (j - 1)] != matrix[i + cols * j])
      {
        elemWithoutRep++;
      }
    }
    if (elemWithoutRep + 1 == rows)
    {
      colsWithoutRep++;
    }
  }
  return colsWithoutRep;
}
