#include <iostream>
#include <fstream>
#include <string>
#include "matrix.hpp"
#include "InputArray.hpp"

int main(int argc, char** argv)
{
  using namespace ankhbayar;

  if (argc != 4)
  {
    std::cerr << "Wrong number of elements.\n";
    return 1;
  }

  char* end;
  long long num = std::strtoll(argv[1], &end, 10);
  if (*end != '\0')
  {
    std::cout << "Input error: argument is not a number.\n";
    return 3;
  }

  size_t rows = 1, cols = 1;
  std::ifstream input(argv[2]);
  try
  {
    input >> rows;
    input >> cols;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot read an input.\n";
    return 2;
  }
  if (cols == 0 || rows == 0)
  {
    return 0;
  }

  if (num == 1)
  {
    int staticMatrix[10000];
    for (size_t i = 0; i < rows * cols; i++)
    {
      input >> staticMatrix[i];
      if (!input)
      {
        std::cerr << "Cannot read an array.\n";
        return 2;
      }
    }
    {
      std::ofstream output(argv[3]);
      output << MaxSideDiagonal(staticMatrix, cols) << "\n"
             << upperTriangularMatrix(staticMatrix, cols, rows);
    }
  }
  else if (num == 2)
  {
    int* dynamicMatrix = new int[rows * cols];
    size_t result = inputMatrix(input, dynamicMatrix, rows * cols, rows * cols);
    if (!(result == rows * cols))
    {
      std::cerr << "Read " << result << " elements.\n";
      delete [] dynamicMatrix;
      return 3;
    }
    {
      std::ofstream output(argv[3]);
      output << MaxSideDiagonal(dynamicMatrix, rows) << "\n"
             << upperTriangularMatrix(dynamicMatrix, cols, rows);
    }
    delete[] dynamicMatrix;
  }
  else
  {
    std::cerr << "Argument is out of range. \n";
    return 1;
  }
  return 0;
}
