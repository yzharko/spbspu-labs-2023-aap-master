#include "triangle.hpp"

using namespace psarev;

Triangle::Triangle(point_t firPoint, point_t secPoint, point_t thirPoint) :
  firCorner(firPoint), secCorner(secPoint), thirCorner(thirPoint)
{}

double Triangle::getArea() const
{
  return (0.5 * abs((secCorner.x - firCorner.x) * (thirCorner.y - firCorner.y) - (thirCorner.x - firCorner.x) * (secCorner.y - firCorner.y)));
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = 0;
  maxX = fmax(firCorner.x, secCorner.x);
  maxX = fmax(maxX, thirCorner.x);
  double maxY = 0;
  maxY = fmax(firCorner.y, secCorner.y);
  maxY = fmax(maxY, thirCorner.y);

  double minX = 0;
  minX = fmin(firCorner.x, secCorner.x);
  minX = fmin(minX, thirCorner.x);
  double minY = 0;
  minY = fmin(firCorner.y, secCorner.y);
  minY = fmin(minY, thirCorner.y);
  double width = abs(maxX - minX);
  double height = abs(maxY - minY);

  return { width, height, { (maxX - minX) * 0.5, (maxY - minY) * 0.5 } };
}

void Triangle::move(point_t newCenter)
{
  double xCh = newCenter.x - ((firCorner.x + secCorner.x + thirCorner.x) / 3);
  double yCh = newCenter.y - ((firCorner.y + secCorner.y + thirCorner.y) / 3);
  move(xCh, yCh);
}

void Triangle::move(double xCh, double yCh)
{
  firCorner = { firCorner.x + xCh, firCorner.y + yCh };
  secCorner = { secCorner.x + xCh, secCorner.y + yCh };
  thirCorner = { thirCorner.x + xCh, thirCorner.y + yCh };
}

void Triangle::scale(double coef)
{
  firCorner = { firCorner.x * coef, firCorner.y * coef };
  secCorner = { secCorner.x * coef, secCorner.y * coef };
  thirCorner = { thirCorner.x * coef, thirCorner.y * coef };
}
