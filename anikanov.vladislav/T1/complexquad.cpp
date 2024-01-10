#include "complexquad.hpp"
#include <iostream>
#include <cmath>
#include <limits>

using namespace anikanov;

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
  float leftMax = std::numeric_limits< float >::max();
  float topMax = std::numeric_limits< float >::min();
  float rightMax = std::numeric_limits< float >::min();
  float bottomMax = std::numeric_limits< float >::max();
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
  float width = rightMax - leftMax;
  float height = topMax - bottomMax;
  return RectangleT(PointT(leftMax + width / 2, bottomMax + height / 2), width, height);
}

void Complexquad::move(PointT newCPoint)
{
  float dx = getDX(cPoint, newCPoint);
  float dy = getDY(cPoint, newCPoint);

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

void Complexquad::move(float x, float y)
{
  PointT newCPoint(x, y);
  move(newCPoint);
}

void Complexquad::scale(float k)
{
  if (k < 0) {
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

namespace anikanov {
  std::istream &operator>>(std::istream &in, Complexquad &complexquad)
  {
    if (!(in >> complexquad.leftBottom >> complexquad.rightTop >> complexquad.leftTop >> complexquad.rightBottom)) {
      throw std::overflow_error("Invalid Input Complexquad");
    }
    float x1 = complexquad.leftBottom.x;
    float y1 = complexquad.leftBottom.y;
    float x2 = complexquad.rightTop.x;
    float y2 = complexquad.rightTop.y;
    float x3 = complexquad.rightBottom.x;
    float y3 = complexquad.rightBottom.y;
    float x4 = complexquad.leftTop.x;
    float y4 = complexquad.leftTop.y;

    complexquad.cPoint.x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
                           ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    complexquad.cPoint.y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
                           ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    if (complexquad.cPoint.x == -0) {
      complexquad.cPoint.x = 0;
    }
    return in;
  }
}

float Complexquad::getDX(PointT fp, PointT sp)
{
  return fp.x - sp.x;
}

float Complexquad::getDY(PointT fp, PointT sp)
{
  return fp.y - sp.y;
}

float Complexquad::getDistance(PointT fp, PointT sp)
{
  return std::sqrt(std::pow(getDX(fp, sp), 2) + std::pow(getDY(fp, sp), 2));
}

float Complexquad::getTriangleArea(PointT fp, PointT sp, PointT tp)
{
  float l1 = getDistance(fp, sp);
  float l2 = getDistance(sp, tp);
  float l3 = getDistance(fp, tp);
  float s = (l1 + l2 + l3) / 2;
  return std::sqrt(s * (s - l1) * (s - l2) * (s - l3));
}

Complexquad::Complexquad()
{
  leftBottom = PointT();
  leftTop = PointT();
  rightBottom = PointT();
  rightTop = PointT();
}
