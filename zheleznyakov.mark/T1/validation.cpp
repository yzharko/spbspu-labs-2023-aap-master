#include "validation.hpp"

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

bool zheleznyakov::checkIsRectangleCoords(double x1, double y1, double x2, double y2)
{
  return x1 < x2 && y1 < y2;
};
