#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(double x, double y) = 0;
  virtual void move(point_t center) = 0;
  virtual void scale(double k) = 0;
};
#endif
