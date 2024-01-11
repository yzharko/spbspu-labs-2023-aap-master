#include "rectangle.hpp"

redko::Rectangle::Rectangle(redko::point_t firstPoint, redko::point_t secondPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint)
{}

double redko::Rectangle::getArea() const
{
  redko::rectangle_t frame = getFrameRect();
  return (frame.height * frame.width);
}

redko::rectangle_t redko::Rectangle::getFrameRect() const
{
  double width = secondPoint_.x - firstPoint_.x;
  double height = secondPoint_.y - firstPoint_.y;
  double x = firstPoint_.x + ((secondPoint_.x - firstPoint_.x) / 2.0);
  double y = firstPoint_.y + ((secondPoint_.y - firstPoint_.y) / 2.0);
  return { width, height, { x, y } };
}

void redko::Rectangle::move(redko::point_t dest)
{
  redko::rectangle_t frame = getFrameRect();
  double xDist = dest.x - frame.pos.x;
  double yDist = dest.y - frame.pos.y;
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
}

void redko::Rectangle::move(double xDist, double yDist)
{
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
}

void redko::Rectangle::scale(double coefficient)
{
  redko::rectangle_t frame = getFrameRect();
  firstPoint_.x = frame.pos.x + (firstPoint_.x - frame.pos.x) * coefficient;
  firstPoint_.y = frame.pos.y + (firstPoint_.y - frame.pos.y) * coefficient;
  secondPoint_.x = frame.pos.x + (secondPoint_.x - frame.pos.x) * coefficient;
  secondPoint_.y = frame.pos.y + (secondPoint_.y - frame.pos.y) * coefficient;
}
