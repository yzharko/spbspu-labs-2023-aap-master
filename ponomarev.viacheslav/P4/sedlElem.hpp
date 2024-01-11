#ifndef SEDL_ELEM_HPP
#define SEDL_ELEM_HPP

namespace ponomarev
{
  int searchMinInLine(const int * matrix, int cols, int numLine);
  int searchMaxInCol(const int * matrix, int rows, int cols, int minEl, int numLine);
  int saddleElem(const int * matrix, int rows, int cols);
}
#endif
