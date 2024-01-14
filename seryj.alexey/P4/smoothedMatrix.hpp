#ifndef SMOOTHED_HPP
#define SMOOTHED_HPP
#include <fstream>
#include <cstddef>
namespace seryj
{
  void printAvgOfNeigbours(size_t line, size_t column, std::ofstream&, int* values);
  double findAverageOfNeighbours(size_t curr_line, size_t curr_column, size_t max_line, size_t max_column, int* values);
}
#endif
