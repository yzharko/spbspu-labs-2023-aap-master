#include "rectangle.hpp"
#include <iostream>

taskaev::Rectangle::Rectangle(point_t rx, point_t ry, point_t lx ,point_t ly):
  rp_x(rx),
  rp_y(ry),
  lp_x(lx),
  lp_y(ly)
{}
double taskaev::Rectangle::getArea()
{
  return std::abs(rp_x - lp_x) * std::abs(rp_x - rp_y);
}

rectangle_t taskaev::Rectangle::getFrameRect()
{
  double height = std::abs(rp_y - lp_y);
  double width = std::abs(rp_x - lp_x);
  point_t pos(((rp_x + lp_x)/2),((rp_y - lp_y)/2));
  return rectangle_t(width, height, pos);
}

void taskaev::Rectangle::move(double dx , double dy)
{
  rp_x = rp_x + dx;
  rp_y = rp_y + dy;
  lp_x = lp_x + dx;
  lp_y = lp_y + dy;
}

void taskaev::Rectangle::move(point_t new_center)
{
  double new_x = new_center.x;
  double new_y = new_center.y;
  double old_x = (rp_x + lp_x)/2;
  double old_y = (rp_y + lp_y)/2;
  double dx = (new_x - old_x);
  double dy = (new_y - old_y);
  move(dx, dy);
}

void taskaev::Rectangle::move(double c)
{
  double center_x = (rp_x + lp_x)/2;
  double center_y = (rp_y + lp_y)/2;
  double height = std::abs(rp_y - lp_y);
  double width = std::abs(rp_x - lp_x);
  double new_widht = (width * c)/2;
  double new_height = (height * c)/2;
  rp_x = center_x - new_width;
  rp_y = center_y - new_height;
  lp_x = center_x + new_width;
  lp_y = center_y + new_height;
}
