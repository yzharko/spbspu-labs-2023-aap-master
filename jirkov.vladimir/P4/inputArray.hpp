#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace jirkov
{
  int inputArray(std::istream &, int *matrix, int rows, int cols);
  void printArray(std::ostream &, int const *matrix, int rows, int cols);
}
#endif
