#include "rectangle.hpp"
#include "base-types.hpp"

ankhbayar::Rectangle::Rectangle(point_t bottomLeft, point_t upperRight)
{
  width_ = upperRight.x - bottomLeft.x;
  height_ = upperRight.y - bottomLeft.y;
  double centerX = (bottomLeft.x + upperRight.x) / 2;
  double centerY = (bottomLeft.y + upperRight.y) / 2;
  center_ = {centerY, centerY};
}

double ankhbayar::Rectangle::getArea() const
{
  return width_ * height_;
}

ankhbayar::rectangle_t ankhbayar::Rectangle::getFrameRect() const
{
  return rectangle_t{center_, width_, height_};
}

void ankhbayar::Rectangle::moveTo(double x, double y)
{
  center_ = point_t{x, y};
}

void ankhbayar::Rectangle::moveBy(double x, double y)
{
  center_ = point_t{center_.x + x, center_.y + y};
}

void ankhbayar::Rectangle::scale(double factor)
{
  width_ *= factor;
  height_ *= factor;
}
