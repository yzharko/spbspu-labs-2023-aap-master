#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

class Shape {
public:
  long long getArea();

  RectangleT getFrameRect();

  void move(PointT);

  void move(double x, double y);

  void scale(double);
};

#endif
