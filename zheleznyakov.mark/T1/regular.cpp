#include "regular.hpp"
#include "length.hpp"

zheleznyakov::Regular::Regular(point_t p1, point_t p2, point_t p3)
{
  points_[0] = p1;
  points_[1] = p2;
  points_[2] = p3;
}

double zheleznyakov::Regular::getArea()
{
  double s = (points_[0].x * (points_[1].y - points_[2].y) +
              points_[1].x * (points_[2].y - points_[0].y) +
              points_[2].x * (points_[0].y - points_[1].y)) /
             2;
  return std::sqrt(s * (s - points_[0].x) * (s - points_[1].x) * (s - points_[2].x));
}

zheleznyakov::rectangle_t zheleznyakov::Regular::getFrameRect()
{
  zheleznyakov::rectangle_t rect;
  double xMin = std::min(std::min(points_[0].x, points_[1].x), points_[2].x);
  double xMax = std::max(std::min(points_[0].x, points_[1].x), points_[2].x);
  double yMin = std::min(std::min(points_[0].y, points_[1].y), points_[2].y);
  double yMax = std::max(std::min(points_[0].y, points_[1].y), points_[2].y);
  rect.width = std::abs(xMax - xMin);
  rect.width = std::abs(yMax - yMin);
  rect.pos.x = xMin;
  rect.pos.y = yMin;
  return rect;
};

void zheleznyakov::Regular::move(zheleznyakov::point_t point)
{
  for (int i = 0; i <= 2; i++)
  {
    double diffX = point.x - points_[i].x;
    double diffY = point.y - points_[i].y;
    point_t newPoint;
    newPoint.x = points_[i].x + diffX;
    newPoint.y = points_[i].y + diffY;
    points_[i] = newPoint;
  }
};

void zheleznyakov::Regular::move(double x, double y)
{
  for (int i = 0; i <= 2; i++)
  {
    point_t newPoint;
    newPoint.x = points_[i].x + x;
    newPoint.y = points_[i].y + y;
    points_[i] = newPoint;
  }
};

void zheleznyakov::Regular::scale(double k)
{
  point_t newP1;
  point_t newP2;
  newP1.x = points_[1].x * k;
  newP1.y = points_[1].y * k;
  newP2.x = points_[2].x * k;
  newP2.y = points_[2].y * k;
  points_[1] = newP1;
  points_[2] = newP2;
};
