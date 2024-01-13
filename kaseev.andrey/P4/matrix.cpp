#include "matrix.hpp"

namespace MatrixStuff {
  size_t NumberOfDiagonals(int *matrixPointer, int n, int m)
  {
    if (matrixPointer == nullptr)
    {
      return 0;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
      bool containsZero = false;

      for (int j = 0; j < m; ++j)
      {
        int index = i * m + j;

        if ((i == j && matrixPointer[index] == 0) || matrixPointer[m - 1] == 0)
        {
          containsZero = true;
        }
        else if (i != j && matrixPointer[index] == 0)
        {
          containsZero = true;
        }
      }

      if (!containsZero)
      {
        count++;
      }
    }
    return count;
  }

  bool upperTriangularMatrix(int *matrixPointer, int n, int m)
  {
    if (matrixPointer == nullptr)
    {
      return false;
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        int index = i * m + j;
        if (i > j && matrixPointer[index] != 0)
        {
          return false;
        }
      }
    }
    return true;
  }
}
