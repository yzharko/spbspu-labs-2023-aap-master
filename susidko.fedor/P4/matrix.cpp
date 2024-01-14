#include "matrix.hpp"
#include <iostream>
#include <memory>

int susidko::countUniqueRows(const int * matrix, size_t rows, size_t cols)
{
  int res = 0;
  int flag;
  for (size_t i = 0; i < rows; i++)
  {
    flag = 1;
    for (size_t j = 1; j < cols; j++)
    {
      if(matrix[i*cols+j] == matrix[i*cols+j-1])
      {
        flag = 0;
      }
    }
    res += flag;
  }
  return res;
}

int susidko::getColNumber(const int * matrix, size_t rows, size_t cols)
{
  int mmax = 0;
  int counter = 0;
  int res = 0;
  for (size_t j = 0; j < cols; j++)
  {
    for (size_t i = 1; i < rows; i++)
    {
      counter = 0;
      if(matrix[i*cols+j] == matrix[(i-1)*cols+j])
      {
        counter += 1;
      }
      else
      {
        counter = 0;
      }
    }
    if (counter > mmax)
    {
      mmax = counter;
      res = j + 1;
    }
  }
  return res;
}
