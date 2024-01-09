#include "matrixCheck.hpp"
#include <iostream>

int gorbunova::isUpperTriangular(int matrix[100][100], int rows, int cols)
{
  if (rows != cols)
  {
    std::cerr << "Matrix is not square\n";
    return 2;
  }
  if (rows == 0)
  {
    return 0;
  }
  for (int i = 1; i < rows; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (matrix[i][j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

int gorbunova::isUpperTriangular(int** matrix, int rows, int cols)
{
  if (rows != cols)
  {
    std::cerr << "Matrix is not square\n";
    return 2;
  }
  if (rows == 0)
  {
    return 0;
  }
  for (int i = 1; i < rows; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (matrix[i][j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

