#ifndef DECREASESPIRALELMENTS_HPP
#define DECREASESPIRALELMENTS_HPP
#include <cstddef>
namespace jirkov
{
  void fillTopRow(int* matrix, int rowend, int cols, int& num);
  void fillRightColumn(int* matrix, int colend, int rows, int cols, int& num);
  void fillBottomRow(int* matrix, int rowstart, int colstart, int cols, int& num);
  void fillLeftColumn(int* matrix, int colstart, int rowstart, int cols, int rows, int& num);
  void decreaseSpiralElements(int *matrix, int rows, int cols);
}
#endif
