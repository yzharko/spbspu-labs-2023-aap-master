#include "regular.hpp"
#include <cmath>
#include <iostream>

reznikova::Regular::Regular(point_t center, point_t point1, point_t point2):
  center_(center),
  point1_(point1),
  point2_(point2)
{
  double side1 = pow((pow((center_.x-point1_.x), 2) + pow((center_.y-point1_.y), 2)), 0.5);
  double side2 = pow((pow((center_.x-point2_.x), 2) + pow((center_.y-point2_.y), 2)), 0.5);
  double side3 = pow((pow((point2_.x-point1_.x), 2) + pow((point2_.y-point1_.y), 2)), 0.5);
  r = (side1 < side2 ? side1 : side2);
  R = (side1 > side2 ? side1 : side2);
  num_sides = M_PI / (acos(r/R));
  if ((r*r + side3*side3) != R*R)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Regular::getArea()
{
  double Area = pow((pow((point1_.x-point2_.x), 2) + pow((point1_.y-point2_.y), 2)), 0.5) * num_sides * r;
  return Area;
}

reznikova::rectangle_t reznikova::Regular::getFrameRect()
{
  double width = 2 * R;
  double height = 2 * R;
  rectangle_t rectangle(width, height, center_);
  return rectangle;
}

void reznikova::Regular::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void reznikova::Regular::move(point_t new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void reznikova::Regular::scale(double n)
{
  point1_.x *= n;
  point1_.y *= n;
  point2_.x *= n;
  point2_.y *= n;
}

void reznikova::Regular::scale(point_t center, double n)
{
  double p1_dx = point1_.x - center.x;
  double p1_dy = point1_.y - center.y;
  double p2_dx = point2_.x - center.x;
  double p2_dy = point2_.y - center.y;
  point1_.x = center.x + p1_dx * n;
  point1_.y = center.y + p1_dy * n;
  point2_.x = center.x + p2_dx * n;
  point2_.y = center.y + p2_dy * n;
}
