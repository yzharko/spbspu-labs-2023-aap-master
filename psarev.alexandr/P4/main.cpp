#include <iostream>
#include <fstream>
#include "inputMatrix.hpp"
#include "checkMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Error: Wrong amount of parameters!\n";
    return 1;
  }
  char* endOfParsing = nullptr;
  int taskNum = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
    std::cerr << "Error: First argument must be integer!\n";
    return 1;
  }
  if (taskNum != 1 && taskNum != 2) {
    std::cerr << "Error: Wrong first argument value!\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;
  if (!(input >> rows >> cols)) {
    std::cerr << "Error: Can't read input file!\n";
    return 2;
  }
  int stMatrix[10000] = { 0 };
  int* matrix = (taskNum == 2) ? new int[rows * cols] : stMatrix;

  if (psarev::inputMatrix(input, matrix, rows * cols) != (rows * cols)) {
    std::cerr << "Error: Mismatch of dimension and values!\n";
    if (taskNum == 2) {
      delete[] matrix;
    }
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Error: Can't open an output file!\n";
    if (taskNum == 2) {
      delete[] matrix;
    }
    return 2;
  }

  psarev::isTriMatrix(matrix, rows, cols) == 1 ? output << "true\n" : output << "false\n";
  if (taskNum == 2) {
    delete[] matrix;
  }
  return 0;
}
