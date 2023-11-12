#include <iostream>
#include <fstream>

int readArray(int * matrix, int cols, int rows, std::ifstream & in)
{
  for (int i = 0; i < rows * cols; i++) {
    in >> matrix[i];
    if (!in) {
      return 2;
    }
  }
  return 0;
}

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

  if (num == 1) {
    int matrix[10000] = {};
    int rows = 0, cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (rows != cols) {
      std::cout << "Not a triangular matrix\n";
      return 0;
    }
    int result = readArray(matrix, cols, rows, input);
    if (result == 2) {
        std::cout << "Not a matrix\n";
        return 2;
    }
    /*bool isZero = true;
    for (int i = 0; i < rows && isZero; i++) {
      for (int j = 0; j < cols && isZero; j++) {
        if (j < i) {
            isZero = (isZero && a[i * rows + j] == 0);
        }
      }
    }*/

  }
  return 0;
}