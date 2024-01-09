#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "decreaseSpiralElements.hpp"
#include "inputArray.hpp"
#include "sumArrays.hpp"
int main(int argc, char** argv)
{
  using namespace jirkov;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  char* end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  long long len = strlen(argv[1]);
  if (end != argv[1] + len)
  {
    std::cerr << "Is not a number\n";
    return 3;
  }
  if (num != 2 && num != 1)
  {
    std::cerr << "First parameter is 1 or 2\n";
    return 2;
  }
  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Input Error\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Failed to open output file.\n";
    return 1;
  }
  if (!(input >> rows >> cols) || rows < 0 || cols < 0 || input.fail())
  {
    std::cerr << "Invalid array dimensions\n";
    return 1;
  }
  int matrixStatic[10000];
  int *matrix1 = matrixStatic;
  int *matrix2 = matrixStatic;
  if (rows == 0 && cols == 0)
  {
    printArray(output, matrix1, rows, cols);
  }
  try{
    if (num == 2)
    {
      int *matrixDynamic = new int[rows * cols];
      matrix1 = matrixDynamic;
      matrix2 = matrixDynamic;
    }
    int inputElements = inputArray(input, matrix1, rows, cols);
    if (inputElements != rows * cols)
    {
      throw std::logic_error("2");
    }
    int result[rows * cols];
    decreaseSpiralElements(matrix2, rows, cols);
    sumArrays(matrix1, matrix2, result, rows, cols);
    printArray(output, result, rows, cols);
    if (num == 2)
    {
      delete[] matrix1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    if (num == 2)
    {
      delete[] matrix1;
      matrix1 = nullptr;
      matrix2 = nullptr;
    }
    return 1;
  }
  matrix1 = nullptr;
  matrix2 = nullptr;
}
