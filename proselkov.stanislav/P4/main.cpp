#include <iostream>
#include <fstream>
#include <string>
#include "inputArray.hpp"
#include "matrix.hpp"
#include "outputArray.hpp"

using namespace proselkov;
int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

  int num = 0;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot parse a value!!!!\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }

  if (num == 1)
  {
    int* matrix = new int[rows * cols];
    size_t result = proselkov::inputArray(std::cin, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Read " << result << " elements..\n";
      delete[] matrix;
      return 3;
    }
    proselkov::outputArray(argv[3], matrix, rows, cols);
    return 0;
  }
  if (num == 2)
  {
    int** m1 = nullptr;
    int** m2 = nullptr;
    try
    {
      m1 = proselkov::createMatrix(rows, cols);
      m2 = proselkov::createMatrix(rows, cols);
      proselkov::freeMatrix(m1, rows, cols);
      proselkov::freeMatrix(m2, rows, cols);
    }
    catch (...)
    {
      //delete[] matrix;
      proselkov::freeMatrix(m1, rows, cols);
      proselkov::freeMatrix(m2, rows, cols);
      return 3;
    }
    //delete[] matrix;
    std::ofstream output(argv[3]);
    output << rows << " " << cols << "\n";
    return 0;
  }
  else
    return 2;
  {
    //std::ofstream output(argv[3]);
    //output << rows << " " << cols << "\n";
  }
  return 0;
}
