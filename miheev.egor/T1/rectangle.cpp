#include "rectangle.hpp"
#include <cmath>

miheev::Rectangle::Rectangle(point_t* points):
  width_(-1),
  height_(-1)
{
  double diag = 0;
  points_[0] = points[0]; // base point
  size_t nonDiag[2] = {0};
  size_t indexNonDiag = 0;
  for (size_t i = 1; i < 4; i++)
  {
    double dist = points_[0].distTo(points[i]);
    if (dist > diag)
    {
      diag = dist;
      points_[2] = points[i]; // temporary diag diagonal to base
    }
    else
    {
      nonDiag[indexNonDiag] = i;
      indexNonDiag++;
    }
  } // 0 -> 2 is diagonal

  points_[1] = points[indexNonDiag[0]];
  points_[3] = points[indexNonDiag[1]]; // 1 -> 3 is diagonal
}


