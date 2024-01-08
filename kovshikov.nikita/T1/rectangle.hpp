#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <cmath>

class Rectangle: public Shape
{
public:
  Rectangle(point_t lowerLeft, point_t upperRight);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t newPos);
  virtual void move(double xPlus, double yPlus);
  virtual void scale(double multiplier);
private:
  point_t lowerLeft_;
  point_t upperRight_;
};

#endif
