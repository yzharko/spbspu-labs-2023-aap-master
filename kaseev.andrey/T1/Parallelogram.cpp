#include <iostream>
#include "Parallelogram.hpp"
#include " base-types.hpp"
#include <cmath>

kaseev::Parallelogram::Parallelogram(point_t A, point_t B, point_t C):
A(A),
B(B),
C(C)
{}

double kaseev::Parallelogram::getArea() const
{
  double fSide = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
  double sSide = sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));

}