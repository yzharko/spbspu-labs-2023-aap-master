#include "complexquad.hpp"
#include <cmath>
#include <algorithm>

using namespace khoroshkin;
Complexquad::Complexquad(point_t first, point_t second, point_t third,point_t fourth):
 pointA(first), pointB(second), pointC(third), pointD(fourth)
{
  double k1 = (pointB.y - pointA.y) / (pointB.x - pointA.x);
  double b1 = pointA.y - k1 * pointA.x;
  double k2 = (pointD.y - pointC.y) / (pointD.x - pointC.x);
  double b2 = pointC.y - k2 * pointC.x;
  cPoint.x = (b2 - b1) / (k1 - k2);
  cPoint.y = k1 * cPoint.x + b1;
  s = sqrt(pow(pointA.x - pointD.x, 2) + pow(pointA.y - pointD.y, 2));
}

double Complexquad::getArea() const
{
  double ABC = 0.25*fabs((pointA.x*(pointB.y - pointC.y) + pointB.x*(pointC.y - pointA.y) + pointC.x*(pointA.y - pointB.y)));
  double ACD = 0.25*fabs((pointA.x*(pointC.y - pointD.y) + pointC.x*(pointD.y - pointA.y) + pointD.x*(pointA.y - pointC.y)));
  return ABC + ACD;
}

rectangle_t Complexquad::getFrameRect() const
{
  double left = std::min({pointA.x, pointB.x, pointC.x, pointD.x});
  double right = std::max({pointA.x, pointB.x, pointC.x, pointD.x});
  double top = std::max({pointA.y, pointB.y, pointC.y, pointD.y});
  double bottom = std::min({pointA.y, pointB.y, pointC.y, pointD.y});

  point_t pos = {(left + right) / 2, (top + bottom) / 2};
  double width = right - left;
  double height = top - bottom;
  return {width, height, pos};
}

void Complexquad::move(point_t newPoint)
{
  double dx = newPoint.x - cPoint.x;
  double dy = newPoint.y - cPoint.y;
  move(dx,dy);
}

void Complexquad::move(double dx, double dy)
{
  pointA = {pointA.x + dx, pointA.y + dy};
  pointB = {pointB.x + dx, pointB.y + dy};
  pointC = {pointC.x + dx, pointC.y + dy};
  pointD = {pointD.x + dx, pointD.y + dy};
  cPoint = {cPoint.x + dx, cPoint.y + dy};
}

void Complexquad::scale(double k)
{
  pointA.x = cPoint.x + k * (pointA.x - cPoint.x);
  pointA.y = cPoint.y + k * (pointA.y - cPoint.y);
  pointB.x = cPoint.x + k * (pointB.x - cPoint.x);
  pointB.y = cPoint.y + k * (pointB.y - cPoint.y);
  pointC.x = cPoint.x + k * (pointC.x - cPoint.x);
  pointC.y = cPoint.y + k * (pointC.y - cPoint.y);
  pointD.x = cPoint.x + k * (pointD.x - cPoint.x);
  pointD.y = cPoint.y + k * (pointD.y - cPoint.y);
  s *= k;
}
