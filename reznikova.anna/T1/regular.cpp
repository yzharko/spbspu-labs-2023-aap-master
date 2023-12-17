#include "regular.hpp"
#include <cmath>
#include <iostream>

Regular::Regular(double x0_, double y0_, double x1_, double y1_, double x2_, double y2_):
  x0(x0_),
  y0(y0_),
  x1(x1_),
  y1(y1_),
  x2(x2_),
  y2(y2_)
{}

double Regular::getArea()
{
  double num_sides = M_PI / (acos(r/R));
  double Area = pow((pow((x1-x2), 2) + pow((y1-y2), 2)), 0.5) * num_sides * r;
  return Area;
}

rectangle_t Regular::getFrameRect()
{
  double width = 2 * r;
  double height = 2 * r;
  point_t pos(x0, y0);
  rectangle_t rectangle(width, height, pos);
  return rectangle;
}

void Regular::move(double dx, double dy)
{
  x0 += dx;
  y0 += dy;
}

void Regular::move(point_t new_center)
{
  x0 = new_center.x;
  y0 = new_center.y;
}

void Regular::scale(double n)
{
  x1 *= n;
  y1 *= n;
  x2 *= n;
  y2 *= n;
}
