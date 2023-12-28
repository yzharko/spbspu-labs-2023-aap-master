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

  double Diamond::getArea()
  {
    return (2 * firstDiagonal * secondDiagonal);
  }

  Rectangle_t Diamond::getFrameRect()
  {
    Point_t leftDownPoint;
    Point_t rightUpPoint;
    
  }

  void Diamond::move(Point_t newCenter)
  {

  }

  void Diamond::move(double moveX, double moveY)
  {

  }

  void Diamond::scale(double n)
  {

  }
}
