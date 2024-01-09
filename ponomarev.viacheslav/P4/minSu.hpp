#ifndef MIN_SU_HPP
#define MIN_SU_HPP

namespace ponomarev
{
  int sumBeforeDiag(const int * matrix, int rows);
  int sumAfterDiag(const int * matrix, int cols, int rows, int minSum);
  int minSu(const int * matrix, int rows, int cols);
}
#endif
