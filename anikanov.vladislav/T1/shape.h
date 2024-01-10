#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

class Shape {
public:
  virtual ~Shape() = default;

  virtual long long getArea() = 0;

  virtual RectangleT getFrameRect() = 0;

  virtual void move(PointT) = 0;

  virtual void move(double x, double y) = 0;

  virtual PointT getCPoint() const = 0;

  virtual void scale(double) = 0;
};

#endif
