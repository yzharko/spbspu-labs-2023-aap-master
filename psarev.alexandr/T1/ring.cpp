#include "ring.hpp"
#include <cmath>

psarev::Ring::Ring(point_t point, double firRad, double secRad) :
  center(point), exterRad(firRad), interRad(secRad)
{}

rectangle_t psarev::Ring::getFrameRect()
{
  return { exterRad * 2, exterRad * 2, center };
}

double psarev::Ring::getArea()
{
  return ((3.14 * pow(exterRad, 2)) - (3.14 * pow(interRad, 2)));
}

void psarev::Ring::move(point_t newCenter)
{
  center = newCenter;
}

void psarev::Ring::move(double xCh, double yCh)
{
  center = { center.x + xCh, center.y + yCh };
}

void psarev::Ring::scale(double coef)
{
  exterRad *= coef;
  interRad *= coef;
}
