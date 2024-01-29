#ifndef COUNT_SADDLE_HPP
#define COUNT_SADDLE_HPP

namespace ankhbayar
{
  int searchMinInLine(const int* matrix, int cols, int numLine);
  int searchMaxInCol(const int* matrix, int rows, int cols, int minEl, int numLine);
  int countSaddle(const int* matrix, int rows, int cols);
}
#endif
