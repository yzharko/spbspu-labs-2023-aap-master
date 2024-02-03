#include "ellipse.hpp"

using namespace nikiforov;

Ellipse::Ellipse(point_t firstPoint, double firstRad, double secondRad) :
  center(firstPoint),
  firstRad(firstRad),
  secondRad(secondRad)
{
  rPoint = { center.x + secondRad, center.y + firstRad };
  lPoint = { center.x - secondRad, center.y - firstRad };
  height_rect = firstRad * 2;
  width_rect = secondRad * 2;
}

double Ellipse::getArea() const
{
  return 3.1415926535 * firstRad * secondRad;
}

rectangle_t Ellipse::getFrameRect() const
{
  return rectangle_t{ width_rect, height_rect, center };
}

void Ellipse::move(double x_m, double y_m)
{
  lPoint = { lPoint.x + x_m, lPoint.y + y_m };
  rPoint = { rPoint.x + x_m, rPoint.y + y_m };
  center = { center.x + x_m, center.y + y_m };
}

void Ellipse::move(point_t newCenter)
{
  movePoint = { (newCenter.x - center.x), (newCenter.y - center.y) };
  lPoint = { lPoint.x + movePoint.x, lPoint.y + movePoint.y };
  rPoint = { rPoint.x + movePoint.x, rPoint.y + movePoint.y };
  center = newCenter;
}

void Ellipse::scale(double ratio)
{
  firstRad *= ratio;
  secondRad *= ratio;
  width_rect *= ratio;
  height_rect *= ratio;
  movePoint = { (width_rect / 2), (height_rect / 2) };
  lPoint = { center.x - movePoint.x, center.y - movePoint.y };
  rPoint = { center.x + movePoint.x, center.y + movePoint.y };
}
