#ifndef SCALEFUNC_HPP
#define SCALEFUNC_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva {
  void getCoordinates(rectangle_t frameRect);
  void getCoordinatesBefore(Shape* figures[], int index);
  void getCoordinatesAfter(Shape* figures[], int index, point_t center, double k);
  void getRectangle(Shape* figures[], Shape* scaledFigures[], point_t rightPoint, point_t leftPoint, int& index);
  void getCircle(Shape* figures[], Shape* scaledFigures[], point_t center, double radius, int& index);
  void getParallelogram(Shape* figures[], Shape* scaledFigures[], point_t aPoint, point_t bPoint, point_t cPoint, int& index);
  void deleteArray(Shape* figures[], int index);
  void getFirstArea(Shape* figures[], int index, double& firstArea);
  void getScaledArea(Shape* figures[], int index, double& scaledArea, double k);
  void scaleCheck(Shape* figures[], Shape* scaledFigures[], int index, double k);
}

#endif
