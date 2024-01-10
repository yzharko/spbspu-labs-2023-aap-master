#ifndef SHAPE_HPP
#define SHAPE_HPP

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
