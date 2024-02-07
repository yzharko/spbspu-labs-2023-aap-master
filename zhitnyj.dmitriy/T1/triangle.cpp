#include "triangle.hpp"
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c) : a_(a), b_(b), c_(c)
{
}

Triangle* Triangle::clone() const
{
  return new Triangle(*this);
}

float Triangle::getArea() const
{
  float sideA = std::sqrt(std::pow(b_.x - a_.x, 2) + std::pow(b_.y - a_.y, 2));
  float sideB = std::sqrt(std::pow(c_.x - b_.x, 2) + std::pow(c_.y - b_.y, 2));
  float sideC = std::sqrt(std::pow(a_.x - c_.x, 2) + std::pow(a_.y - c_.y, 2));
  float s = (sideA + sideB + sideC) / 2;
  return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

rectangle_t Triangle::getFrameRect() const
{
  float minX = std::min({ a_.x, b_.x, c_.x });
  float maxX = std::max({ a_.x, b_.x, c_.x });
  float minY = std::min({ a_.y, b_.y, c_.y });
  float maxY = std::max({ a_.y, b_.y, c_.y });
  return { maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 }};
}

void Triangle::move(const point_t& newPos)
{
  float dx = newPos.x - getFrameRect().pos.x;
  float dy = newPos.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Triangle::move(float dx, float dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void Triangle::scale(float scaleFactor)
{
  point_t center = getFrameRect().pos;
  a_ = { center.x + scaleFactor * (a_.x - center.x), center.y + scaleFactor * (a_.y - center.y) };
  b_ = { center.x + scaleFactor * (b_.x - center.x), center.y + scaleFactor * (b_.y - center.y) };
  c_ = { center.x + scaleFactor * (c_.x - center.x), center.y + scaleFactor * (c_.y - center.y) };
}
