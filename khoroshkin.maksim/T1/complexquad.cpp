#include "complexquad.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace khoroshkin;
Complexquad::Complexquad(point_t first, point_t second, point_t third,point_t fourth):
 pointA(first), pointB(second), pointC(third), pointD(fourth)
{
  double angleCoeffAB = (pointB.y - pointA.y) / (pointB.x - pointA.x);
  double yIntercectionAB = pointA.y - angleCoeffAB * pointA.x;
  double angleCoeffCD = (pointD.y - pointC.y) / (pointD.x - pointC.x);
  double yIntercectionCD = pointC.y - angleCoeffCD * pointC.x;
  centerPoint.x = (yIntercectionCD - yIntercectionAB) / (angleCoeffAB - angleCoeffCD);
  centerPoint.y = angleCoeffAB * centerPoint.x + yIntercectionAB;
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

void Complexquad::move(const point_t & newPoint)
{
  double dx = newPoint.x - centerPoint.x;
  double dy = newPoint.y - centerPoint.y;
  move(dx,dy);
}

void Complexquad::move(double dx, double dy)
{
  pointA = {pointA.x + dx, pointA.y + dy};
  pointB = {pointB.x + dx, pointB.y + dy};
  pointC = {pointC.x + dx, pointC.y + dy};
  pointD = {pointD.x + dx, pointD.y + dy};
  centerPoint = {centerPoint.x + dx, centerPoint.y + dy};
}

void Complexquad::doScale(double k)
{
  pointA.x = centerPoint.x + k * (pointA.x - centerPoint.x);
  pointA.y = centerPoint.y + k * (pointA.y - centerPoint.y);
  pointB.x = centerPoint.x + k * (pointB.x - centerPoint.x);
  pointB.y = centerPoint.y + k * (pointB.y - centerPoint.y);
  pointC.x = centerPoint.x + k * (pointC.x - centerPoint.x);
  pointC.y = centerPoint.y + k * (pointC.y - centerPoint.y);
  pointD.x = centerPoint.x + k * (pointD.x - centerPoint.x);
  pointD.y = centerPoint.y + k * (pointD.y - centerPoint.y);
}
