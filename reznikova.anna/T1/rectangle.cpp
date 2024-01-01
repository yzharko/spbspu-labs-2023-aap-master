#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double lx, double ly, double rx, double ry):
  lp_x(lx),
  lp_y(ly),
  rp_x(rx),
  rp_y(ry)
{}

double Rectangle::getArea()
{
  double Area = 0;
  double width = std::abs(rp_x - lp_x);
  double height = std::abs(rp_y - lp_y);
  Area = width * height;
  return Area;
}

rectangle_t Rectangle::getFrameRect()
{
  double width = std::abs(rp_x - lp_x);
  double height = std::abs(rp_y - lp_y);
  point_t pos(((rp_x + lp_x)/2),((rp_y + lp_y)/2));
  rectangle_t rectangle(width, height, pos);
  return rectangle;
}

void Rectangle::move(double dx, double dy)
{
  lp_x += dx;
  rp_x += dx;
  lp_y += dy;
  rp_y += dy;
}

void Rectangle::move(point_t new_center)
{
  double new_x0 = new_center.x;
  double new_y0 = new_center.y;
  double old_x0 = (rp_x + lp_x)/2;
  double old_y0 = (rp_y + lp_y)/2;
  double dx = (new_x0 - old_x0);
  double dy = (new_y0 - old_y0);
  move(dx, dy);
}

void Rectangle::scale(double n)
{
  double width = std::abs(rp_x - lp_x);
  double height = std::abs(rp_y - lp_y);
  lp_x -= width/2*(n-1);
  lp_y -= height/2*(n-1);
  rp_x += width/2*(n-1);
  rp_y += height/2*(n-1);
}

