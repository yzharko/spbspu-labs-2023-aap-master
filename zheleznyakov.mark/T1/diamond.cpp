#include <cmath>
#include "diamond.hpp"

zheleznyakov::Diamond::Diamond(point_t p1, point_t p2, point_t p3)
{
  points_[0] = p1;
  points_[1] = p2;
  points_[2] = p3;
}

double zheleznyakov::Diamond::getArea()
{
  double x1 = points_[0].x;
  double y1 = points_[0].y;
  double x2 = points_[1].x;
  double y2 = points_[1].y;
  double x3 = points_[2].x;
  double y3 = points_[2].y;
  double len12 = std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2);
  double len13 = std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2);
  double len23 = std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2);
  if (len12 == len13 + len23)
  {
    return ((std::sqrt(len13) * std::sqrt(len23)) / 2) * 4;
  }
  else if (len13 == len12 + len23)
  {
    return ((std::sqrt(len12) * std::sqrt(len23)) / 2) * 4;
  }
  else if (len23 == len12 + len13)
  {
    return ((std::sqrt(len12) * std::sqrt(len13)) / 2) * 4;
  }
  else
  {
    return 0;
  }
};

zheleznyakov::rectangle_t zheleznyakov::Diamond::getFrameRect()
{
  zheleznyakov::rectangle_t rect;
  if (points_[0].x == points_[1].y && points_[0].y == points_[2].x)
  {
    rect.pos = point_t{points_[0].x, points_[0].y};
    rect.width = 2 * (points_[1].x - points_[0].x);
    rect.height = 2 * (points_[2].y - points_[0].y);
  }
  else if (points_[0].y == points_[1].x && points_[0].x == points_[2].y)
  {
    rect.pos = point_t{points_[0].x, points_[0].y};
    rect.width = 2 * (points_[2].x - points_[0].x);
    rect.height = 2 * (points_[1].y - points_[0].y);
  }
  else if (points_[1].x == points_[0].y && points_[1].y == points_[2].x)
  {
    rect.pos = point_t{points_[1].x, points_[1].y};
    rect.width = 2 * (points_[2].x - points_[1].x);
    rect.height = 2 * (points_[0].y - points_[1].y);
  }
  else if (points_[1].y == points_[0].x && points_[1].x == points_[2].y)
  {
    rect.pos = point_t{points_[1].x, points_[1].y};
    rect.width = 2 * (points_[0].x - points_[1].x);
    rect.height = 2 * (points_[2].y - points_[1].y);
  }
  else if (points_[2].x == points_[0].y && points_[2].y == points_[1].x)
  {
    rect.pos = point_t{points_[2].x, points_[2].y};
    rect.width = 2 * (points_[0].y - points_[2].x);
    rect.height = 2 * (points_[1].x - points_[2].y);
  }
  else if (points_[2].y == points_[0].x && points_[2].x == points_[1].y)
  {
    rect.pos = point_t{points_[2].x, points_[2].y};
    rect.width = 2 * (points_[1].y - points_[2].x);
    rect.height = 2 * (points_[0].x - points_[2].y);
  }
  return rect;
};

void zheleznyakov::Diamond::move(zheleznyakov::point_t point)
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

void zheleznyakov::Diamond::move(double x, double y)
{
  for (int i = 0; i <= 2; i++)
  {
    point_t newPoint;
    newPoint.x = points_[i].x + x;
    newPoint.y = points_[i].y + y;
    points_[i] = newPoint;
  }
};

void zheleznyakov::Diamond::scale(double k)
{
  point_t newP1;
  point_t newP2;
  if ((points_[0].x == points_[1].y && points_[0].y == points_[2].x) ||
      (points_[0].y == points_[1].x && points_[0].x == points_[2].y))
  {
    newP1.x = points_[1].x * k;
    newP1.y = points_[1].y * k;
    newP2.x = points_[2].x * k;
    newP2.y = points_[2].y * k;
    points_[1] = newP1;
    points_[2] = newP2;
  }
  else if ((points_[1].x == points_[0].y && points_[1].y == points_[2].x) ||
           (points_[1].y == points_[0].x && points_[1].x == points_[2].y))
  {
    newP1.x = points_[0].x * k;
    newP1.y = points_[0].y * k;
    newP2.x = points_[2].x * k;
    newP2.y = points_[2].y * k;
    points_[0] = newP1;
    points_[2] = newP2;
  }
  else if ((points_[2].x == points_[0].y && points_[2].y == points_[1].x) ||
           (points_[2].y == points_[0].x && points_[2].x == points_[1].y))
  {
    newP1.x = points_[0].x * k;
    newP1.y = points_[0].y * k;
    newP2.x = points_[1].x * k;
    newP2.y = points_[1].y * k;
    points_[0] = newP1;
    points_[1] = newP2;
  }
};
