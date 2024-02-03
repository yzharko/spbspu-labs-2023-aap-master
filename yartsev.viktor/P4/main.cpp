#include <iostream>
#include <fstream>
#include "checkmatrix.hpp"
#include "arrfuncs.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  } else if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  int num = 0;
  try {
    num = std::stol(argv[1]);
    if (num < 1 || num > 2) {
      std::cerr << "First parameter is out of range\n";
      return 1;
    }
  } catch (std::invalid_argument & e) {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  int rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  int a[10000] = {};
  int * matrix = nullptr;
  if (num == 1) {
    matrix = a;
  } else {
    matrix = new int [rows * cols];
  }
  try {
    yartsev::readArray(matrix, cols, rows, input);
  } catch (const std::logic_error & e) {
    std::cerr << e.what() << "\n";
    return 2;
  }
  if (yartsev::isLowerTriangularMatrix(matrix, cols, rows)) {
    std::cout << "Is triangular matrix\n";
  } else {
    std::cout << "Not a triangular matrix\n";
  }

  return 0;
}