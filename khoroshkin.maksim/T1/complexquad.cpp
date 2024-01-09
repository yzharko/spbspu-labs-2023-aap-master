#include "complexquad.hpp"
#include <cmath>
#include <algorithm>

khoroshkin::Complexquad::Complexquad(point_t first, point_t second, point_t third,point_t fourth):
 pointA(first), pointB(second), pointC(third), pointD(fourth)
{
  double k1 = (pointB.y - pointA.y) / (pointB.x - pointA.x);
  double b1 = pointA.y - k1 * pointA.x;
  double k2 = (pointD.y - pointC.y) / (pointD.x - pointC.x);
  double b2 = pointC.y - k2 * pointC.x;
  cPoint.x = (b2 - b1) / (k1 - k2);
  cPoint.y = k1 * cPoint.x + b1;
  double side = sqrt(pow(pointA.x - pointD.x, 2) + pow(pointA.y - pointD.y, 2));
}

double khoroshkin::Complexquad::getArea()
{
  point_t vector1 = {pointB.x - pointA.x, pointB.y - pointA.y};
  point_t vector2 = {pointD.x - pointC.x, pointD.y - pointC.y};
  double angleCos = abs(vector1.x * vector2.x + vector1.y * vector2.y) / \
  (sqrt(pow(vector1.x,2) + pow(vector1.y,2)) * sqrt(pow(vector2.x,2) \
  + pow(vector2.y,2)));
  return side * side * sin(acos(angleCos));
}

rectangle_t khoroshkin::Complexquad::getFrameRect()
{
  
  point_t vec1 = {pointB.x - pointA.x, pointB.y - pointA.y};
  point_t vec2 = {pointD.x - pointC.x, pointD.y - pointC.y};

  double side = sqrt(pow(pointA.x - pointD.x, 2) + pow(pointA.y - pointD.y, 2));

  point_t upPoint1 = {cPoint.x + side * vec1.x / sqrt(pow(vec1.x,2) + pow(vec1.y,2)),cPoint.y + side * vec1.y / sqrt(pow(vec1.x,2) + pow(vec1.y,2))};

  point_t downPoint1 = {cPoint.x - side * vec1.x / sqrt(pow(vec1.x,2) + pow(vec1.y,2)), cPoint.y - side * vec1.y / sqrt(pow(vec1.x,2) + pow(vec1.y,2))};

  point_t upPoint2 = {cPoint.x + side * vec2.x / sqrt(pow(vec2.x,2) + pow(vec2.y,2)), cPoint.y - side * vec2.y / sqrt(pow(vec2.x,2) + pow(vec2.y,2))};

  point_t downPoint2 = {cPoint.x - side * vec2.x / sqrt(pow(vec2.x,2) + pow(vec2.y,2)),cPoint.y + side * vec2.y / sqrt(pow(vec2.x,2) + pow(vec2.y,2))};

  point_t pointOfRec1 = {std::min({upPoint1.x, downPoint1.x, upPoint2.x, downPoint2.x}), std::min({upPoint1.y, downPoint1.y, upPoint2.y, downPoint2.y})};

  point_t pointOfRec2 = {std::max({upPoint1.x, downPoint1.x, upPoint2.x, downPoint2.x}), std::max({upPoint1.y, downPoint1.y, upPoint2.y, downPoint2.y})};

  return {abs(pointOfRec1.x - pointOfRec2.x),abs(pointOfRec1.y - pointOfRec2.y), cPoint};
}

void khoroshkin::Complexquad::move(point_t newPoint)
{
  pointA = {pointA.x + (newPoint.x - cPoint.x),\
  pointA.y + (newPoint.y - cPoint.y)};
  pointB = {pointB.x + (newPoint.x - cPoint.x),\
  pointB.y + (newPoint.y - cPoint.y)};
  pointC = {pointC.x + (newPoint.x - cPoint.x),\
  pointC.y + (newPoint.y - cPoint.y)};
  pointD = {pointD.x + (newPoint.x - cPoint.x),\
  pointD.y + (newPoint.y - cPoint.y)};
  cPoint = newPoint;
}

void khoroshkin::Complexquad::move(double dx, double dy)
{
  pointA = {pointA.x + dx, pointA.y + dy};
  pointB = {pointB.x + dx, pointB.y + dy};
  pointC = {pointC.x + dx, pointC.y + dy};
  pointD = {pointD.x + dx, pointD.y + dy};
  cPoint = {cPoint.x + dx, cPoint.y + dy};
}

void khoroshkin::Complexquad::scale(double k)
{
  side *= k;
}
