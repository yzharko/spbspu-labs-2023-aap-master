#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments.\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments.\n";
    return 1;
  }

  int num;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "First parameter is not a number.\n";
    return 1;
  }
  if (num > 2)
  {
    std::cerr << "First parameter out of range.\n";
    return 1;
  }

  size_t rows;
  size_t columns;
  int result;
  std::ifstream inputStream;
  inputStream.open(argv[2]);
  if (!inputStream)
  {
    std::cerr << "The file could not be opened.\n";
    return 2;
  }
  inputStream >> rows >> columns;
  if (!inputStream)
  {
    std::cerr << "Could not read file contents.\n";
    return 2;
  }

  if (num == 1)
  {
    int * matrix = {0};
    try
    {
      LabP4::InputMatrixAsArray(inputStream, matrix, rows, columns);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what();
      return 2;
    }
    result = LabP4::MaxSumParallelToSDG(matrix, rows, columns);
  }
  else
  {
    int * matrix = new int[rows * columns];
    try
    {
      LabP4::InputMatrixAsArray(inputStream, matrix, rows, columns);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what();
      return 2;
    }
    result = LabP4::MaxSumParallelToSDG(matrix, rows, columns);
    delete[] matrix;
  }
  inputStream.close();
  std::ofstream outputStream;
  outputStream.open(argv[3]);
  if (!outputStream)
  {
    std::cerr << "The output file could not be opened.\n";
    return 2;
  }
  outputStream << result;
  outputStream.close();
  return 0;
}
