#include "outputArray.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

void mihalchenko::outputDinArray(char* argv3, float* matrix, size_t rows, size_t cols)
{
  float* matrixNew = new float[rows * cols];

  int countNew = 0;
  int sum = 0;

  for (size_t m = 0; m < rows; m++)
  {
    for (size_t n = 0; n < cols; n++)
    {
      countNew = 0;
      sum = 0;
      size_t sch;
      (m > 0) ? (sch = m - 1) : (sch = 0);
      for (size_t i = sch; i <= m + 1; i++)
      {
        if (i < rows)
        {
          size_t schNext;
          (n > 0) ? (schNext = n - 1) : (schNext = 0);
          for (size_t j = schNext; j <= n + 1; j++)
          {
            if (j < cols)
            {
              if ((m == i) and (n == j))
              {
                continue;
              }
              else
              {
              countNew++;
              sum += matrix[i * cols + j];
              }
            }
          }
        }
      }
      if (countNew != 0)
      {
        matrixNew[m * cols + n] = float(sum) / countNew;
      }
    }
  }
  std::ofstream output(argv3);
  output << rows << " " << cols << " ";
  for (size_t i = 0; i < rows * cols; ++i)
  {
    output << static_cast<float>(round(matrixNew[i] * 10)) / 10 << " ";
  }
  delete[] matrixNew;
}
