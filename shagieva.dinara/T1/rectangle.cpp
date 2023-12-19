#include "rectangle.hpp"
#include <cmath>

shagieva::Rectangle::Rectangle(point_t firstPoint, point_t secondPoint) :
  cornerA(firstPoint),
  cornerC(secondPoint)
{
  center = { (cornerA.x + cornerC.x) / 2, (cornerA.y + cornerC.y) /2 };
}

rectangle_t shagieva::Rectangle::getFrameRect()
{
  return { fabs(cornerA.x - cornerC.x), fabs(cornerA.y - cornerC.y), center };
}

double shagieva::Rectangle::getArea()
{
  rectangle_t frameRect = getFrameRect();
  return (frameRect.width * frameRect.height);
}

void shagieva::Rectangle::move(point_t newCenter)
{
  double dX = newCenter.x - center.x;
  double dY = newCenter.y - center.y;
  cornerA.x += dX;
  cornerA.y += dY;
  cornerC.x += dX;
  cornerC.y += dY;
  center = newCenter;
}

void shagieva::Rectangle::move(double dX, double dY)
{
  cornerA.x += dX;
  cornerA.y += dY;
  cornerC.x += dX;
  cornerC.y += dY;
  center = { center.x += dX, center.y += dY };
}
