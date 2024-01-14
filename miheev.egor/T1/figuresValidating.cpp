#include "figuresValidating.hpp"
#include "geometricalMethods.hpp"

bool miheev::validateTriangle(point_t A, point_t B, point_t C)
{
  bool condition1 = findDist(A, B) + findDist(A, C) > findDist(B, C);
  bool condition2 = findDist(B, C) + findDist(A, B)> findDist(A, C);
  bool condition3 = findDist(A, C) + findDist(B, C)> findDist(A, B);
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
