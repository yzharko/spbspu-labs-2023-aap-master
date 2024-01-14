#include <iostream>
#include <fstream>
#include <cstring>
#include "inputArray.hpp"
#include "countCols.hpp"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "wrong number of arguments\n";
    return 1;
  }
  char * endOfParsing = nullptr;
  int num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
      std::cerr << "wrong first argument\n";
      return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "the first argument must be 1 or 2\n";
    return 1;
  }
  int rows;
  int cols;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  int matrixSize = rows * cols;
  if (!input)
  {
    std::cerr << "can't read input\n";
    return 2;
  }
  int staticMatrix[10000] = {};
  int * matrix = num == 1 ? &staticMatrix[0] : new int[matrixSize];
  int countedElem = redko::inputArray(input, matrix, matrixSize);
  if (countedElem < matrixSize)
  {
    std::cerr << "error while filling array: counted only " << countedElem << " elements\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  int result = redko::countCols(matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }
  std::ofstream output(argv[3]);
  output << result;
  return 0;
}
