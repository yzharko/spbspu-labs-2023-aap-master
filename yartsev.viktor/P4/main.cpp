#include <iostream>
#include <fstream>

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
    int a[10000] = {};
    int rows = 0, cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (rows != cols) {
      std::cout << "Not a triangular matrix\n";
      return 0;
    }
    for (int i = 0; i < rows * cols; i++) {
      input >> a[i];
      if (!input) {
        std::cerr << "Not a matrix\n";
        return 2;
      }
    }
    bool isZero = true;
    
  }
  return 0;
}