#include "InputOutput.hpp"

namespace MatrixStuff
{
  void writeResult(std::ostream &output, int result, bool UpperTriangularMatrix)
  {
    if (UpperTriangularMatrix)
    {
      output << result << "\n" << "true";
    } else
    {
      output << result << "\n" << "false";
    }
  }

  int readMatrix(std::istream &input, int *matrixPointer, int n, int m)
  {
    int count = 0;
    for (int i = 0; i < n * m; ++i)
    {
      if (!(input >> matrixPointer[i]))
      {
        return count;
      }
      count += 1;
    }
    return count;
  }
}
