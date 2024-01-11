#include "freeMatrix.hpp"

void batunov::freeMatrix(int** matrix, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}
