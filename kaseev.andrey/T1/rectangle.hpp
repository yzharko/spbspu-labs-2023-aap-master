#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include " base-types.hpp"

class Rectangle: public shape{
public:
  Rectangle(point_t lPoint, point_t rPoint);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(double x, double y);
  virtual void move(point_t center);
  virtual void scale(double k);
private:
  point_t lPoint;
  point_t rPoint;
};

#endif
