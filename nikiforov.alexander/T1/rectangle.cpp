#include "rectangle.hpp"
#include <cmath>

nikiforov::Rectangle::Rectangle(point_t firstPoint, point_t secondPoint) :
  lPoint(firstPoint),
  rPoint(secondPoint)
{
  width_rect = abs(rPoint.x - lPoint.x);
  height_rect = abs(rPoint.y - lPoint.y);
  center = { ((rPoint.x + lPoint.x) / 2),((rPoint.y + lPoint.y) / 2) };
}

double nikiforov::Rectangle::getArea() const
{
  return width_rect * height_rect;
}

rectangle_t nikiforov::Rectangle::getFrameRect() const
{
  return rectangle_t{ width_rect, height_rect, center };
}

void nikiforov::Rectangle::move(double x_m, double y_m) 
{
  lPoint = { lPoint.x + x_m, lPoint.y + y_m };
  rPoint = { rPoint.x + x_m, rPoint.y + y_m };
  center = { center.x + x_m, center.y + y_m };
}

void nikiforov::Rectangle::move(point_t newCenter) 
{
  movePoint = { (newCenter.x - center.x), (newCenter.y - center.y) };
  lPoint = { lPoint.x + movePoint.x, lPoint.y + movePoint.y };
  rPoint = { rPoint.x + movePoint.x, rPoint.y + movePoint.y };
  center = newCenter;
}

void nikiforov::Rectangle::scale(double ratio)
{
  width_rect *= ratio;
  height_rect *= ratio;
  movePoint = { (width_rect / 2), (height_rect / 2) };
  lPoint = { center.x - movePoint.x, center.y - movePoint.y };
  rPoint = { center.x + movePoint.x, center.y + movePoint.y };
}
