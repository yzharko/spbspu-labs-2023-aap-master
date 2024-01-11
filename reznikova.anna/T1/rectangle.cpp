#include "rectangle.hpp"
#include <iostream>
#include <exception>

reznikova::Rectangle::Rectangle(point_t leftpoint, point_t rightpoint):
  leftpoint_(leftpoint),
  rightpoint_(rightpoint)
{
  if ((leftpoint.x > rightpoint.x) || (leftpoint.y > rightpoint.y))
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Rectangle::getArea()
{
  double Area = 0;
  double width = std::abs(rightpoint_.x - leftpoint_.x);
  double height = std::abs(rightpoint_.y - leftpoint_.y);
  Area = width * height;
  return Area;
}

reznikova::rectangle_t reznikova::Rectangle::getFrameRect()
{
  double width = std::abs(rightpoint_.x - leftpoint_.x);
  double height = std::abs(rightpoint_.y - leftpoint_.y);
  point_t pos(((rightpoint_.x + leftpoint_.x)/2),((rightpoint_.y + leftpoint_.y)/2));
  rectangle_t rectangle(width, height, pos);
  return rectangle;
}

void reznikova::Rectangle::move(double dx, double dy)
{
  leftpoint_.x += dx;
  rightpoint_.x += dx;
  leftpoint_.y += dy;
  rightpoint_.y += dy;
}

void reznikova::Rectangle::move(point_t new_center)
{
  double new_x0 = new_center.x;
  double new_y0 = new_center.y;
  double old_x0 = (rightpoint_.x + leftpoint_.x)/2;
  double old_y0 = (rightpoint_.y + leftpoint_.y)/2;
  double dx = (new_x0 - old_x0);
  double dy = (new_y0 - old_y0);
  move(dx, dy);
}

void reznikova::Rectangle::scale(double n)
{
  double width = std::abs(rightpoint_.x - leftpoint_.x);
  double height = std::abs(rightpoint_.y - leftpoint_.y);
  leftpoint_.x -= width/2*(n-1);
  leftpoint_.y -= height/2*(n-1);
  rightpoint_.x += width/2*(n-1);
  rightpoint_.y += height/2*(n-1);
}