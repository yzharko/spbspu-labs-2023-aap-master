#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "InputArray.hpp"

int main(int argc, char** argv)
{
  using namespace sukacheva;

  if (argc != 4)
  {
    std::cerr << "Wrong number of elements.\n";
    return 1;
  }

  char* end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  if (*end != '\0')
  {
    std::cout << "Input error: argument is not a number.\n";
    return 3;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Uable to read file.\n";
    return 2;
  }
  if (cols == 0 || rows == 0)
  {
    return 0;
  }
  if (num == 1 || num == 2)
  {
    size_t sizeOfMatrix = rows * cols;
    int staticMatrix[10000];
    int* resultMatrix = (num == 1) ? staticMatrix : new int[sizeOfMatrix];
    size_t result = inputMatrix(input, resultMatrix, sizeOfMatrix, sizeOfMatrix);
    if (!(result == sizeOfMatrix))
    {
      std::cerr << "Cannot read an array. Read " << result << " elements.\n";
      if (num == 2)
      {
        delete[] resultMatrix;
      }
      return 2;
    }
    std::ofstream output(argv[3]);
    output << MaxSideDiagonal(resultMatrix, rows) << "\n" << upperTriangularMatrix(resultMatrix, cols, rows);
    if (num == 2)
    {
      delete[] resultMatrix;
    }
  }
  else
  {
    std::cerr << "Argument is out of range. \n";
    return 1;
  }
  return 0;
}
