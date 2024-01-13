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
    points_[i].x += diffX;
    points_[i].y += diffY;
  }
};

void zheleznyakov::Diamond::move(double x, double y)
{
  for (int i = 0; i <= 2; i++)
  {
    points_[i].x += x;
    points_[i].y += y;
  }
};

void zheleznyakov::Diamond::scale(double k)
{
  if ((points_[0].x == points_[1].y && points_[0].y == points_[2].x) ||
      (points_[0].y == points_[1].x && points_[0].x == points_[2].y))
  {
    points_[1].x *= k;
    points_[1].y *= k;
    points_[2].x *= k;
    points_[2].y *= k;
  }
  else if ((points_[1].x == points_[0].y && points_[1].y == points_[2].x) ||
           (points_[1].y == points_[0].x && points_[1].x == points_[2].y))
  {
    points_[0].x *= k;
    points_[0].y *= k;
    points_[2].x *= k;
    points_[2].y *= k;
  }
  else if ((points_[2].x == points_[0].y && points_[2].y == points_[1].x) ||
           (points_[2].y == points_[0].x && points_[2].x == points_[1].y))
  {
    points_[0].x *= k;
    points_[0].y *= k;
    points_[1].x *= k;
    points_[1].y *= k;
  }
};

bool zheleznyakov::checkIsRighrTriangle(zheleznyakov::point_t p1, zheleznyakov::point_t p2, zheleznyakov::point_t p3)
{
  double x1 = p1.x;
  double y1 = p1.y;
  double x2 = p2.x;
  double y2 = p2.y;
  double x3 = p3.x;
  double y3 = p3.y;
  double len1 = std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2);
  double len2 = std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2);
  double len3 = std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2);
  return (len1 == len2 + len3) || (len2 == len1 + len3) || (len3 == len1 + len2);
}
