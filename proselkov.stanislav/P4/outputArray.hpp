#ifndef OUTPUT_ARRAY_HPP
#define OUTPUT_ARRAY_HPP
#include <iosfwd>
#include <cstddef>

namespace proselkov
{
  size_t outputArray(char* arvg3, int* matrix, size_t s, size_t toRead);
  int linemin(int first, int second, int three);
  int locmin(int first, int second, int three, int four);
  int CountLocMin(int matrix[], int rows, int cols);
}
#endif
