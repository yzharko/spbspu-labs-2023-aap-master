#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

class Shape {
public:
  virtual ~Shape() = default;

  virtual long long getArea() = 0;

  virtual RectangleT getFrameRect() = 0;

  virtual void move(PointT) = 0;

  virtual void move(float x, float y) = 0;

  virtual PointT getCPoint() const = 0;

  virtual void scale(float) = 0;
};

#endif
