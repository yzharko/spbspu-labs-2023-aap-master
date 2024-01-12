#include "ellipse.hpp"
#include <cmath>

nikiforov::Ellipse::Ellipse(point_t firstPoint, double firstRad, double secondRad) :
  center(firstPoint),
  firstRad(firstRad),
  secondRad(secondRad)
{
  width_rect = firstRad * 2;
  height_rect = secondRad * 2;
}

double nikiforov::Ellipse::getArea() const
{
  return 3.14 * firstRad * secondRad;
}

rectangle_t nikiforov::Ellipse::getFrameRect() const
{
  return rectangle_t{ width_rect, height_rect, center };
}

void nikiforov::Ellipse::move(double x_m, double y_m)
{
  center = { center.x + x_m, center.y + y_m };
}

void nikiforov::Ellipse::move(point_t newCenter)
{
  center = newCenter;
}

void nikiforov::Ellipse::scale(double ratio)
{
  firstRad *= ratio;
  secondRad *= ratio;
  width_rect *= ratio;
  height_rect *= ratio;
}

void nikiforov::Ellipse::point(Ellipse Rect)
{
  std::cout << "center (" << Rect.center.x << ", " << Rect.center.y << ")" << '\n';
  std::cout << "width -- " << width_rect << '\n';
  std::cout << "height -- " << height_rect << '\n' << '\n';
}
