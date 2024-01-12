#ifndef SCALEFUNC_HPP
#define SCALEFUNC_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva {
  void getCoordinates(sukacheva::rectangle_t frameRect);
  void getRectangle(Shape* figures[], double x1, double y1, double x2, double y2, int& index);
  void getCircle(Shape* figures[], double x, double y, double radius, int& index);
  void getParallelogram(Shape* figures[], double x1, double y1, double x2, double y2, double x3, double y3, int& index);
}

#endif
