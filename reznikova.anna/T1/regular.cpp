#include "regular.hpp"
#include <cmath>
#include <iostream>

reznikova::Regular::Regular(point_t center, point_t pointA, point_t pointB):
  center_(center),
  pointA_(pointA),
  pointB_(pointB)
{
  double side1 = pow((pow((center_.x-pointA_.x), 2) + pow((center_.y-pointA_.y), 2)), 0.5);
  double side2 = pow((pow((center_.x-pointB_.x), 2) + pow((center_.y-pointB_.y), 2)), 0.5);
  inscribed_rad = (side1 < side2 ? side1 : side2);
  circum_rad = (side1 > side2 ? side1 : side2);
  num_sides = M_PI / (acos(inscribed_rad/circum_rad));
  double const eps = 0.00000000001;
  if (fabs(num_sides - floor(num_sides + 0.5)) > eps)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Regular::getArea() const
{
  double Area = pow((pow((pointA_.x-pointB_.x), 2) + pow((pointA_.y-pointB_.y), 2)), 0.5) * num_sides * inscribed_rad;
  return Area;
}

reznikova::rectangle_t reznikova::Regular::getFrameRect() const
{
  double height = 0;
  if (abs(pointA_.y - center_.y) > abs(pointB_.y - center_.y))
  {
    height = 2 * abs(pointA_.y - center_.y);
  }
  else
  {
    height = 2 * abs(pointB_.y - center_.y);
  }
  double width = 0;
  if (abs(pointA_.x - center_.x) > abs(pointB_.x - center_.x))
  {
    width = 2 * abs(pointA_.x - center_.x);
  }
  else
  {
    width = 2 * abs(pointB_.x - center_.x);
  }
  double res_len = (width > height ? width : height);
  rectangle_t rectangle{res_len, res_len, center_};
  return rectangle;
}

void reznikova::Regular::move(const double& dx, const double& dy)
{
  center_.x += dx;
  center_.y += dy;
}

void reznikova::Regular::move(const point_t& new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void reznikova::Regular::scale(const double n)
{
  pointA_.x = center_.x + (pointA_.x - center_.x) * n;
  pointA_.y = center_.x + (pointA_.y - center_.y) * n;
  pointB_.x = center_.x + (pointB_.x - center_.x) * n;
  pointB_.y = center_.x + (pointB_.y - center_.y) * n;
  inscribed_rad *= n;
  circum_rad *= n;
}

