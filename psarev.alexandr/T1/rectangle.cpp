#include "rectangle.hpp"
#include <cmath>

psarev::Rectangle::Rectangle(point_t firPoint, point_t secPoint) :
  ldCorner(firPoint), ruCorner(secPoint)
{
  center = { (ldCorner.x + ruCorner.x) / 2, (ldCorner.y + ruCorner.y) / 2 };
}

rectangle_t psarev::Rectangle::getFrameRect()
{
  return { abs(ldCorner.x - ruCorner.x), abs(ldCorner.y - ruCorner.y), center };
}

double psarev::Rectangle::getArea()
{
  rectangle_t frameRect = getFrameRect();
  return (frameRect.width * frameRect.height);
}

void psarev::Rectangle::move(point_t newCenter)
{
  double centerXCh = newCenter.x - center.x;
  double centerYCh = newCenter.y - center.y;
  ldCorner.x += centerXCh;
  ldCorner.y += centerYCh;
  ruCorner.x += centerXCh;
  ruCorner.y += centerYCh;
  center = newCenter;
}

void psarev::Rectangle::move(double xCh, double yCh)
{
  ldCorner.x += xCh;
  ldCorner.y += yCh;
  ruCorner.x += xCh;
  ruCorner.y += yCh;
  center = { center.x + xCh, center.y + yCh };
}

void psarev::Rectangle::scale(double coef)
{
  ldCorner.x = ldCorner.x * coef + (1 - coef) * center.x;
  ldCorner.y = ldCorner.y * coef + (1 - coef) * center.y;
  ruCorner.x = ruCorner.x * coef + (1 - coef) * center.x;
  ruCorner.y = ruCorner.y * coef + (1 - coef) * center.y;
}
