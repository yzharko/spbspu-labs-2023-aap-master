#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(point_t center, double radius);
  double getArea();
  rectangle_t getFrameRect();
  void move(double x, double y);
  void move(point_t center);
  void scale(double k);
private:
  point_t center_;
  double radius_;
};

#endif