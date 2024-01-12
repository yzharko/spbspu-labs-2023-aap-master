#ifndef HELPFULFUNCS_HPP
#define HELPFULFUNCS_HPP
#include <cctype>
#include "shape.hpp"

namespace khoroshkin
{
  bool isRectangleCorrect(double x1, double y1, double x2, double y2);
  bool isComplexquad(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
  Shape ** expandArray(Shape ** array, size_t currSize, size_t newSize);
}

#endif