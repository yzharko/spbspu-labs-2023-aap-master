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

double Complexquad::getArea()
{
  point_t vec1 = {pointB.x - pointA.x, pointB.y - pointA.y};
  point_t vec2 = {pointD.x - pointC.x, pointD.y - pointC.y};
  double cos = fabs(vec1.x * vec2.x + vec1.y * vec2.y) / (sqrt(pow(vec1.x,2) + pow(vec1.y,2)) * sqrt(pow(vec2.x,2) + pow(vec2.y,2)));
  return s * s * sin(acos(cos));
}

rectangle_t Complexquad::getFrameRect()
{
  point_t vec1 = {pointB.x - pointA.x, pointB.y - pointA.y};
  point_t vec2 = {pointD.x - pointC.x, pointD.y - pointC.y};
  point_t up1 = {cPoint.x + s * vec1.x / sqrt(pow(vec1.x,2) + pow(vec1.y,2)),cPoint.y + s * vec1.y / sqrt(pow(vec1.x,2) + pow(vec1.y,2))};
  point_t down1 = {cPoint.x - s * vec1.x / sqrt(pow(vec1.x,2) + pow(vec1.y,2)), cPoint.y - s * vec1.y / sqrt(pow(vec1.x,2) + pow(vec1.y,2))};
  point_t up2 = {cPoint.x + s * vec2.x / sqrt(pow(vec2.x,2) + pow(vec2.y,2)), cPoint.y - s * vec2.y / sqrt(pow(vec2.x,2) + pow(vec2.y,2))};
  point_t down2 = {cPoint.x - s * vec2.x / sqrt(pow(vec2.x,2) + pow(vec2.y,2)),cPoint.y + s * vec2.y / sqrt(pow(vec2.x,2) + pow(vec2.y,2))};
  point_t pointOfRec1 = {std::min({up1.x, down1.x, up2.x, down2.x}), std::min({up1.y, down1.y, up2.y, down2.y})};
  point_t pointOfRec2 = {std::max({up1.x, down1.x, up2.x, down2.x}), std::max({up1.y, down1.y, up2.y, down2.y})};
  return {fabs(pointOfRec1.x - pointOfRec2.x),fabs(pointOfRec1.y - pointOfRec2.y), cPoint};
}

void Complexquad::move(point_t newPoint)
{
  pointA = {pointA.x + (newPoint.x - cPoint.x), pointA.y + (newPoint.y - cPoint.y)};
  pointB = {pointB.x + (newPoint.x - cPoint.x), pointB.y + (newPoint.y - cPoint.y)};
  pointC = {pointC.x + (newPoint.x - cPoint.x), pointC.y + (newPoint.y - cPoint.y)};
  pointD = {pointD.x + (newPoint.x - cPoint.x), pointD.y + (newPoint.y - cPoint.y)};
  cPoint = newPoint;
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
  s *= k;
}
