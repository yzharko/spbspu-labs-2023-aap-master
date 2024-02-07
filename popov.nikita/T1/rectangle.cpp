#include "rectangle.hpp"
#include <cmath>

popov::Rectangle::Rectangle(float x1, float y1, float x2, float y2):
  pointLD{x1,y1},
  pointRU{x2,y2}
{
  float width = abs(pointRU.x - pointLD.x);
  float hight = abs(pointRU.y - pointLD.y);
  point_t pos {((x2 - x1)/2) + x1, ((y2 - y1)/2) + y1};
}
float popov::Rectangle::getArea()
{
  return width * hight;
}
popov::rectangle_t popov::Rectangle::getFrameRect()
{
  return {width, hight, pos};
}
void popov::Rectangle::move(point_t n)
{
  point_t pos = n;
}
void popov::Rectangle::move(float x, float y)
{
  point_t pos {((x2 - x1)/2) + x1 + x, ((y2 - y1)/2) + y1 + y};
}
void popov::Rectangle::scale(float n)
{
  pointLD.x = x1 * n;
  pointLD.y = y1 * n;
  pointRU.x = x2 * n;
  pointRU.y = y2 * n;
}
