#include "complexquad.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace shagieva
{
  Complexquad::Complexquad(const point_t & point1, const point_t & point2,
      const point_t & point3, const point_t & point4)
  {
    points[0] = point1;
    points[1] = point2;
    points[2] = point3;
    points[3] = point4;
  }

  double Complexquad::getArea() const
  {
    point_t center = getCenter();
    return getTriangleArea(points[0], center, points[4]) + getTriangleArea(points[1], center, points[2]);
  }

  rectangle_t Complexquad::getFrameRect() const
  {
    double minX = std::min({ points[0].x, points[1].x, points[2].x, points[3].x });
    double maxX = std::max({ points[0].x, points[1].x, points[2].x, points[3].x });
    double minY = std::min({ points[0].y, points[1].y, points[2].y, points[3].y });
    double maxY = std::max({ points[0].y, points[1].y, points[2].y, points[3].y });
    return { maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2} };
  }

  void Complexquad::move(const double & dx, const double & dy)
  {
    for (int i = 0; i < 4; ++i)
    {
      points[i].x += dx;
      points[i].y += dy;
    }
  }

  void Complexquad::move(const point_t & newCenter)
  {
    point_t center = getCenter();
    double dx = newCenter.x - center.x;
    double dy = newCenter.y - center.y;
    move(dx, dy);
  }

  void Complexquad::scale(const double & scaleFactor)
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
    double a1 = points[0].y - points[2].y;
    double b1 = points[2].x - points[0].x;
    double c1 = points[0].x * points[2].y - points[2].x * points[0].y;

    double a2 = points[1].y - points[3].y;
    double b2 = points[3].x - points[1].x;
    double c2 = points[1].x * points[3].y - points[3].x * points[1].y;

    double determinant = a1 * b2 - a2 * b1;

    return { (b1 * c2 - b2 * c1) / determinant, (a1 * c2 - a2 * c1) / determinant };
  }

  double Complexquad::getLength(const point_t & point1, const point_t & point2) const
  {
    return std::hypot(point2.x - point1.x, point2.y - point1.y);
  }

  double Complexquad::getTriangleArea(const point_t & pointA, const point_t & pointB, const point_t & pointC) const
  {
    double a = getLength(pointA, pointB);
    double b = getLength(pointB, pointC);
    double c = getLength(pointC, pointA);
    double semiPerimeter = (a + b + c) / 2;
    return std::sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
  }
}
