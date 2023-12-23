#include "complex-quad.hpp"
#include <algorithm>

ComplexQuad::ComplexQuad(const point_t& point1, const point_t& point2, const point_t& point3, const point_t& point4)
{
  points_[0] = point1;
  points_[1] = point2;
  points_[2] = point3;
  points_[3] = point4;
}

ComplexQuad* ComplexQuad::clone() const
{
  return new ComplexQuad(*this);
}

float ComplexQuad::getArea() const
{
  Triangle triangle1(points_[0], points_[1], points_[2]);
  Triangle triangle2(points_[2], points_[3], points_[0]);

  return triangle1.getArea() + triangle2.getArea();
}

rectangle_t ComplexQuad::getFrameRect() const
{
  float minX = std::min({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  float maxX = std::max({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  float minY = std::min({ points_[0].y, points_[1].y, points_[2].y, points_[3].y });
  float maxY = std::max({ points_[0].y, points_[1].y, points_[2].y, points_[3].y });

  return { maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 }};
}

void ComplexQuad::move(const point_t& newPos)
{
  float dx = newPos.x - getFrameRect().pos.x;
  float dy = newPos.y - getFrameRect().pos.y;
  move(dx, dy);
}

void ComplexQuad::move(float dx, float dy)
{
  for (point_t& point : points_)
  {
    point.x += dx;
    point.y += dy;
  }
}

void ComplexQuad::scale(float scaleFactor)
{
  point_t center = getFrameRect().pos;
  for (point_t& point : points_)
  {
    point.x = center.x + scaleFactor * (point.x - center.x);
    point.y = center.y + scaleFactor * (point.y - center.y);
  }
}
