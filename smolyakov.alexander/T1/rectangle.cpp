#include "rectangle.hpp"
#include "base-types.hpp"

smolyakov::Rectangle::Rectangle(point_t bottomLeft, point_t upperRight)
{
  width_ = upperRight.x - bottomLeft.x;
  height_ = upperRight.y - bottomLeft.y;
  double centerX = (bottomLeft.x + upperRight.x) / 2;
  double centerY = (bottomLeft.y + upperRight.y) / 2;
  center_ = {centerY, centerY}; 
}

double smolyakov::Rectangle::getArea() const
{
  return width_ * height_;
}

smolyakov::rectangle_t smolyakov::Rectangle::getFrameRect() const
{
  return rectangle_t{center_, width_, height_};
}

void smolyakov::Rectangle::moveTo(point_t shift)
{
  center_ = point_t{shift.x, shift.y};
}

void smolyakov::Rectangle::moveBy(point_t shift)
{
  center_ = point_t{center_.x + shift.x, center_.y + shift.y};
}

void smolyakov::Rectangle::scale(double factor)
{
  width_ *= factor;
  height_ *= factor;
}
