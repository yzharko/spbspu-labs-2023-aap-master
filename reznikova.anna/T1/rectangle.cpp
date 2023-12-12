#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double lx, double ly, double rx, double ry):
  lp_x(lx),
  lp_y(ly),
  rp_x(rx),
  rp_y(ry)
{}

void Rectangle::getShape()
{
  std::cout << "left bottom point: (" << lp_x << ", " << lp_y << ")\n";
  std::cout << "right upper point: (" << rp_x << ", " << rp_y << ")\n";
}

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
