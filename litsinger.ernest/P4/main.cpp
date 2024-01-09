#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "functioninput.hpp"
#include "variantlogic.hpp"

using namespace litsinger;
int main(int args,char * argv[])
{
  if (args != 4)
  {
    std::cerr << "Problem with arguments\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows, cols;
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Error with input file\n";
    return 2;
  }
  if (!std::strcmp(argv[1], "1") || !std::strcmp(argv[1], "2"))
  {
    std::ofstream output(argv[3]);
    if (rows != cols)
    {
      std::cerr << "Matrix is not a square\n";
      return 0;
    }
    if (rows == 0 || cols == 0)
    {
      output << 0;
      return 0;
    }
  }
  if (!std::strcmp(argv[1], "1"))
  {
    std::ofstream output(argv[3]);
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
    output << MaximalSum(static_array, rows, cols) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    std::ofstream output(argv[3]);
    size_t size_dyn_array = rows * cols;
    int * dynamic_array = new int[size_dyn_array];
    try
    {
      inputArray(input, dynamic_array, size_dyn_array);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamic_array;
      return 2;
    }
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
