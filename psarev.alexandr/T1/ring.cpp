#include "ring.hpp"
#include <cmath>

using namespace psarev;

Ring::Ring(point_t point, double firRad, double secRad) :
  center(point), exterRad(firRad), interRad(secRad)
{}

rectangle_t Ring::getFrameRect() const
{
  return { exterRad * 2, exterRad * 2, center };
}

double Ring::getArea() const
{
  return ((3.14 * pow(exterRad, 2)) - (3.14 * pow(interRad, 2)));
}

void Ring::move(point_t newCenter)
{
  center = newCenter;
}

void Ring::move(double xCh, double yCh)
{
  center = { center.x + xCh, center.y + yCh };
}

void Ring::scale(double coef)
{
  exterRad *= coef;
  interRad *= coef;
}
