#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "function.hpp"

using namespace litsinger;
int main(int args,char * argv[])
{
  if (args < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (args > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Error\n";
    return 2;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    if (rows != cols)
    {
      std::cerr << "Matrix is not a square\n";
      return 0;
    }
    if (rows == 0 || cols == 0)
    {
      std::cerr << "Error\n";
      return 0;
    }
    int static_array[10000] = {0};
    try
    {
      inputArray(input, static_array, rows * cols);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    output << MaximalSum(static_array, rows, cols) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (rows != cols)
    {
      std::cerr << "Rows and cols are different\n";
      return 0;
    }
    if (rows == 0 || cols == 0)
    {
      std::cerr << "Error\n";
      return 0;
    }
    int * dynamic_array = new int[rows * cols];
    try
    {
      inputArray(input, dynamic_array, rows * cols);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamic_array;
      return 2;
    }
    std::ofstream output(argv[3]);
    try
    {
      if ((rows != cols) || (rows = 0 || cols == 0))
      {
        throw std::invalid_argument("Rows and cols are different\n");
      }
      output << MaximalSum(dynamic_array, rows, cols);
    }
    catch (const std::invalid_argument& e)
    {
      delete[] dynamic_array;
      std::cerr << e.what();
      return 0;
    }
    delete[] dynamic_array;
  }
  else
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}
