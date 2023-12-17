#ifndef RING_HPP
#define RING_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

class Ring : public Shape
{
public:
  Ring(double x0, double y0, double rad1, double rad2);
  double getArea();
  rectangle_t getFrameRect();
  void move(double dx, double dy);
  void move(point_t new_center);
  void scale(double n);
private:
  double x;
  double y;
  double r1;
  double r2;
  double pi = 3.1415;
};

#endif
