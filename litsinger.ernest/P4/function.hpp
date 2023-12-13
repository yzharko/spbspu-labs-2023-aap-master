#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <cstddef>
#include <fstream>
namespace litsinger
{
  void inputArray(std::ifstream & input, int * matrix, size_t sizeMatrix);
  int MaximalSum(const int * arr, size_t rows, size_t cols);
}
#endif
