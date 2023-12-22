#include <iostream>
#include <fstream>
#include "findCntLocMin.hpp"
#include "inputArray.hpp"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }
  char* endNum;
  int num = std::strtoll(argv[1], std::addressof(endNum), 10);
  if (*endNum != '\0')
  {
    std::cerr << "Cannot parse values\n";
    return 3;
  }
  if (num == 1 || num == 2)
  {
    int resultNum = 0;
    std::ifstream input(argv[2]);
    size_t rows, cols;
    input >> rows >> cols;
    size_t matrixSize = rows * cols;
    if (!input)
    {
      std::cerr << " Cannot read an input.\n";
      return 2;
    }
    int matrixStatic[matrixSize];
    int* matrix = (num == 2) ? new int[matrixSize] : matrixStatic;
    if((taskaev::inputArray(input, matrix, matrixSize, matrixSize)) != (matrixSize))
    {
      if (num == 2)
      {
        delete[] matrix;
      }
      std::cerr <<"Error matrix cannot read.\n";
      return 2;
    }
    resultNum = taskaev::findCntLocMin(matrix, rows, cols);
    std::ofstream output(argv[3]);
    output << resultNum;
    if (num == 2)
    {
      delete[] matrix;
    }
  }
  else
  {
    std::cerr << "Error num != 1 or num != 2.\n";
    return 2;
  }
  return 0;
}
