#include "triangle.hpp"

using namespace psarev;

Triangle::Triangle(point_t firPoint, point_t secPoint, point_t thirPoint) :
  firCorner(firPoint), secCorner(secPoint), thirCorner(thirPoint)
{}

double Triangle::getArea() const
{
  double firSide = sqrt(pow((firCorner.x - secCorner.x), 2) + pow((firCorner.y - secCorner.y), 2));
  double secSide = sqrt(pow((secCorner.x - thirCorner.x), 2) + pow((secCorner.y - thirCorner.y), 2));
  double thirSide = sqrt(pow((thirCorner.x - firCorner.x), 2) + pow((thirCorner.y - firCorner.y), 2));
  double halfP = 0.5 * (firSide + secSide + thirSide);
  return (sqrt(halfP * (halfP - firSide) * (halfP - secSide) * (halfP - thirSide)));
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
  double width = maxX - minX;
  double height = maxY - minY;

  return { width, height, { (maxX + minX) * 0.5, (maxY + minY) * 0.5 } };
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
  double xMid, yMid;
  xMid = (firCorner.x + secCorner.x + thirCorner.x) / 3;
  yMid = (firCorner.y + secCorner.y + thirCorner.y) / 3;
  firCorner.x += (firCorner.x - xMid) * (coef - 1);
  firCorner.y += (firCorner.y - yMid) * (coef - 1);
  secCorner.x += (secCorner.x - xMid) * (coef - 1);
  secCorner.y += (secCorner.y - yMid) * (coef - 1);
  thirCorner.x += (thirCorner.x - xMid) * (coef - 1);
  thirCorner.y += (thirCorner.y - yMid) * (coef - 1);
}
