#include "rectangle.hpp"
#include <cmath>

nikiforov::Rectangle::Rectangle(point_t firstPoint, point_t secondPoint) :
  lPoint(firstPoint),
  rPoint(secondPoint)
{
  width_rect = abs(rPoint.x - lPoint.x);
  height_rect = abs(rPoint.y - lPoint.y);
}

double nikiforov::Rectangle::getArea() {
  return width_rect * height_rect;
}

rectangle_t nikiforov::Rectangle::getFrameRect() {
  point_t pos = { ((rPoint.x + lPoint.x) / 2),((rPoint.y + lPoint.y) / 2) };
  return rectangle_t{ width_rect, height_rect, pos };
}

void nikiforov::Rectangle::move(double x_m, double y_m) {
  lPoint.x += x_m;
  lPoint.y += y_m;
  rPoint.x += x_m;
  rPoint.y += y_m;
}

void nikiforov::Rectangle::move(point_t center) {
  rectangle_t NewPos = { width_rect, height_rect, center };
}

void nikiforov::Rectangle::scale(double ratio)
{
  lPoint.x *= ratio;
  lPoint.y *= ratio;
  rPoint.x *= ratio;
  rPoint.y *= ratio;
}
