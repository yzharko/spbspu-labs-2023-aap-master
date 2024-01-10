#include "regular.hpp"
#include <cmath>
#include <iostream>

Regular::Regular(point_t center, point_t point1, point_t point2):
  center_(center),
  point1_(point1),
  point2_(point2)
{
  double r1 = pow((pow((center_.x-point1_.x), 2) + pow((center_.y-point1_.y), 2)), 0.5);
  double r2 = pow((pow((center_.x-point2_.x), 2) + pow((center_.y-point2_.y), 2)), 0.5);
  double r = (r1 < r2 ? r1 : r2);
  double R = (r1 > r2 ? r1 : r2);
  double num_sides = M_PI / (acos(r/R));
}

double Regular::getArea()
{
  double Area = pow((pow((point1_.x-point2_.x), 2) + pow((point1_.y-point2_.y), 2)), 0.5) * num_sides * r;
  return Area;
}

rectangle_t Regular::getFrameRect()
{
  double width = 2 * R;
  double height = 2 * R;
  rectangle_t rectangle(width, height, center_);
  return rectangle;
}

void Regular::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Regular::move(point_t new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void Regular::scale(double n)
{
  point1_.x *= n;
  point1_.y *= n;
  point2_.x *= n;
  point2_.y *= n;
}
