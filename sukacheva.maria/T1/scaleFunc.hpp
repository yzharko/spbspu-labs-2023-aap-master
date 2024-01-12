#ifndef SCALEFUNC_HPP
#define SCALEFUNC_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva {
  void getCoordinates(rectangle_t frameRect);
  void getCoordinatesBefore(Shape* figures[], int index);
  void getCoordinatesAfter(Shape* figures[], int index, point_t center, double k);
  void getRectangle(Shape* figures[], double x1, double y1, double x2, double y2, int& index);
  void getCircle(Shape* figures[], double x, double y, double radius, int& index);
  void getParallelogram(Shape* figures[], double x1, double y1, double x2, double y2, double x3, double y3, int& index);
  void deleteArray(Shape* figures[], int index);
  void getFirstArea(Shape* figures[], int index, double& firstArea);
  void getScaledArea(Shape* figures[], int index, double& scaledArea, double k);
}

#endif
