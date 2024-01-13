#include "figuresValidating.hpp"

bool miheev::validateTriangle(point_t A, point_t B, point_t C)
{
  bool condition1 = A.distTo(B) + A.distTo(C) > B.distTo(C);
  bool condition2 = B.distTo(C) + A.distTo(B)> A.distTo(C);
  bool condition3 = A.distTo(C) + B.distTo(C)> A.distTo(B);
  return condition1 && condition2 && condition3;
}

bool miheev::validateParallelogram(point_t A, point_t B, point_t C)
{
  if (!(A.y == B.y || B.y == C.y) || !(validateTriangle(A, B, C)))
  {
    return 0;
  }
  return 1;
}
