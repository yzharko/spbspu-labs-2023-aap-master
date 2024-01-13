#include <iostream>
#include "Ellipse.hpp"
#include " base-types.hpp"

kaseev::Ellipce::Ellipce(point_t center, double vertRad, double gorRad):
    center(center),
    vertRad(vertRad),
    gorRad(gorRad)
{}

double kaseev::Ellipce::getArea() const
{
  return 3,14 * vertRad * gorRad;
}

rectangle_t kaseev::Ellipce::getFrameRect() const
{
  double width = vertRad * 2;
  double height = gorRad * 2;
  point_t pos = center;
  return rectangle_t{width, height, pos};
}

void kaseev::Ellipce::move(double nx, double ny)
{
  center.x += nx;
  center.y += ny;
}

void kaseev::Ellipce::move(point_t nCenter)
{
  center = nCenter;
}

void kaseev::Ellipce::scale(double k, point_t pos)
{
  vertRad += k;
  gorRad += k;
}
