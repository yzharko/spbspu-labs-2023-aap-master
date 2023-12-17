#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(point_t rp, point_t lp);
  double getArea();
  rectangle_t getFrameRect();
  void move(double x, double y);
  void move(point_t center);
  void scale(double k);
private:
  point_t right_point;
  point_t left_point;
};
#endif