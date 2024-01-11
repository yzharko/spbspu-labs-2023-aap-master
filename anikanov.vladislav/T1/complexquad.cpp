#include "complexquad.hpp"
#include <cmath>
#include <iostream>
#include <cmath>
#include <limits>

using namespace anikanov;

point_t Complexquad::getCPoint() const
{
  return cPoint;
}

double Complexquad::getArea() const
{
  return getTriangleArea(leftBottom, leftTop, cPoint) +
         getTriangleArea(rightTop, rightBottom, cPoint);
}

rectangle_t Complexquad::getFrameRect() const
{
  double leftMax = std::numeric_limits< double >::max();
  double topMax = std::numeric_limits< double >::min();
  double rightMax = std::numeric_limits< double >::min();
  double bottomMax = std::numeric_limits< double >::max();
  point_t points[] = {leftTop, leftBottom, rightTop, rightBottom};
  for (auto point: points) {
    leftMax = std::min(leftMax, point.x);
  }
  for (auto point: points) {
    topMax = std::max(topMax, point.y);
  }
  for (auto point: points) {
    rightMax = std::max(rightMax, point.x);
  }
  for (auto point: points) {
    bottomMax = std::min(bottomMax, point.y);
  }
  float width = rightMax - leftMax;
  float height = topMax - bottomMax;
  return rectangle_t(point_t(leftMax + width / 2.0f, bottomMax + height / 2.0f), width, height);
}

void Complexquad::move(const point_t newCPoint)
{
  float dx = getDX(cPoint, newCPoint);
  float dy = getDY(cPoint, newCPoint);
  std::cerr << dx << "\n";

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

void Complexquad::move(const float x, const float y)
{
  point_t newCPoint(x, y);
  move(newCPoint);
}

void Complexquad::scale(const double k, const point_t center)
{
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  point_t *points[] = {&leftBottom, &leftTop, &rightTop, &rightBottom, &cPoint};
  for (auto point: points) {
    (*point).x += (k - 1) * getDX(*point, center);
    (*point).y += (k - 1) * getDY(*point, center);
  }
}

namespace anikanov {
  std::istream &operator>>(std::istream &in, Complexquad &complexquad)
  {
    if (!(in >> complexquad.leftBottom >> complexquad.rightTop >> complexquad.rightBottom >> complexquad.leftTop)) {
      throw std::overflow_error("Invalid Input Complexquad");
    }
    point_t p1 = complexquad.leftBottom;
    point_t p2 = complexquad.rightTop;
    point_t p3 = complexquad.rightBottom;
    point_t p4 = complexquad.leftTop;
    auto st = [&complexquad](point_t &a, point_t &b, point_t &c) {
      return complexquad.getTriangleArea(a, b, c);
    };
    if (!(st(p1, p2, p3) != 0.0f &&
          st(p1, p2, p4) != 0.0f &&
          st(p1, p3, p4) != 0.0f &&
          st(p2, p3, p4) != 0.0f)) {
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
    if (complexquad.cPoint.y == -0) {
      complexquad.cPoint.y = 0;
    }
    return in;
  }
}

float Complexquad::getDistance(point_t fp, point_t sp)
{
  return std::sqrt(std::pow(getDX(fp, sp), 2) + std::pow(getDY(fp, sp), 2));
}

float Complexquad::getTriangleArea(point_t a, point_t b, point_t c) const
{
  point_t ab(b.x - a.x, b.y - a.y);
  point_t ac(c.x - a.x, c.y - a.y);
  return std::sqrt(powf(ab.x * ac.y - ac.x * ab.y, 2)) / 2.0f;
}

Complexquad::Complexquad()
{
  leftBottom = point_t();
  leftTop = point_t();
  rightBottom = point_t();
  rightTop = point_t();
}

void Complexquad::scale(const double k)
{
  (*this).scaleCorrect(k, point_t(0, 0));
}

//COMPLEXQUAD -1.0 -2.0 1.0 2.0 1.0 -1.0 -2.0 2.0
//SCALE 0.0 0.0 2.0

