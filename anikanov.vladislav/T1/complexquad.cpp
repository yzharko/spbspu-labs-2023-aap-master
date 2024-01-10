#include "complexquad.hpp"
#include <iostream>
#include <cmath>
#include <limits>

PointT Complexquad::getCPoint() const
{
  return cPoint;
}

long long Complexquad::getArea()
{
  return getTriangleArea(leftBottom, leftTop, cPoint) +
         getTriangleArea(rightTop, rightBottom, cPoint);
}

RectangleT Complexquad::getFrameRect()
{
  double leftMax = std::numeric_limits<double>::max();
  double topMax = std::numeric_limits<double>::min();
  double rightMax = std::numeric_limits<double>::min();
  double bottomMax = std::numeric_limits<double>::max();
  PointT points[] = {leftTop, leftBottom, rightTop, rightBottom};
  for (auto point: points) {
    leftMax = std::min(leftMax, point.x);
  }
  for (auto point: points) {
    topMax = std::max(topMax, point.y);
  }
  for (auto point: points) {
    rightMax = std::max(topMax, point.x);
  }
  for (auto point: points) {
    bottomMax = std::min(topMax, point.y);
  }
  double width = rightMax - leftMax;
  double height = topMax - bottomMax;
  return RectangleT(PointT(leftMax + width / 2, bottomMax + height / 2), width, height);
}

void Complexquad::move(PointT newCPoint)
{
  double dx = getDX(cPoint, newCPoint);
  double dy = getDY(cPoint, newCPoint);

  leftBottom.x += dx;
  leftBottom.y += dy;

  leftTop.x += dx;
  leftTop.y += dy;

  rightTop.x += dx;
  rightTop.y += dy;

  rightBottom.x += dx;
  rightBottom.y += dy;

  cPoint = newCPoint;
}

void Complexquad::move(double x, double y)
{
  PointT newCPoint(x, y);
  move(newCPoint);
}

void Complexquad::scale(double k)
{
  if (k < 0){
    throw std::logic_error("Invalid scale argument");
  }
  leftBottom.x = cPoint.x + k * getDX(leftBottom, cPoint);
  leftBottom.y = cPoint.y + k * getDY(leftBottom, cPoint);

  leftTop.x = cPoint.x + k * getDX(leftTop, cPoint);
  leftTop.y = cPoint.y + k * getDY(leftTop, cPoint);

  rightTop.x = cPoint.x + k * getDX(rightTop, cPoint);
  rightTop.y = cPoint.y + k * getDY(rightTop, cPoint);

  rightBottom.x = cPoint.x + k * getDX(rightBottom, cPoint);
  rightBottom.y = cPoint.y + k * getDY(rightBottom, cPoint);
}

std::istream &operator>>(std::istream &in, Complexquad &complexquad)
{
  if (!(in >> complexquad.leftBottom >> complexquad.leftTop >> complexquad.rightBottom >> complexquad.rightTop)) {
    throw std::overflow_error("Invalid Input Complexquad");
  }
  double x1 = complexquad.leftBottom.x;
  double y1 = complexquad.leftBottom.y;
  double x2 = complexquad.rightTop.x;
  double y2 = complexquad.rightTop.y;
  double x3 = complexquad.rightBottom.x;
  double y3 = complexquad.rightBottom.y;
  double x4 = complexquad.leftTop.x;
  double y4 = complexquad.leftTop.y;

  complexquad.cPoint.x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
                         ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

  complexquad.cPoint.y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
                         ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
  if (complexquad.cPoint.x == -0){
    complexquad.cPoint.x = 0;
  }
//  if (complexquad.cPoint.y == -0){
//    complexquad.cPoint.y = 0;
//  }
  return in;
}

double Complexquad::getDX(PointT fp, PointT sp)
{
  return fabs(fp.x - sp.x);
}

double Complexquad::getDY(PointT fp, PointT sp)
{
  return fabs(fp.y - sp.y);
}

double Complexquad::getDistance(PointT fp, PointT sp)
{
  return sqrt(pow(getDX(fp, sp), 2) + pow(getDY(fp, sp), 2));
}

double Complexquad::getTriangleArea(PointT fp, PointT sp, PointT tp)
{
  double l1 = getDistance(fp, sp);
  double l2 = getDistance(sp, tp);
  double l3 = getDistance(fp, tp);
  double s = (l1 + l2 + l3) / 2;
  return std::sqrt(s * (s - l1) * (s - l2) * (s - l3));
}
