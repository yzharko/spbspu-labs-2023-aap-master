#include "concave.hpp"
#include <algorithm>

using namespace redko;

Concave::Concave(const point_t & firstPoint, const point_t & secondPoint, const point_t & thirdPoint, const point_t & fourthPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double Concave::getArea() const
{
  double bigTriangle = firstPoint_.x * (secondPoint_.y - thirdPoint_.y) + secondPoint_.x * (thirdPoint_.y - firstPoint_.y);
  bigTriangle = std::abs((bigTriangle + thirdPoint_.x * (firstPoint_.y - secondPoint_.y)) / 2.0);
  double smallTriangle = fourthPoint_.x * (secondPoint_.y - thirdPoint_.y) + secondPoint_.x * (thirdPoint_.y - fourthPoint_.y);
  smallTriangle = std::abs((smallTriangle + thirdPoint_.x * (fourthPoint_.y - secondPoint_.y)) / 2.0);
  return bigTriangle - smallTriangle;
}

rectangle_t Concave::getFrameRect() const
{
  double maxX = std::max(std::max(firstPoint_.x, secondPoint_.x), thirdPoint_.x);
  double minX = std::min(std::min(firstPoint_.x, secondPoint_.x), thirdPoint_.x);
  double width = maxX - minX;
  double maxY = std::max(std::max(firstPoint_.y, secondPoint_.y), thirdPoint_.y);
  double minY = std::min(std::min(firstPoint_.y, secondPoint_.y), thirdPoint_.y);
  double height = maxY - minY;
  double x = minX + width / 2.0;
  double y = minY + height / 2.0;
  return { width, height, { x, y } };
}

void Concave::move(const point_t & dest)
{
  double xDist = dest.x - fourthPoint_.x;
  double yDist = dest.y - fourthPoint_.y;
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
  thirdPoint_.x += xDist;
  thirdPoint_.y += yDist;
  fourthPoint_.x += xDist;
  fourthPoint_.y += yDist;
}

void Concave::move(double xDist, double yDist)
{
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
  thirdPoint_.x += xDist;
  thirdPoint_.y += yDist;
  fourthPoint_.x += xDist;
  fourthPoint_.y += yDist;
}

void Concave::scale(double coefficient)
{
  firstPoint_.x = fourthPoint_.x + (firstPoint_.x - fourthPoint_.x) * coefficient;
  firstPoint_.y = fourthPoint_.y + (firstPoint_.y - fourthPoint_.y) * coefficient;
  secondPoint_.x = fourthPoint_.x + (secondPoint_.x - fourthPoint_.x) * coefficient;
  secondPoint_.y = fourthPoint_.y + (secondPoint_.y - fourthPoint_.y) * coefficient;
  thirdPoint_.x = fourthPoint_.x + (thirdPoint_.x - fourthPoint_.x) * coefficient;
  thirdPoint_.y = fourthPoint_.y + (thirdPoint_.y - fourthPoint_.y) * coefficient;
}
