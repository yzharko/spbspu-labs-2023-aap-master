#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "inputArray.hpp"
#include "matrix.hpp"

int main(int argc, char** argv)
{
  using namespace hohlova;
  if (argc != 4)
  {
    std::cerr << "Something wrong, problem with number of arguments\n";
    return 1;
  }
  char* seqEnd = nullptr;
  int num = std::strtoll(argv[1], std::addressof(seqEnd), 10);
  if (num != 1 && num != 2)
  {
    std::cerr << "First arg 1 or 2\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows, cols;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot open an input file\n";
    return 2;
  }
  size_t matrixSize = rows * cols;
  if (num == 1 || num == 2)
  {
    std::ofstream output(argv[3]);
    if (rows != cols)
    {
      std::cerr << "Not a square\n";
    }
  }
  if (num == 1)
  {
    std::ofstream output(argv[3]);
    int staticm[1000] = { 0 };
    size_t sizeM = hohlova::inputArray(input, staticm, matrixSize);
    if (sizeM != matrixSize)
    {
      std::cerr << "Not all elements are read\n";
      return 2;
    }
    try
    {
      hohlova::inputArray(input, staticm, matrixSize);
    }
    catch (std::logic_error const& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    output << hohlova::countStrings(staticm, rows, cols);
  }
  else if (num == 2)
  {
    std::ofstream output(argv[3]);
    int* dynamicm = new int[matrixSize];
    size_t toRead = hohlova::inputArray(input, dynamicm, matrixSize);
    if (toRead != matrixSize)
    {
      delete[] dynamicm;
      std::cerr << "Not all elements are read\n";
      return 1;
    }
    try
    {
      hohlova::inputArray(input, dynamicm, matrixSize);
    }
    catch (std::logic_error const& e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamicm;
      return 2;
    }
    try
    {
      output << hohlova::countStrings(dynamicm, rows, cols);
    }
    catch (std::invalid_argument const& e)
    {
      delete[] dynamicm;
      std::cerr << e.what();
      return 0;
    }
    delete[] dynamicm;
  }
  else
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}

