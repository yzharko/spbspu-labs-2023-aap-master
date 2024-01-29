#include "countSaddle.hpp"

int ankhbayar::searchMinInLine(const int* matrix, int cols, int numLine)
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

int ankhbayar::searchMaxInCol(const int* matrix, int rows, int cols, int minEl, int numLine)
{
  int maxEl = 0;
  for (int i = (cols *  numLine); i < (cols + cols * numLine); i++)
  {
    if(minEl == matrix [i])
    {
      int numOfColumn = i % cols;
      maxEl = matrix[numOfColumn];
      for (int j= numOfColumn; j <= numOfColumn + (cols*(rows-1)); j += cols)
      {
        maxEl = matrix[j] > maxEl ? matrix[j] : maxEl;
      }
    }
  }
  return maxEl;
}

int ankhbayar::countSaddle(const int* matrix, int rows, int cols)
{
  int numOfSaddEl = 0, minEl = 0, maxEl = 0;
  for (int j=0; j < rows; j++)
  {
    minEl = ankhbayar::searchMinInLine(matrix, cols, j);
    maxEl = ankhbayar::searchMaxInCol(matrix, rows, cols, minEl, j);
    if(minEl==maxEl)
    {
      numOfSaddEl += 1;
    }
  }
  return numOfSaddEl;
}
