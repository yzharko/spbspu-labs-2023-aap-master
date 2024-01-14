#include "sedlElem.hpp"

int ponomarev::searchMinInLine(const int * matrix, int cols, int numLine)
{
  int minEl = matrix[cols * numLine];
  for (int i = (cols * numLine); i < (cols + cols * numLine); i++)
    {
      if (minEl > matrix[i])
      {
        minEl = matrix[i];
      }
    }
  return minEl;
}

int ponomarev::searchMaxInCol(const int * matrix, int rows, int cols, int minEl, int numLine)
{
  int maxEl = 0;
  for (int i = (cols * numLine); i < (cols + cols * numLine); i++)
  {
    if (minEl == matrix[i])
    {
      int numOfColumn = i % cols;
      maxEl = matrix[numOfColumn];
      for (int j = numOfColumn; j <= numOfColumn + (cols * (rows - 1)); j += cols)
      {
        maxEl = matrix[j] > maxEl ? matrix[j] : maxEl;
      }
    }
  }
  return maxEl;
}

int ponomarev::saddleElem(const int * matrix, int rows, int cols)
{
  int numOfSaddEl = 0, minEl = 0, maxEl = 0;
  for (int j = 0; j < rows; j++)
  {
    minEl = ponomarev::searchMinInLine(matrix, cols, j);
    maxEl = ponomarev::searchMaxInCol(matrix, rows, cols, minEl, j);
    if (minEl == maxEl)
    {
      numOfSaddEl += 1;
    }
  }
  return numOfSaddEl;
}
