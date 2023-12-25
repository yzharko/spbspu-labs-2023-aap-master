#include "Functions.hpp"
#include <iostream>
#include <fstream>
namespace toksen
{
  std::ifstream input;
  std::ofstream output;
  int fillArguments(int args, const char* argv[]) {
    
    if (args > 4) {
      throw (std::invalid_argument("There are more arguments than should be!"));
    }
    if (args < 4) {
      throw (std::invalid_argument("There are not enough arguments!"));
    }
    input.open(argv[2]);
    output.open(argv[3]);
    int a = std::strtoll(argv[1], nullptr, 10);
    if (a < 1 || a > 2) {
      throw(std::invalid_argument("Invalid argument!"));
    }
    return a;
    }

  int readInput() {
    int value = 0;
    if (input.is_open() && input) {
      input >> value;
    }
    else if (!input.is_open()) {
      throw std::invalid_argument("Can not open input.txt file.");
    }
    if (!input) {
      throw std::logic_error("Input error!");
    }
    return value;
    }

  void Matrix::fillArray()
  {
    int count = 0;
    while (input.good())
    {
      *(values + count) = readInput();
      count++;
    }
    if (count < line * column) {
      throw std::logic_error("There are not enough elements.");
    }
  }

  void Matrix::writeAnswer() const {
    if (output.is_open()) {
      output << line << " ";
      output << column << " ";
      for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++) {
          output << findAnswer(i,j) << " ";
        }
    }
    else {
      throw (std::invalid_argument("Can not open output file!"));
    }
    output.close();
    }

  double Matrix::findAnswer(int rows, int cols) const {
    double diagonalCount = 0.0;
    if (rows <= 0 || cols <= 0 || rows > 10000 || cols > 10000) {
      throw (std::invalid_argument("Invalid Argument!"));
      return 2;
    }

    double matrix1[10000][10000];
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
      std::cin >> matrix1[i][j];
      }
    }

    for (int i = 0; i < rows; ++i) {
      bool hasZero = false;
      bool isParallel = true;
      for (int j = 0; j < cols; ++j) {
        if (matrix1[i][j] == 0) {
          hasZero = true;
          break;
        }
        if (j != i && matrix1[i][j] != matrix1[j][i]) {
          isParallel = false;
          break;
        }
      }
      if (!hasZero && isParallel) {
      diagonalCount++;
      }
    }
    return diagonalCount;
  }
}
