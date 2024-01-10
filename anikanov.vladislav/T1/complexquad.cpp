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
  return getTriangleArea(point1, point4, cPoint) +
         getTriangleArea(point2, point3, cPoint);
}

RectangleT Complexquad::getFrameRect()
{
  float leftMax = std::numeric_limits< float >::max();
  float topMax = std::numeric_limits< float >::min();
  float rightMax = std::numeric_limits< float >::min();
  float bottomMax = std::numeric_limits< float >::max();
  PointT points[] = {point1, point2, point3, point4};
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

  point1.x += dx;
  point1.y += dy;

  point2.x += dx;
  point2.y += dy;

  point3.x += dx;
  point3.y += dy;

  point4.x += dx;
  point4.y += dy;

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
  k--;
  point1.x = cPoint.x + k * getDX(point1, cPoint);
  point1.y = cPoint.y + k * getDY(point1, cPoint);

  point2.x = cPoint.x + k * getDX(point2, cPoint);
  point2.y = cPoint.y + k * getDY(point2, cPoint);

  point3.x = cPoint.x + k * getDX(point3, cPoint);
  point3.y = cPoint.y + k * getDY(point3, cPoint);

  point4.x = cPoint.x + k * getDX(point4, cPoint);
  point4.y = cPoint.y + k * getDY(point4, cPoint);
}

namespace anikanov {
  std::istream &operator>>(std::istream &in, Complexquad &complexquad)
  {
    if (!(in >> complexquad.point1 >> complexquad.point2 >> complexquad.point3 >> complexquad.point4)) {
      throw std::overflow_error("Invalid Input Complexquad");
    }
    float x1 = complexquad.point1.x;
    float y1 = complexquad.point1.y;
    float x2 = complexquad.point2.x;
    float y2 = complexquad.point2.y;
    float x3 = complexquad.point3.x;
    float y3 = complexquad.point3.y;
    float x4 = complexquad.point4.x;
    float y4 = complexquad.point4.y;

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
  point1 = PointT();
  point2 = PointT();
  point4 = PointT();
  point3 = PointT();
}
