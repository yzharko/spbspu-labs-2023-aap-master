#include "matrix.hpp"
#include <memory>
#include <fstream>
#include <iostream>

int** proselkov::createMatrix(size_t rows, size_t cols)
{
  int** rowsPtrs = new int* [rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsPtrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsPtrs[i] = new int[cols];
    }
    return rowsPtrs;
  }
  catch (const std::bad_alloc& e)
  {
    freeMatrix(rowsPtrs, rows, cols);
    throw e;
  }
}

void proselkov::freeMatrix(int** matrix, size_t rows)
{
  if (!matrix)
  {
    std::cerr << "Alas.\n";
    //return 1;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void proselkov::freeMatrix(int** matrix, size_t rows, size_t)
{
  freeMatrix(matrix, rows);
}
