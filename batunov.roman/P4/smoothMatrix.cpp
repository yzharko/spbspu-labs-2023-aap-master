#include "smoothMatrix.hpp"

double* batunov::smoothMatrix(int** matrix, int rows, int cols)
{
  double* smoothedMatrix = new double[rows * cols];
  int index = 0;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      double sum = 0.0;
      int count = 0;
      for (int x = -1; x <= 1; x++)
      {
        for (int y = -1; y <= 1; y++)
        {
          int row = i + x;
          int col = j + y;
          if (row >= 0 && row < rows && col >= 0 && col < cols && !(x == 0 && y == 0))
          {
            sum += matrix[row][col];
            count++;
          }
        }
      }
      double smoothedValue = sum / count;
      smoothedMatrix[index] = smoothedValue;
      index++;
    }
  }
  return smoothedMatrix;
}
