#include "rectangle.hpp"

using namespace redko;

Rectangle::Rectangle(const point_t & firstPoint, const point_t & secondPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint)
{}

double Rectangle::getArea() const
{
  rectangle_t frame = getFrameRect();
  return (frame.height * frame.width);
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = secondPoint_.x - firstPoint_.x;
  double height = secondPoint_.y - firstPoint_.y;
  double x = firstPoint_.x + ((secondPoint_.x - firstPoint_.x) / 2.0);
  double y = firstPoint_.y + ((secondPoint_.y - firstPoint_.y) / 2.0);
  return { width, height, { x, y } };
}

void Rectangle::move(const point_t & dest)
{
  rectangle_t frame = getFrameRect();
  double xDist = dest.x - frame.pos.x;
  double yDist = dest.y - frame.pos.y;
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
}

void Rectangle::move(double xDist, double yDist)
{
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
}

void Rectangle::scale(double coefficient)
{
  rectangle_t frame = getFrameRect();
  firstPoint_.x = frame.pos.x + (firstPoint_.x - frame.pos.x) * coefficient;
  firstPoint_.y = frame.pos.y + (firstPoint_.y - frame.pos.y) * coefficient;
  secondPoint_.x = frame.pos.x + (secondPoint_.x - frame.pos.x) * coefficient;
  secondPoint_.y = frame.pos.y + (secondPoint_.y - frame.pos.y) * coefficient;
}
