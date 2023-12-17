#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "InputOutput.hpp"

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cerr << "There are wrong number of arguments";
    return 1;
  }
  char *endptr = nullptr;
  long long int num = std::strtol(argv[1], std::addressof(endptr), 10);
  if (num != 1 && num != 2)
  {
    std::cerr << "Wrong type of matrix";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  int m = 0, n = 0;
  if (!(input >> n >> m))
  {
    std::cerr << "There are wrong number of arguments";
    return 1;
  }
  if (m < 0 || n < 0)
  {
    std::cerr << "Wrong marix size!";
    return 1;
  }
  else if (m == 0 && n == 0)
  {
    if (output.is_open())
    {
      MatrixStuff::writeResult(output, 0, false);
      output.close();
    }
  }
  try
  {
    int matrix[10000];
    int *matrixPointer = matrix;
    if (num == 2)
    {
      int *matrixD = new int[n * m];
      matrixPointer = matrixD;
    }
    int matrixCheck = MatrixStuff::readMatrix(input, matrixPointer, n, m);
    if (matrixCheck != m * n)
    {
      if (num == 2)
      {
        delete[] matrixPointer;
      }
      throw std::logic_error("invalid matix input");
    }
    size_t count = MatrixStuff::NumberOfDiagonals(matrixPointer, n, m);
    bool UpperTriangularMatrix = MatrixStuff::upperTriangularMatrix(matrixPointer, n, m);
    if (num == 2)
    {
      delete[] matrixPointer;
    }
    if (output.is_open())
    {
      MatrixStuff::writeResult(output, count, UpperTriangularMatrix);
    }
  }
  catch (const std::exception &err)
  {
    std::cerr << err.what() << "\n";
    return 2;
  }

}
