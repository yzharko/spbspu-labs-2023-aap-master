#include <iostream>
#include <exception>
#include <fstream>
#include "spiralSub.hpp"
#include "incPer.hpp"
#include "inputArray.hpp"

int main(int argc, char ** argv)
{
  using namespace khomichenko;

  if (argc != 4)
  {
    std::cerr << "something wrong.\n";
    return 1;

  }

  int num = 0;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "can not parse a value\n";
    return 1;
  }

  if (num > 2 || num < 1)
  {
    std::cerr << "first parameter is out of range\n";
    return 1;
  }

  size_t rows;
  size_t cols;

  std::ifstream input (argv[2]);
  if (!input)
  {
    std::cerr << "can not read file\n";
    return 2;
  }

  input >> rows >> cols;

  if (!input)
  {
    std::cerr << "can't read cols and rows\n";
    return 2;
  }

  int firstMatrix[10000] = {0};
  int *Matrix = nullptr;

  Matrix = num==2?new int[rows * cols]:firstMatrix;

  size_t hadRead = inputArray(input, Matrix, rows*cols);

  if (hadRead != rows*cols)
  {
    std::cerr << "not all elements were read\n";
    if (num == 2)
    {
      delete [] Matrix;
    }
    return 2;
  }

  std::ofstream output (argv[3]);
  output << rows << " " << cols << " ";
  if (!output)
  {
    std::cerr<<"file not open\n";
    if (num==2)
    {
      delete[] Matrix;
    }
    return 2;
  }
  if (cols * rows != 0)
  {
    //FLL-INC-WAV
    callFunc(Matrix, cols, rows);
    for (size_t i = 0; i < cols*rows; ++i)
    {
      output << Matrix[i] << " ";
    }
    output << "\n";
    output << "\n";
    output << rows << " " << cols << " ";
    //LFT-TOP-CLK
    callFuncSec(Matrix, cols, rows);
    for (size_t i = 0; i < cols*rows; ++i)
    {
      output << Matrix[i] << " ";
    }
    output << "\n";
  }
  else
  {
    output << "\n";
  }

  if (num == 2)
  {
    delete [] Matrix;
  }
  return 0;
}
