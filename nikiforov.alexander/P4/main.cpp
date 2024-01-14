#include <iostream>
#include <string>
#include "CreateMatrix.hpp"

int main(int argc, const char* argv[])
{
  if (argc != 4) {
    std::cerr << "Not enough args.\n";
    return 1;
  }

  char* endOfParsing = nullptr;
  int num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
    std::cerr << "First parameter is not number\n";
    return 1;
  }

  if (num != 1 && num != 2)
  {
    std::cerr << "Incorrect value of the first argument\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows >> cols))
  {
    std::cerr << "Cannot read an input.\n";
    return 2;
  }

  if (rows != cols) {
    std::cerr << "Error: Matrix is not square.";
    return 1;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Error: Can't open an output file!\n";
    return 2;
  }

  size_t score = rows * cols;
  int staticArr[10000] = {};
  int* arr = nullptr;

  if (num == 1)
  {
    arr = staticArr;
  }
  else if (num == 2)
  {
    arr = new int[score];
  }

  if (nikiforov::inputMatrix(input, arr, score) != score)
  {
    std::cerr << "Mismatch of dimension and values!\n";
    if (num == 2) {
      delete[] arr;
      arr = nullptr;
    }
    return 2;
  }

  nikiforov::spiralMatrix(output, arr, rows, cols);

  if (num == 2) {
    delete[] arr;
    arr = nullptr;
  }
  return 0;
}
