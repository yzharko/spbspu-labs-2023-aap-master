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
  double vec1_x, vec1_y;
  vec1_x = vec1_y = 0;
  if (side1 < side2)
  {
    r = side1;
    R = side2;
    vec1_x = point1_.x - center_.x;
    vec1_y = point1_.y - center_.y;
  }
  else
  {
    r = side2;
    R = side1;
    vec1_x = point2_.x - center_.x;
    vec1_y = point2_.y - center_.y;
  }
  num_sides = M_PI / (acos(r/R));
  double vec2_x = point1_.x - point2_.x;
  double vec2_y = point1_.y - point2_.y;
  if ((vec1_x * vec2_x + vec1_y * vec2_y) != 0)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Regular::getArea() const
{
  double Area = pow((pow((point1_.x-point2_.x), 2) + pow((point1_.y-point2_.y), 2)), 0.5) * num_sides * r;
  return Area;
}

reznikova::rectangle_t reznikova::Regular::getFrameRect() const
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

void reznikova::Regular::newscale(point_t center, double n)
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
