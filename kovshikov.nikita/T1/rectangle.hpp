#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t p);
  virtual void move(double xPlus, double yPlus);
  virtual void scale(double multiplier);
private:
  rectangle_t rectangle;
}

#endif
