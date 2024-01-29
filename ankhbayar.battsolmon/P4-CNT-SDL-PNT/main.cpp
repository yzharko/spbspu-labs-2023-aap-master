#include <iostream>
#include <fstream>
#include "countSaddle.hpp"

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cout << "the number of parameters is not equal to 3.\n";
    return 1;
  }
  char* endOfParsing = nullptr;
  int num = std::strtol(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
    std::cout << "Cannot parse a value.\n";
    return 1;
  }
  if (num != 1 && num !=2)
  {
    std::cout << "enter 1or 2.\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;
  if (!(input >> rows >> cols))
  {
    std::cerr << "Error.\n";
    return 2;
  }
  int fixMatrix[10000] = {0};
  int* matrix = (num==2)? new int [rows * cols] : fixMatrix;

  std::ofstream output(argv[3]);
  output << "number of saddle elements = " << ankhbayar::countSaddle(matrix, rows, cols) << "\n";

  if (num ==2)
  {
    delete[] matrix;
  }
  return 0;
}
