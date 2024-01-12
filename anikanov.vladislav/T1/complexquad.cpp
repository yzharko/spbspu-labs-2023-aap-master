#include "complexquad.hpp"
#include <cmath>
#include <limits>

using namespace anikanov;

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
  double width = rightMax - leftMax;
  double height = topMax - bottomMax;
  return rectangle_t{point_t{leftMax + width / 2.0f, bottomMax + height / 2.0f}, width, height};
}

void Complexquad::move(const point_t newCPoint)
{
  double dx = getDX(newCPoint, cPoint);
  double dy = getDY(newCPoint, cPoint);

  point_t *points[] = {&leftBottom, &leftTop, &rightTop, &rightBottom};
  for (auto point: points) {
    (*point).x += dx;
    (*point).y += dy;
  }

  cPoint = newCPoint;
}

void Complexquad::move(const double x, const double y)
{
  point_t *points[] = {&leftBottom, &leftTop, &rightTop, &rightBottom, &cPoint};
  for (auto point: points) {
    (*point).x += x;
    (*point).y += y;
  }
};

void Complexquad::scale(const double k)
{
//  (*this).move(point_t(k * getDX(cPoint, center), k * getDY(cPoint, center)));
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  point_t *points[] = {&leftBottom, &leftTop, &rightTop, &rightBottom};
  for (auto point: points) {
    (*point).x = cPoint.x + k * getDX(*point, cPoint);
    (*point).y = cPoint.y + k * getDY(*point, cPoint);
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
    bool p1p2p3S = st(p1, p2, p3) != 0.0f;
    bool p1p2p4S = st(p1, p2, p4) != 0.0f;
    bool p1p3p4S = st(p1, p3, p4) != 0.0f;
    bool p2p3p4S = st(p2, p3, p4) != 0.0f;
    if (!(p1p2p3S && p1p2p4S && p1p3p4S && p2p3p4S)) {
      throw std::overflow_error("Invalid Input Complexquad");
    }
    double lbx = complexquad.leftBottom.x;
    double lby = complexquad.leftBottom.y;
    double rtx = complexquad.rightTop.x;
    double rty = complexquad.rightTop.y;
    double rbx = complexquad.rightBottom.x;
    double rby = complexquad.rightBottom.y;
    double ltx = complexquad.leftTop.x;
    double lty = complexquad.leftTop.y;

    complexquad.cPoint.x = ((lbx * rty - lby * rtx) * (rbx - ltx) - (lbx - rtx) * (rbx * lty - rby * ltx)) /
                           ((lbx - rtx) * (rby - lty) - (lby - rty) * (rbx - ltx));

    complexquad.cPoint.y = ((lbx * rty - lby * rtx) * (rby - lty) - (lby - rty) * (rbx * lty - rby * ltx)) /
                           ((lbx - rtx) * (rby - lty) - (lby - rty) * (rbx - ltx));
    if (complexquad.cPoint.x == -0) {
      complexquad.cPoint.x = 0;
    }
    if (complexquad.cPoint.y == -0) {
      complexquad.cPoint.y = 0;
    }
    return in;
  }
}

double Complexquad::getDistance(point_t fp, point_t sp)
{
  return std::sqrt(std::pow(getDX(fp, sp), 2) + std::pow(getDY(fp, sp), 2));
}

double Complexquad::getTriangleArea(point_t a, point_t b, point_t c) const
{
  point_t ab{b.x - a.x, b.y - a.y};
  point_t ac{c.x - a.x, c.y - a.y};
  return std::sqrt(pow(ab.x * ac.y - ac.x * ab.y, 2)) / 2.;
}

double Complexquad::getDX(point_t fp, point_t sp)
{
  return fp.x - sp.x;
};

double Complexquad::getDY(point_t fp, point_t sp)
{
  return fp.y - sp.y;
}

point_t Complexquad::getCPoint()
{
  return cPoint;
}

//COMPLEXQUAD -1.0 -2.0 1.0 2.0 1.0 -1.0 -2.0 2.0
//SCALE 0.0 0.0 2.0

