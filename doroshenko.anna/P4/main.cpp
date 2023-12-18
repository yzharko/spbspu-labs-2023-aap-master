#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "findingLocMax.hpp"
#include "inputArray.hpp"

int main(int argc, char** argv)
{
  using namespace doroshenko;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  char* endOfParcing = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(endOfParcing), 10);
  long long lenOfArg = strlen(argv[1]);
  if (endOfParcing != argv[1] + lenOfArg)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if (num > 2 || num < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t rows_;
  size_t cols_;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "File not open\n";
    return 2;
  }
  input >> rows_ >> cols_;
  if (!input)
  {
    std::cerr << "It is not number\n";
    return 2;
  }
  if (rows_ < 3 || cols_ < 3)
  {
    return 0;
  }
  int staticMatrix[10000] = { 0 };
  int* Matrix = (num == 2)? new int[rows_ * cols_] : staticMatrix;
  size_t readEl = inputArray(input, Matrix, rows_ * cols_);
  if (readEl != rows_ * cols_)
  {
    std::cerr << "Not all elements were read";
    if (num == 2)
    {
      delete[] Matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "File not open\n";
    if (num == 2)
    {
      delete[] Matrix;
    }
    return 2;
  }
  output << findingLocMax(Matrix, rows_, cols_);
  if (num == 2)
  {
    delete[] Matrix;
  }
  return 0;
}
