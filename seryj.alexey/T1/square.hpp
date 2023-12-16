#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
class Square : public Shape
{
public:
  Square() {};
  Square(point_t pos, double side);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t);
  virtual void move(double x, double y);
  virtual void scale(double k);
private:
  point_t pos_ = { 0,0 };
  double side_ = 0;
};
#endif
