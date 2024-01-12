#include "complexquad.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace shagieva;

Complexquad::Complexquad(const point_t point1, const point_t point2,
    const point_t point3, const point_t point4)
{
  points[0] = point1;
  points[1] = point2;
  points[2] = point3;
  points[3] = point4;

  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;

  if ( ((x3 - x1) / (x2 - x3)) == ((y3 - y1) / (y2 - y3))
    || ((x4 - x1) / (x2 - x4)) == ((y4 - y1) / (y2 - y4))
    || ((x1 - x3) / (x4 - x1)) == ((y1 - y3) / (y4 - y1))
    || ((x2 - x3) / (x4 - x2)) == ((y2 - y3) / (y4 - y2)) )
  {
    throw std::invalid_argument("Complexquad does not exist");
  }
}

double Complexquad::getArea() const
{
  point_t center = getCenter();
  return getTriangleArea(points[0], center, points[3]) + getTriangleArea(points[1], center, points[2]);
}

rectangle_t Complexquad::getFrameRect() const
{
  double minX = std::min({ points[0].x, points[1].x, points[2].x, points[3].x });
  double maxX = std::max({ points[0].x, points[1].x, points[2].x, points[3].x });
  double minY = std::min({ points[0].y, points[1].y, points[2].y, points[3].y });
  double maxY = std::max({ points[0].y, points[1].y, points[2].y, points[3].y });
  return { maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2} };
}

void Complexquad::move(const double dx, const double dy)
{
  for (int i = 0; i < 4; ++i)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}

void Complexquad::move(const point_t newCenter)
{
  point_t center = getCenter();
  double dx = newCenter.x - center.x;
  double dy = newCenter.y - center.y;
  move(dx, dy);
}

void Complexquad::scale(const double scaleFactor)
{
  point_t center = getCenter();
  for (int i = 0; i < 4; ++i)
  {
    points[i].x = (points[i].x - center.x) * scaleFactor + center.x;
    points[i].y = (points[i].y - center.y) * scaleFactor + center.y;
  }
}

point_t Complexquad::getCenter() const
{
  double a1 = points[0].y - points[1].y;
  double b1 = points[0].x - points[1].x;
  double c1 = points[0].x * points[1].y - points[1].x * points[0].y;

  double a2 = points[2].y - points[3].y;
  double b2 = points[2].x - points[3].x;
  double c2 = points[2].x * points[3].y - points[3].x * points[2].y;

  double determinant = b1 * a2 - a1 * b2;

  return { (b2 * c1 - b1 * c2) / determinant, (a2 * c1 - a1 * c2) / determinant };
}

double Complexquad::getTriangleArea(const point_t pointA, const point_t pointB, const point_t pointC) const
{
  return std::fabs((pointB.x - pointA.x) * (pointC.y - pointA.y) - (pointC.x - pointA.x) * (pointB.y - pointA.y)) / 2;
}
