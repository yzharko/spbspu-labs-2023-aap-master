#include "parallelogram.hpp"
#include <cmath>

redko::Parallelogram::Parallelogram(redko::point_t firstPoint, redko::point_t secondPoint, redko::point_t thirdPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{}

double redko::Parallelogram::getArea() const
{
  redko::rectangle_t frame = getFrameRect();
  if (firstPoint_.y == secondPoint_.y)
  {
    return (std::abs(firstPoint_.x - secondPoint_.x) * frame.height);
  }
  else
  {
    return (std::abs(secondPoint_.x - thirdPoint_.x) * frame.height);
  }
}

redko::rectangle_t redko::Parallelogram::getFrameRect() const
{
  double width = abs(secondPoint_.x - firstPoint_.x) + abs(secondPoint_.x - thirdPoint_.x);

  double height = 0;
  if (secondPoint_.y == firstPoint_.y)
  {
    height = std::abs(secondPoint_.y - thirdPoint_.y);
  }
  else
  {
    height = std::abs(secondPoint_.y - firstPoint_.y);
  }

  double x = 0;
  if (firstPoint_.x <= secondPoint_.x && firstPoint_.x <= thirdPoint_.x)
  {
    x = firstPoint_.x + (width / 2.0);
  }
  else if (secondPoint_.x <= firstPoint_.x && secondPoint_.x <= thirdPoint_.x)
  {
    x = secondPoint_.x + (width / 2.0);
  }
  else
  {
    x = thirdPoint_.x + (width / 2.0);
  }

  double y = 0;
  if (secondPoint_.y > firstPoint_.y || secondPoint_.y > thirdPoint_.y)
  {
    y = secondPoint_.y - (height / 2.0);
  }
  else
  {
    y = secondPoint_.y + (height / 2.0);
  }

  return { width, height, { x, y } };
}

void redko::Parallelogram::move(redko::point_t dest)
{
  redko::rectangle_t frame = getFrameRect();
  double xDist = dest.x - frame.pos.x;
  double yDist = dest.y - frame.pos.y;
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
  thirdPoint_.x += xDist;
  thirdPoint_.y += yDist;
}

void redko::Parallelogram::move(double xDist, double yDist)
{
  firstPoint_.x += xDist;
  firstPoint_.y += yDist;
  secondPoint_.x += xDist;
  secondPoint_.y += yDist;
  thirdPoint_.x += xDist;
  thirdPoint_.y += yDist;
}

void redko::Parallelogram::scale(double coefficient)
{
  redko::rectangle_t frame = getFrameRect();
  firstPoint_.x = frame.pos.x + (firstPoint_.x - frame.pos.x) * coefficient;
  firstPoint_.y = frame.pos.y + (firstPoint_.y - frame.pos.y) * coefficient;
  secondPoint_.x = frame.pos.x + (secondPoint_.x - frame.pos.x) * coefficient;
  secondPoint_.y = frame.pos.y + (secondPoint_.y - frame.pos.y) * coefficient;
  thirdPoint_.x = frame.pos.x + (thirdPoint_.x - frame.pos.x) * coefficient;
  thirdPoint_.y = frame.pos.y + (thirdPoint_.y - frame.pos.y) * coefficient;
}
