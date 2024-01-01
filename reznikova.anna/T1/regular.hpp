#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <stdio.h>
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

class Regular : public Shape
{
public:
  Regular(double x0_, double y0_, double x1_, double y1_, double x2_, double y2_);
  double getArea();
  rectangle_t getFrameRect();
  void move(double dx, double dy);
  void move(point_t new_center);
  void scale(double n);
private:
  double x0;
  double y0;
  double x1;
  double y1;
  double x2;
  double y2;
  double r1 = pow((pow((x0-x1), 2) + pow((y0-y1), 2)), 0.5);
  double r2 = pow((pow((x0-x2), 2) + pow((y0-y2), 2)), 0.5);
  double r = (r1 < r2 ? r1 : r2);
  double R = (r1 > r2 ? r1 : r2);
};

#endif
