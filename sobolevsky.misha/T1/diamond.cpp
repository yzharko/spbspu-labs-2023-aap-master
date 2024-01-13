#include "diamond.hpp"
#include <cmath>

namespace sobolevsky
{
  Diamond::Diamond(Point_t upPoint2, Point_t rightPoint2, Point_t centerPoint2)
  {
    upPoint = upPoint2;
    rightPoint = rightPoint2;
    centerPoint = centerPoint2;
    firstDiagonal = std::abs(upPoint2.y - centerPoint2.y);
    secondDiagonal = std::abs(rightPoint2.y - centerPoint2.y);
  }

  double Diamond::getArea() const
  {
    return (2 * firstDiagonal * secondDiagonal);
  }

  Rectangle_t Diamond::getFrameRect() const
  {
    Rectangle_t test;
    test.pos = centerPoint;
    test.height = firstDiagonal * 2;
    test.width = secondDiagonal * 2;
    return test;
  }

  void Diamond::move(Point_t newCenter)
  {
    double dx = centerPoint.x - newCenter.x;
    double dy = centerPoint.y - newCenter.y;
    centerPoint = newCenter;
    rightPoint.x += dx;
    upPoint.x += dx;
    rightPoint.y += dy;
    upPoint.y += dy;
  }

  void Diamond::move(double moveX, double moveY)
  {
    centerPoint.x += moveX;
    centerPoint.y += moveY;
    rightPoint.x += moveX;
    upPoint.x += moveX;
    rightPoint.y += moveY;
    upPoint.y += moveY;
  }

  void Diamond::scale(double n)
  {
    rightPoint.x *= n;
    upPoint.x *= n;
    rightPoint.y *= n;
    upPoint.y *= n;
    firstDiagonal *= n;
    secondDiagonal *= n;
  }
}
