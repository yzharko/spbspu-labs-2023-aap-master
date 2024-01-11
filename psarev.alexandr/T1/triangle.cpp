#include "triangle.hpp"

using namespace psarev;

Triangle::Triangle(point_t firPoint, point_t secPoint, point_t thirPoint) :
  firCorner(firPoint), secCorner(secPoint), thirCorner(thirPoint)
{
  center = { ((firCorner.x + secCorner.x + thirCorner.x) / 3), ((firCorner.y + secCorner.y + thirCorner.y) / 3) };
}

rectangle_t Triangle::getFrameRect()
{
  double maxX = 0;
  maxX = fmax(firCorner.x, secCorner.x);
  maxX = fmax(maxX, thirCorner.x);
  double maxY = 0;
  maxY = fmax(firCorner.y, secCorner.y);
  maxY = fmax(maxY, thirCorner.y);

  double minX = 0;
  minX = fmax(firCorner.x, secCorner.x);
  minX = fmax(minX, thirCorner.x);
  double minY = 0;
  minY = fmax(firCorner.y, secCorner.y);
  minY = fmax(minY, thirCorner.y);
  double width = abs(maxX - minX);
  double height = abs(maxY - minY);

  return { width, height, { (maxX - minX) * 0.5, (maxY - minY) * 0.5 } };
}

double Triangle::getArea()
{
  return (0.5 * abs((secCorner.x - firCorner.x) * (thirCorner.y - firCorner.y) - (thirCorner.x - firCorner.x) * (secCorner.y - firCorner.y)));
}

void Triangle::move(point_t newCenter)
{
  double xCh = newCenter.x - ((firCorner.x + secCorner.x + thirCorner.x) / 3);
  double yCh = newCenter.y - ((firCorner.y + secCorner.y + thirCorner.y) / 3);
  firCorner = { firCorner.x + xCh, firCorner.y + yCh };
  secCorner = { secCorner.x + xCh, secCorner.y + yCh };
  thirCorner = { thirCorner.x + xCh, thirCorner.y + yCh };
  center = newCenter;
}

void Triangle::move(double xCh, double yCh)
{
  firCorner = { firCorner.x + xCh, firCorner.y + yCh };
  secCorner = { secCorner.x + xCh, secCorner.y + yCh };
  thirCorner = { thirCorner.x + xCh, thirCorner.y + yCh };
  center = { ((firCorner.x + secCorner.x + thirCorner.x) / 3), ((firCorner.y + secCorner.y + thirCorner.y) / 3) };
}

void Triangle::scale(double coef)
{
  firCorner = { firCorner.x * coef, firCorner.y * coef };
  secCorner = { secCorner.x * coef, secCorner.y * coef };
  thirCorner = { thirCorner.x * coef, thirCorner.y * coef };
  center = { ((firCorner.x + secCorner.x + thirCorner.x) / 3), ((firCorner.y + secCorner.y + thirCorner.y) / 3) };
}
