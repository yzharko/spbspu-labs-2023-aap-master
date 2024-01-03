#include "rectangle.hpp"
#include <cmath>

shagieva::Rectangle::Rectangle(const point_t & firstPoint, const point_t & secondPoint) :
  cornerA(firstPoint),
  cornerC(secondPoint)
{
  pos = { (cornerA.x + cornerC.x) / 2, (cornerA.y + cornerC.y) / 2 };
}

double shagieva::Rectangle::getArea() const
{
  double width = cornerC.x - cornerA.x;
  double height = cornerC.y - cornerA.y;
  return width * height;
}

rectangle_t shagieva::Rectangle::getFrameRect() const
{
  double width = cornerC.x - cornerA.x;
  double height = cornerC.y - cornerA.y;
  return { width, height, pos };
}

void shagieva::Rectangle::move(const double dx, const double dy)
{
  cornerA.x += dx;
  cornerA.y += dy;
  cornerC.x += dx;
  cornerC.y += dy;
  pos = { pos.x += dx, pos.y += dy };
}

void shagieva::Rectangle::move(const point_t & newPos)
{
  double dx = newPos.x - pos.x;
  double dy = newPos.y - pos.y;
  move(dx, dy);
}

void shagieva::Rectangle::scale(const double scaleFactor)
{
  cornerA.x = (cornerA.x - pos.x) * scaleFactor + pos.x;
  cornerA.y = (cornerA.y - pos.y) * scaleFactor + pos.y;
  cornerC.x = (cornerC.x - pos.x) * scaleFactor + pos.x;
  cornerC.y = (cornerC.y - pos.y) * scaleFactor + pos.y;
}
